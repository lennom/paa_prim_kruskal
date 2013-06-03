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

#include "pq_changekey.hpp"

#include <queue>

//O(n) extractMin operations
//O(m) changeKey operations
void prim_vertex(Graph G, MST &T, int vi = 0)
{
  std::vector<Edge> edges;
  for(int i = 0 ; i < G.V ; i++)
  {
    for(int j = 0 ; j < (int)G.edges[i].size() ; j++)
    {
      edges.push_back(Edge(i, G.edges[i][j],G.weights[i][j]));
    }
  }
  std::vector<int> S;
  PQueue_CKey<int> a;
  std::vector<int> e;
  for(int i = 0 ; i < G.V ; i++)
  {
    S.push_back(0);
    a.data.push_back(std::numeric_limits<int>::max());
    e.push_back(-1);
  }
  S[vi] = 1;

  //O(n + 2m)
  for(int v = 0 ; v < G.V ; v++)
  {
    if(S[v] == 0)
    {
      for(int j = 0 ; j < (int)G.edges[v].size() ; j++)
      {
        if(S[G.edges[v][j]] == 1)
        {
          if(a.data[v] > G.weights[v][j])
          {
            a.data[v] = G.weights[v][j];
            e[v] = j;
          }
        }
      }
    }
  }
  
  while(false) //S =/= V
  {
    int v = a.extractMin();
    
    T.add_edge(v, e[v], a.data[v]);

    S[v] = 1;

    //O(m) changeKey operations
    //changeKey Operations
    //atualiza arrays 'a' e 'e'
  }
}

//Number of iterations = O(n), where n is number of vertices
//Picking e is O(m) where m is the number of edges
//Priority queue: O(mlgn), m edges and n vertices
void prim_edges(Graph G, std::vector<int> &a, MST &mst, int vi = 0)
{
  //init the costs of each node at the graph
  a.clear();
  for(int i = 0 ; i < G.V ; i++) a.push_back(std::numeric_limits<int>::max());

  //add the initial node
  std::deque<int> Q;
  Q.push_back(vi);
  
  //Initialize the empty vector with S explored nodes
  //0 - not explored | 1 - explored
  std::vector<int> S;
  for(int i = 0 ; i < G.V ; i++) S.push_back(0);
  
  std::priority_queue<Edge, std::vector<Edge>, Edge_compare> e;
  a[vi] = 0;
    
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
        mst.add_edge(ex.v1,ex.v2,ex.weight);
        a[ex.v2] = ex.weight;
        break;
      }
    }
  }
}

#endif