/*
  - Leonardo Benevides
  - Leonardo Quatrin Campagnolo

  1. Algoritmo de Kruskal utilizando o heap sort e a estrutura union-ﬁnd (utilizando as heurísticas de union by rank e path compression).
  2. Algoritmo de Kruskal utilizando o counting sort e a estrutura union-ﬁnd (utilizando as heurísticas de union by rank e path compression).
  3. Algoritmo de Prim utilizando a ﬁla de prioridade sobre as arestas.
  4. Algoritmo de Prim utilizando a ﬁla de prioridade com a operação change-key sobre os vértices.

  . heapsort                           [done]
  . counting sort                      [done]
  . union by rank & path compression   [done]
  . fila de prioridades                [done]
  . fila de prioridades com change-key [done]
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
#include <ctime>

#include <stdio.h>

void run_kruskal_hs(Graph g, int n, std::vector<Edge> edges);
void run_kruskal_cs(Graph g, int n, std::vector<Edge> edges);
void run_prim_edges(Graph g, int n, std::vector<Edge> edges);
void run_prim_vertex(Graph g, int n, std::vector<Edge> edges);

int main()
{
  /*std::vector<int> fq;
  for(int i = 1 ; i < 1000000 ; i++)
  {
    for(int j = 0 ; j < i ; j++)
    {
      fq.push_back(rand() % 1000);
    }
    std::clock_t t = std::clock();
    heapsort(fq);
    t = std::clock() - t;
    printf("%f\n",((float)t)/CLOCKS_PER_SEC);
    fq.clear();
  }*/


 /* int soma = 0;
  int n;
  int vezes = 0;
  while(std::cin >> n)
  {
    vezes += 1;
    soma += n;
  }
  printf("vezes %d\n", vezes);
  printf("%Lf\n", (long double)soma/(long double)vezes);*/

  int n;
  std::cin >> n;
  int v1,v2,risco;
  Graph g(n);
  std::vector<Edge> edges;
  while(std::cin >> v1 >> v2 >> risco)
  {
    g.add_edge(v1-1,v2-1,risco);
    edges.push_back(Edge(v1-1,v2-1,risco));
  }

  run_kruskal_hs(g, n,edges);
  printf("\n");
  run_kruskal_cs(g, n,edges);
  printf("\n");
  run_prim_edges(g, n,edges);
  printf("\n");
  run_prim_vertex(g, n,edges);
  
  return 0;
}

void run_kruskal_hs(Graph g, int n, std::vector<Edge> edges)
{
  //printf("Running Kruskal Algorithm\n");
  //printf("Sort method: Heapsort\n");

  MST mst(n);
  kruskal_hs(g,mst,edges);

  int risco_total = 0;
  for(int i = 0 ; i < (int)mst.edges.size() ; i++)
  {
    risco_total += mst.edges[i].weight;
    //printf("%d %d %d\n", mst.edges[i].v1+1, mst.edges[i].v2+1, mst.edges[i].weight);
  }
  //printf("Risco total: %d\n", risco_total);
  //printf("Risco medio: %Lf\n", (long double)risco_total/(long double)g.edges.size());
}

void run_kruskal_cs(Graph g, int n, std::vector<Edge> edges)
{
  printf("Running Kruskal Algorithm\n");
  printf("Sort method: Counting Sort\n");

  MST mst(n);

  kruskal_cs(g,mst,edges);
  
  int risco_total = 0;
  for(int i = 0 ; i < (int)mst.edges.size() ; i++)
  {
    risco_total += mst.edges[i].weight;
    //printf("%d %d %d\n", mst.edges[i].v1+1, mst.edges[i].v2+1, mst.edges[i].weight);
  }
  printf("Risco total: %d\n", risco_total);
  printf("Risco medio: %Lf\n", (long double)risco_total/(long double)g.edges.size());
  
}

void run_prim_edges(Graph g, int n, std::vector<Edge> edges)
{
  printf("Running Prim Algorithm\n");
  printf("Struct: Priority Queue on Edges\n");
  std::vector<int> cost;
  MST mst(n);

  std::clock_t t = std::clock();
  prim_edges(g,cost,mst);
  t = std::clock() - t;

  /*for(int i = 0 ; i < (int)cost.size(); i++)
  {
    std::cout << i+1 << ": " << cost[i] << std::endl;
  }*/

  printf("Time seconds: %f\n", ((float)t)/CLOCKS_PER_SEC);
  int risco_total = 0;
  for(int i = 0 ; i < (int)mst.edges.size() ; i++)
  {
    risco_total += mst.edges[i].weight;
    //printf("%d %d %d\n", mst.edges[i].v1+1, mst.edges[i].v2+1, mst.edges[i].weight);
  }
  printf("Risco total: %d\n", risco_total);
  printf("Risco medio: %Lf\n", (long double)risco_total/(long double)g.edges.size());
}

void run_prim_vertex(Graph g, int n, std::vector<Edge> edges)
{
  printf("Running Prim Algorithm\n");
  printf("Struct: Priority Queue on Vertex with Change-Key\n");
  MST mst(n);
  
  std::clock_t t = std::clock();
  prim_vertex(g,mst);
  t = std::clock() - t;

  /*for(int i = 0 ; i < (int)cost.size(); i++)
  {
    std::cout << i+1 << ": " << cost[i] << std::endl;
  }*/

  printf("Time seconds: %f\n", ((float)t)/CLOCKS_PER_SEC);
  int risco_total = 0;
  for(int i = 0 ; i < (int)mst.edges.size() ; i++)
  {
    risco_total += mst.edges[i].weight;
    //printf("%d %d %d\n", mst.edges[i].v1+1, mst.edges[i].v2+1, mst.edges[i].weight);
  }
  printf("Risco total: %d\n", risco_total);
  printf("Risco medio: %Lf\n", (long double)risco_total/(long double)g.edges.size());
}