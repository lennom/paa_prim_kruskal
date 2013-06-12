#ifndef __PRIM__HPP__
#define __PRIM__HPP__

#include "graph.hpp"
#include "mst.hpp"

#include "heap.hpp"
#include "vertex.hpp"
#include <ctime>
#include <queue>

void prim_vertex_vec(Graph G, MST &T, int vi = 0)
{
  Heap_min_Vertex heap(G.V);
  std::vector<int> S;
  for(int i = 0 ; i < G.V ; i++)
  {
    S.push_back(0);
  }
  heap.decrease_key(vi,0);
  Vertex v;
  S[vi] = 1;
  while(!heap.is_empty())
  {
    v = heap.pop();
    S[v.id] = 1;
    if(v.prev != -1)
    {
      T.add_edge(v.prev,v.id,v.weight);
    }
    for(int i = 0 ; i < (int)G.edges[v.id].size(); i++)
    {
      if(S[v.id] != S[G.edges[v.id][i]]){
        if(heap.get_cost(G.edges[v.id][i]) > G.weights[v.id][i])
        {
          heap.set_previous(G.edges[v.id][i], v.id);
          heap.decrease_key(G.edges[v.id][i], G.weights[v.id][i]);
        }
      }
    }
  }
  //printf("Max HeapfyDown (Heap Vector): %d\n", heap.heapfyDown_Max);
  //printf("HeapfyDowns (Heap Vector): %d\n", heap.heapfyDowns);
  //printf("Max HeapfyUp (Heap Vector): %d\n", heap.heapfyUp_Max);
  //printf("HeapfyUps (Heap Vector): %d\n", heap.heapfyUps);
}

void prim_edges(Graph G, MST &mst, int vi = 0)
{
    //Initialize the empty vector with S explored nodes
  //0 - not explored | 1 - explored
  std::vector<int> S;
  for(int i = 0 ; i < G.V ; i++) S.push_back(0);
  Heap_min_Edge heap;

  //add the initial node
  std::deque<int> Q;
  Q.push_back(vi);
  S[vi] = 1;

  int u;
  while (!Q.empty())
  {
    u = Q.front();
    Q.pop_front();

    S[u] = 1;
    //adiciona as arestas que fazem parte do vértices corrente
    for(int i = 0 ; i < (int)G.edges[u].size() ; i++)
    {
      //aresta com extremidade não visitada ainda
      if(S[G.edges[u][i]] == 0)
      {
        heap.insert(Edge(u,G.edges[u][i],G.weights[u][i]));
      }
    }

    while((int)heap.size() > 0)
    {
      Edge ex = heap.deletemin();
      if(S[ex.v2] == 0)
      {
        //printf("vertex %d added to queue\n", ex.v2);
        Q.push_back(ex.v2);
        S[ex.v2] = 1;
        mst.add_edge(ex.v1,ex.v2,ex.weight);
        break;
      }
    }
  }

  //printf("Max HeapfyDown (Heap Min Vector): %d\n", heap.heapfyDown_Max);
  //printf("HeapfyDowns (Heap Min Vector): %d\n", heap.heapfyDowns);
  //printf("Max HeapfyUp (Heap Min Vector): %d\n", heap.heapfyUp_Max);
  //printf("HeapfyUps (Heap Min Vector): %d\n", heap.heapfyUps);
}

void prim_edges_pqueue(Graph G, MST &mst, int vi = 0)
{
  //Initialize the empty vector with S explored nodes
  //0 - not explored | 1 - explored
  std::vector<int> S;
  for(int i = 0 ; i < G.V ; i++) S.push_back(0);
  std::priority_queue<Edge, std::vector<Edge>, Edge_compare> e;

  //add the initial node
  std::deque<int> Q;
  Q.push_back(vi);
  S[vi] = 1;

  int u;
  while (!Q.empty())
  {
    u = Q.front();
    Q.pop_front();
    
    S[u] = 1;
    //adiciona as arestas que fazem parte do vértices corrente
    for(int i = 0 ; i < (int)G.edges[u].size() ; i++)
    {
      //aresta com extremidade não visitada ainda
      if(S[G.edges[u][i]] == 0)
      {
        e.push(Edge(u,G.edges[u][i],G.weights[u][i]));
      }
    }

    while((int)e.size() > 0)
    {
      Edge ex = e.top();
      e.pop();
      if(S[ex.v2] == 0)
      {
        Q.push_back(ex.v2);
        S[ex.v2] = 1;
        mst.add_edge(ex.v1,ex.v2,ex.weight);
        break;
      }
    }
  }
}

#endif