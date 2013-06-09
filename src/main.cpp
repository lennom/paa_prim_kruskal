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
  for(int i = 1 ; i < 1000000 ; i+=1000)
  {
    for(int j = 0 ; j < i ; j++)
    {
      fq.push_back(rand() % 1000);
    }
    std::vector<int> r;
    std::clock_t t = std::clock();
    //CountingSort(fq,r,1000);
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
  printf("Running Kruskal Algorithm\n");
  printf("Sort method: Heapsort\n");

  MST mst(n);
  MST mst_vec(n);

  kruskal_hs(g,mst,edges);
  int risco_total = 0;
  for(int i = 0 ; i < (int)mst.edges.size() ; i++)
  {
    risco_total += mst.edges[i].weight;
    //printf("%d %d %d\n", mst.edges[i].v1+1, mst.edges[i].v2+1, mst.edges[i].weight);
  }
  printf("Risco total (Pointer): %d\n", risco_total);
  printf("Risco medio (Pointer): %Lf\n", (long double)risco_total/(long double)g.edges.size());

  printf("\n");
  kruskal_hs_vec(g,mst_vec,edges);
  risco_total = 0;
  for(int i = 0 ; i < (int)mst_vec.edges.size() ; i++)
  {
    risco_total += mst_vec.edges[i].weight;
    //printf("%d %d %d\n", mst.edges[i].v1+1, mst.edges[i].v2+1, mst.edges[i].weight);
  }
  printf("Risco total (Vector): %d\n", risco_total);
  printf("Risco medio (Vector): %Lf\n", (long double)risco_total/(long double)g.edges.size());
}

void run_kruskal_cs(Graph g, int n, std::vector<Edge> edges)
{
  printf("Running Kruskal Algorithm\n");
  printf("Sort method: Counting Sort\n");

  MST mst(n);
  MST mst_vec(n);

  kruskal_cs(g,mst,edges);
  int risco_total = 0;
  for(int i = 0 ; i < (int)mst.edges.size() ; i++)
  {
    risco_total += mst.edges[i].weight;
    //printf("%d %d %d\n", mst.edges[i].v1+1, mst.edges[i].v2+1, mst.edges[i].weight);
  }
  printf("Risco total (Pointer): %d\n", risco_total);
  printf("Risco medio (Pointer): %Lf\n", (long double)risco_total/(long double)g.edges.size());
  
  printf("\n");
  kruskal_cs_vec(g,mst_vec,edges);
  risco_total = 0;
  for(int i = 0 ; i < (int)mst_vec.edges.size() ; i++)
  {
    risco_total += mst_vec.edges[i].weight;
    //printf("%d %d %d\n", mst.edges[i].v1+1, mst.edges[i].v2+1, mst.edges[i].weight);
  }
  printf("Risco total (Vector): %d\n", risco_total);
  printf("Risco medio (Vector): %Lf\n", (long double)risco_total/(long double)g.edges.size());
}

void run_prim_edges(Graph g, int n, std::vector<Edge> edges)
{
  printf("Running Prim Algorithm\n");
  printf("Struct: Priority Queue on Edges\n");
  MST mst(n);
  MST mst_pqueue(n);

  prim_edges(g,mst);
  int risco_total = 0;
  for(int i = 0 ; i < (int)mst.edges.size() ; i++)
  {
    risco_total += mst.edges[i].weight;
    //printf("%d %d %d\n", mst.edges[i].v1+1, mst.edges[i].v2+1, mst.edges[i].weight);
  }
  printf("Risco total (Heap Min Vector): %d\n", risco_total);
  printf("Risco medio (Heap Min Vector): %Lf\n", (long double)risco_total/(long double)g.edges.size());

  printf("\n");
  prim_edges_pqueue(g,mst_pqueue);
  risco_total = 0;
  for(int i = 0 ; i < (int)mst_pqueue.edges.size() ; i++)
  {
    risco_total += mst_pqueue.edges[i].weight;
    //printf("%d %d %d\n", mst.edges[i].v1+1, mst.edges[i].v2+1, mst.edges[i].weight);
  }
  printf("Risco total (Priority Queue): %d\n", risco_total);
  printf("Risco medio (Priority Queue): %Lf\n", (long double)risco_total/(long double)g.edges.size());
  
}

void run_prim_vertex(Graph g, int n, std::vector<Edge> edges)
{
  printf("Running Prim Algorithm\n");
  printf("Struct: Priority Queue on Vertex with Change-Key\n");
  int risco_total = 0;

  /*MST mst(n);
  prim_vertex_pointer(g,mst);
  risco_total = 0;
  for(int i = 0 ; i < (int)mst.edges.size() ; i++)
  {
    risco_total += mst.edges[i].weight;
    //printf("%d %d %d\n", mst.edges[i].v1+1, mst.edges[i].v2+1, mst.edges[i].weight);
  }
  printf("Risco total (Heap Pointer): %d\n", risco_total);
  printf("Risco medio (Heap Pointer): %Lf\n", (long double)risco_total/(long double)g.edges.size());*/

  MST mst_vec(n);
  prim_vertex_vec(g,mst_vec);
  risco_total = 0;
  for(int i = 0 ; i < (int)mst_vec.edges.size() ; i++)
  {
    risco_total += mst_vec.edges[i].weight;
    //printf("%d %d %d\n", mst.edges[i].v1+1, mst.edges[i].v2+1, mst.edges[i].weight);
  }
  printf("Risco total (Heap Vector): %d\n", risco_total);
  printf("Risco medio (Heap Vector): %Lf\n", (long double)risco_total/(long double)g.edges.size());
}