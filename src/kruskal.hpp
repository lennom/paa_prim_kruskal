#ifndef __KRUSKAL__HPP__
#define __KRUSKAL__HPP__

#include <vector>

#include "graph.hpp"
#include "mst.hpp"
#include "heapsort.hpp"
#include "tree_node.hpp"
#include "union_Find.hpp"

#include <ctime>

/////////////////////////////////////////
// Utilizando Union Find com ponteiros //
/////////////////////////////////////////
void kruskal_hs(Graph G, MST &T, std::vector<Edge> edges)
{
  
  heapsortEdges(edges);
  //////////////////////
  /*  std::vector<Edge> ed = edges;
  float time_t = 0.0f;
  for(int j = 0 ; j < 30 ; j++)
  {
    edges = ed;
    T = MST(G.V);
  std::clock_t t = std::clock();*/
  ////////////////
  std::vector<Tree_node<int>*> components(G.V);
  for(int i = 0 ; i < G.V ; i++)
  {
    components[i] = new Tree_node<int>();
    components[i]->Make_Set(i);
  }


  int m = edges.size();
  for(int i = 0 ; i < m ; i++)
  {
    /*for(int j = 0 ; j < G.V ;j++)
    {
      int a = components[j]->m_head == NULL ? -1 : components[j]->m_head->m_value;
      std::cout << a << " ";
    }
    std::cout << std::endl;*/

    int u = edges[i].v1;
    int v = edges[i].v2;

    Tree_node<int>* t1 = components[u]->Find_Set(); 
    Tree_node<int>* t2 = components[v]->Find_Set();
    if(t1->m_value != t2->m_value)
    {
      T.add_edge(edges[i].v1,edges[i].v2,edges[i].weight);
      components[u]->Union(t1, t2);
    }

  }
  int csize = (int)components.size();
  for(int i = 0 ; i < csize ; i++)
  {
    delete components[i];
  }
  ////////////////////////////
  /*t = std::clock() - t;
  time_t +=  ((float)t)/CLOCKS_PER_SEC;
  }
  printf("Time seconds (Pointers): %f\n", time_t);*/
  ////////////////////////////
}
 
void kruskal_cs(Graph G, MST &T, std::vector<Edge> edges)
{
  int w_max = 0;
  for(int i = 0 ; i < (int)edges.size() ; i++)
  {
    w_max = std::max(w_max, edges[i].weight);
  }
  std::vector<Edge> edges_sorted;
  CountingSortEdges(edges, edges_sorted, w_max);

  /////////////////////
  /*std::vector<Edge> ed = edges_sorted;
  float time_t = 0.0f;
  for(int j = 0 ; j < 30 ; j++)
  {
    edges_sorted = ed;
    T = MST(G.V);
  std::clock_t t = std::clock();*/
  /////////////////////

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
    Tree_node<int>* t1 = components[u]->Find_Set(); 
    Tree_node<int>* t2 = components[v]->Find_Set();
    if(t1->m_value != t2->m_value)
    {
      T.add_edge(edges_sorted[i].v1,edges_sorted[i].v2,edges_sorted[i].weight);
      components[u]->Union(t1, t2);
    }
  }
  
  int csize = (int)components.size();
  for(int i = 0 ; i < csize ; i++)
  {
    delete components[i];
  }
  ////////////////////////////
  /*t = std::clock() - t;
  time_t +=  ((float)t)/CLOCKS_PER_SEC;
  }
  printf("Time seconds (Pointers): %f\n", time_t);*/
  ////////////////////////////
}
///////////////////////////////////////
// Utilizando Union Find com Vetores //
///////////////////////////////////////
void kruskal_hs_vec(Graph G, MST &T, std::vector<Edge> edges)
{
  heapsortEdges(edges);
  
  /////////////////////
  /*std::vector<Edge> ed = edges;
  float time_t = 0.0f;
  for(int j = 0 ; j < 30 ; j++)
  {
    edges = ed;
    T = MST(G.V);
  std::clock_t t = std::clock();*/
  /////////////////////
  Union_Find unf(G.V);
  
  int m = edges.size();
  for(int i = 0 ; i < m ; i++)
  {
    int u = edges[i].v1;
    int v = edges[i].v2;

    int t1 = unf.Find_Set(u); 
    int t2 = unf.Find_Set(v); 
    if(t1 != t2)
    {
      T.add_edge(edges[i].v1,edges[i].v2,edges[i].weight);
      unf.Union(t1, t2);
    }

  }
  /////////////////////////
  /*t = std::clock() - t;
  time_t +=  ((float)t)/CLOCKS_PER_SEC;
  }
  printf("Time seconds (Vectors): %f\n", time_t);*/
  /////////////////////////
}
 
void kruskal_cs_vec(Graph G, MST &T, std::vector<Edge> edges_in)
{
  int w_max = 0;
  for(int i = 0 ; i < (int)edges_in.size() ; i++)
  {
    w_max = std::max(w_max, edges_in[i].weight);
  }
  std::vector<Edge> edges;
  CountingSortEdges(edges_in, edges, w_max);

  /////////////////////
  /*std::vector<Edge> ed = edges;
  float time_t = 0.0f;
  for(int j = 0 ; j < 30 ; j++)
  {
    edges = ed;
    T = MST(G.V);
  std::clock_t t = std::clock();*/
  /////////////////////
  Union_Find unf(G.V);
  
  int m = edges.size();
  for(int i = 0 ; i < m ; i++)
  {
    int u = edges[i].v1;
    int v = edges[i].v2;

    int t1 = unf.Find_Set(u); 
    int t2 = unf.Find_Set(v); 
    if(t1 != t2)
    {
      T.add_edge(edges[i].v1,edges[i].v2,edges[i].weight);
      unf.Union(t1, t2);
    }
  }
  /////////////////////////
  /*t = std::clock() - t;
  time_t +=  ((float)t)/CLOCKS_PER_SEC;
  }
  printf("Time seconds (Vectors): %f\n", time_t);*/
  /////////////////////////
}

#endif