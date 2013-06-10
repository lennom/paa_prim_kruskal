/*
Prim Algorithm:
- Initialize S = any node.
- Apply cut property to S.
- Add min cost edge that crosses S to T, and add one new explored node u to S.

Bad Implementation:
- Maintain set of explored nodes S.
- Find the lightest edge that crosses S in O(m) time
- Total complexity O(m.n)

Good Implementation:
- Use a priority queue.
- Maintain set of explored nodes S.
- For each unexplored node v, maintain attachment cost a[v] = cost of cheapest edge v to a node in S.
- O(n2) with an array; O(m log n) with a binary heap
*/


#ifndef __PRIM__HPP__
#define __PRIM__HPP__

#include "graph.hpp"
#include "mst.hpp"

#include "heap.hpp"
#include "vertex.hpp"
#include <ctime>
#include <queue>

//O(mlgn)
void prim_vertex_vec(Graph G, MST &T, int vi = 0)
{
  std::clock_t t = std::clock();
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

  printf("Max HeapfyDown (Heap Vector): %d\n", heap.heapfyDown_Max);
  printf("HeapfyDowns (Heap Vector): %d\n", heap.heapfyDowns);
  printf("Max HeapfyUp (Heap Vector): %d\n", heap.heapfyUp_Max);
  printf("HeapfyUps (Heap Vector): %d\n", heap.heapfyUps);
 
  t = std::clock() - t;
  printf("Time seconds (Heap Vector): %f\n", ((float)t)/CLOCKS_PER_SEC);
}

//O(mlgn)
void prim_vertex_pointer(Graph G, MST &T, int vi = 0)
{
  std::clock_t t = std::clock();
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
  t = std::clock() - t;
  printf("Time seconds (Heap Vector): %f\n", ((float)t)/CLOCKS_PER_SEC);
}


//Number of iterations = O(n), where n is number of vertices
//Picking e is O(m) where m is the number of edges
//Priority queue: O(mlgm), m edges and n vertices
void prim_edges(Graph G, MST &mst, int vi = 0)
{
    //Initialize the empty vector with S explored nodes
  //0 - not explored | 1 - explored
  std::vector<int> S;
  for(int i = 0 ; i < G.V ; i++) S.push_back(0);
  Heap_min_Edge heap;

  //init time
  std::clock_t t = std::clock();

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

  printf("Max HeapfyDown (Heap Min Vector): %d\n", heap.heapfyDown_Max);
  printf("HeapfyDowns (Heap Min Vector): %d\n", heap.heapfyDowns);
  printf("Max HeapfyUp (Heap Min Vector): %d\n", heap.heapfyUp_Max);
  printf("HeapfyUps (Heap Min Vector): %d\n", heap.heapfyUps);

  t = std::clock() - t;
  printf("Time seconds (Heap Min Vector): %f\n", ((float)t)/CLOCKS_PER_SEC);
}

//Number of iterations = O(n), where n is number of vertices
//Picking e is O(m) where m is the number of edges
//Priority queue: O(mlgm), m edges and n vertices
void prim_edges_pqueue(Graph G, MST &mst, int vi = 0)
{
  //Initialize the empty vector with S explored nodes
  //0 - not explored | 1 - explored
  std::vector<int> S;
  for(int i = 0 ; i < G.V ; i++) S.push_back(0);
  std::priority_queue<Edge, std::vector<Edge>, Edge_compare> e;

  //init time
  std::clock_t t = std::clock();

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
        //printf("vertex %d added to queue\n", ex.v2);
        Q.push_back(ex.v2);
        S[ex.v2] = 1;
        mst.add_edge(ex.v1,ex.v2,ex.weight);
        break;
      }
    }
  }
  t = std::clock() - t;
  printf("Time seconds (Priority Queue): %f\n", ((float)t)/CLOCKS_PER_SEC);
}

#endif