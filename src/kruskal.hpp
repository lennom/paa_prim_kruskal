#ifndef __KRUSKAL__HPP__
#define __KRUSKAL__HPP__

#include "graph.hpp"
#include "mst.hpp"

//n -> n�mero de nodos
//m -> n�mero de arestas
void kruskal(Graph G, MST &mst)
{
  /*Sort edges weight (c1 <= c2 <= ... <= cn)

  MST T(false); <- inicializa uma MST nula

  for each ( u E V ) make_set(u);

  for(int i = 0 ; i < m ; i++)
  {
    (u,v) = ei;
    if(u e v estiverem em set's diferentes)
    {
      T.add_edge(ei);
      Union(find_set(u), find_set(v));
    }
  }*/
}

#endif