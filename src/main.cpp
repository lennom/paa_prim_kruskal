/*
  - Leonardo Benevides
  - Leonardo Quatrin Campagnolo

  1. Algoritmo de Kruskal utilizando o heap sort e a estrutura union-ﬁnd (utilizando as heurísticas de union by rank e path compression).
  2. Algoritmo de Kruskal utilizando o counting sort e a estrutura union-ﬁnd (utilizando as heurísticas de union by rank e path compression).
  3. Algoritmo de Prim utilizando a ﬁla de prioridade sobre as arestas.
  4. Algoritmo de Prim utilizando a ﬁla de prioridade com a operação change-key sobre os vértices.

  . heapsort                           [working]
  . counting sort                      [working]
  . union by rank                      [----]
  . paht compression                   [----]
  . fila de prioridades                [done]
  . fila de prioridades com change-key [----]
  . kruskal                            [----]
  . prim                               [done]

  kruskal_hs_ubr()                     [working]
  kruskal_hs_pc()                      [----]
  kruskal_cs_ubr()                     [----]
  kruskal_cs_pc()                      [----]
  prim_edges()                         [done]
  prim_vertex()                        [----]

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

#include "union_by_rank.hpp"
#include "path_compression.hpp"

#include <iostream>
#include <queue>

#include <stdio.h>
 
void prim_edges();

int main()
{
  //run_kruskal_hs_ubr();
  //run_kruskal_hs_pc();
  //run_kruskal_cs_ubr();
  //run_kruskal_cs_pc();
  run_prim_edges();
  //run_prim_vertex();

  return 0;
}

void run_prim_edges()
{
  int n;
  std::cin >> n;
  int v1,v2,risco;
  Graph g(n);
  while(std::cin >> v1 >> v2 >> risco)
  {
    g.add_edge(v1-1,v2-1,risco);
  }
  std::vector<int> cost;
  MST mst(n);
  prim_edges(g,cost,mst);
  
  /*for(int i = 0 ; i < (int)cost.size(); i++)
  {
    std::cout << i+1 << ": " << cost[i] << std::endl;
  }*/

  printf("MST edges result:\n");
  for(int i = 0 ; i < (int)mst.edges.size() ; i++)
  {
    printf("%d %d %d\n", mst.edges[i].v1+1, mst.edges[i].v2+1, mst.edges[i].weight);
  }
}