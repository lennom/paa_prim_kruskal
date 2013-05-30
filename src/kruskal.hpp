/*Kruskal's algorithm:
	. Consider edges in ascending order of weight
	. Case 1: If adding and edge e to T creates a cycle, discard e
	. Case 2: Otherwise, insert e = (u, v) into T

  Bad Implementation:
  . Sorting the edges
  . Testing the existence of a cycle whyle considering edge e: O(n) via a DFS(BFS). Nota that a tree has at most n edges.
  . For all edges O(m*n)
  . Total complexity O(mlgn)+O(mn) = O(mn)

  Good implementation: use the union-find data structure
  . Build set T of edges in the MST
  . Maintain set for each connected component
  . O(mlgn) for sorting and O(m &(m,n)) for union-find.

*/
#ifndef __KRUSKAL__HPP__
#define __KRUSKAL__HPP__

#include <vector>

#include "graph.hpp"
#include "mst.hpp"
#include "heapsort.hpp"
#include "tree_node.hpp"

void kruskal_hs(Graph G, MST &T)
{
  std::vector<Edge> edges;
  for(int i = 0 ; i < G.V ; i++)
  {
    for(int j = 0 ; j < (int)G.edges[i].size() ; j++)
    {
      edges.push_back(Edge(i, G.edges[i][j],G.weights[i][j]));
    }
  }
  //tem que trocar a função de compare (pesquisar como)
  heapsortEdges(edges);

  std::vector<Tree_node<int>*> components(G.V);
  for(int i = 0 ; i < G.V ; i++)
  {
    components[i] = new Tree_node<int>();
    components[i]->Make_Set(i);
  }
  
  int m = edges.size();
  for(int i = 0 ; i < m ; i++)
  {
    int u = edges[i].v1;
    int v = edges[i].v2;
    //se estiverem em componentes diferentes...
    if(components[u]->Find_Set() != components[v]->Find_Set())
    {
      T.add_edge(edges[i].v1,edges[i].v2,edges[i].weight);
      components[u]->Union(components[u], components[v]);
    }
  }
}
 
void kruskal_cs(Graph G, MST &T)
{
  std::vector<Edge> edges;
  int w_max = 0;
  for(int i = 0 ; i < G.V ; i++)
  {
    for(int j = 0 ; j < (int)G.edges[i].size() ; j++)
    {
      w_max = std::max(w_max, G.weights[i][j]);
      edges.push_back(Edge(i, G.edges[i][j],G.weights[i][j]));
    }
  }
  //tem que trocar a função de compare (pesquisar como)
  std::vector<Edge> edges_sorted;
  CountingSortEdges(edges, edges_sorted, w_max);

  std::vector<Tree_node<int>*> components(G.V);
  for(int i = 0 ; i < G.V ; i++)
  {
    components[i] = new Tree_node<int>();
    components[i]->Make_Set(i);
  }

  
  int m = edges_sorted.size();
  for(int i = 0 ; i < m ; i++)
  {
    int u = edges_sorted[i].v1;
    int v = edges_sorted[i].v2;
    //se estiverem em componentes diferentes...
    if(components[u]->Find_Set() != components[v]->Find_Set())
    {
      T.add_edge(edges_sorted[i].v1,edges_sorted[i].v2,edges_sorted[i].weight);
      components[u]->Union(components[u], components[v]);
    }
  }
}

#endif