#ifndef __KRUSKAL__HPP__
#define __KRUSKAL__HPP__

#include "graph.hpp"
#include "mst.hpp"

//n -> número de nodos
//m -> número de arestas
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
  
  /*
  Kruskal(G, c) {
Sort edges weights so that c1 c2 ... cm.
T 
foreach (u V) make a set containing singleton u
for i = 1 to m
(u,v) = ei
if (u and v are in different sets) {
T T {ei}
merge the sets containing u and v
}
return T
}
  */
}

#endif