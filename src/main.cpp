/*
  - Leonardo Benevides
  - Leonardo Quatrin Campagnolo

  1. Algoritmo de Kruskal utilizando o heap sort e a estrutura union-ﬁnd (utilizando as heurísticas de union by rank e path compression).
  2. Algoritmo de Kruskal utilizando o counting sort e a estrutura union-ﬁnd (utilizando as heurísticas de union by rank e path compression).
  3. Algoritmo de Prim utilizando a ﬁla de prioridade sobre as arestas.
  4. Algoritmo de Prim utilizando a ﬁla de prioridade com a operação change-key sobre os vértices.

  . heapsort                           [done]
  . counting sort                      [done]
  . union by rank & path compression   [working]
  . fila de prioridades                [done]
  . fila de prioridades com change-key [----]
  . kruskal                            [done]
  . prim                               [done]

  . kruskal                            [done]
  . prim                               [done]
 
  Input:
  [número de vértices]
  [aresta 1, vértice 1] [aresta 1, vértice 2] [risco aresta 1]
  [aresta 2, vértice 1] [aresta 2, vértice 2] [risco aresta 2]
  ...
  [aresta n-1, vértice 1] [aresta n-1, vértice 2] [risco aresta n-1]
  [aresta n  , vértice 1] [aresta n  , vértice 2] [risco aresta n  ]

  Relatório
  . Decisões de implementação que foram importantes no desenvolvimento do trabalho;
  . O ambiente computacional utilizado;
  . Resultados dos experimentos (tabelas/risco total das árvores);
  . Uma discussão comparando os resultados obtidos pelos diferentes algoritmos implementados e confrontando os resultados encontrados com aqueles previstos pela teoria.
*/

#include "counting_sort.hpp"
#include "heapsort.hpp"
#include "priority_queue.hpp"

#include "graph.hpp"
#include "mst.hpp"

#include "kruskal.hpp"
#include "prim.hpp"

#include "tree_node.hpp"

#include "heap.hpp"

#include <iostream>
#include <queue>

#include <stdio.h>

void run_kruskal_hs(Graph g, int n);
void run_kruskal_cs(Graph g, int n);
void run_prim_edges(Graph g, int n);
void run_prim_vertex(Graph g, int n);

int main()
{
  int n;
  std::cin >> n;
  int v1,v2,risco;
  Graph g(n);
  while(std::cin >> v1 >> v2 >> risco)
  {
    g.add_edge(v1-1,v2-1,risco);
  }

  run_kruskal_hs(g, n);
  run_kruskal_cs(g, n);
  run_prim_edges(g, n);
  run_prim_vertex(g, n);
  
  return 0;
}

void run_kruskal_hs(Graph g, int n)
{
  printf("Running Kruskal Algorithm\n");
  printf("Sort method: Heapsort\n");

  MST mst(n);

  kruskal_hs(g,mst);
  
  printf("Kruskal Heapsort Algorithm MST edges result:\n");
  for(int i = 0 ; i < (int)mst.edges.size() ; i++)
  {
    printf("%d %d %d\n", mst.edges[i].v1+1, mst.edges[i].v2+1, mst.edges[i].weight);
  }
}

void run_kruskal_cs(Graph g, int n)
{
  printf("Running Kruskal Algorithm\n");
  printf("Sort method: Counting Sort\n");

  MST mst(n);

  kruskal_cs(g,mst);
  
  printf("Kruskal Counting Sort Algorithm MST edges result:\n");
  for(int i = 0 ; i < (int)mst.edges.size() ; i++)
  {
    printf("%d %d %d\n", mst.edges[i].v1+1, mst.edges[i].v2+1, mst.edges[i].weight);
  }
}

void run_prim_edges(Graph g, int n)
{
  printf("Running Prim Algorithm\n");
  printf("Struct: Priority Queue on Edges\n");
  std::vector<int> cost;
  MST mst(n);
  prim_edges(g,cost,mst);
  
  /*for(int i = 0 ; i < (int)cost.size(); i++)
  {
    std::cout << i+1 << ": " << cost[i] << std::endl;
  }*/

  printf("Prim Edges Algorithm MST edges result:\n");
  for(int i = 0 ; i < (int)mst.edges.size() ; i++)
  {
    printf("%d %d %d\n", mst.edges[i].v1+1, mst.edges[i].v2+1, mst.edges[i].weight);
  }
}

void run_prim_vertex(Graph g, int n)
{
  printf("Running Prim Algorithm\n");
  printf("Struct: Priority Queue on Vertex with Change-Key\n");

 MST mst(n);
  prim_vertex(g,mst);
  
  /*for(int i = 0 ; i < (int)cost.size(); i++)
  {
    std::cout << i+1 << ": " << cost[i] << std::endl;
  }*/

  printf("Prim Vertex Algorithm MST edges result:\n");
  for(int i = 0 ; i < (int)mst.edges.size() ; i++)
  {
    printf("%d %d %d\n", mst.edges[i].v1+1, mst.edges[i].v2+1, mst.edges[i].weight);
  }
}