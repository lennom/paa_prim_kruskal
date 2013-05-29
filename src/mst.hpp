#ifndef _MINIMUM_SPAMMING_TREE_H_
#define _MINIMUM_SPAMMING_TREE_H_

#include <vector>
#include <iostream>

class Edge
{
public:
  Edge(int vi, int vf, int w) 
    : v1(vi), v2(vf), weight(w)
  {}

  int v1;
  int v2;
  int weight;
};

struct Edge_compare  
{  
  bool operator()(const Edge& l, const Edge& r)  
  {  
    return l.weight > r.weight;  
  }  
}; 


class MST  
{
public:
  MST(bool _directed = false) : directed(_directed)
  {
    V = 0;
  }

  MST(int nNodes, bool _directed = false) : directed(_directed)
  {
    V = nNodes;
  }

  ~MST() {}

  void add_edge(int v1, int v2, int w = 1)
  {
    if(v1 > V || v2 > V)
    {
      std::cout << "error on vertex index." << std::endl;
      return;
    }

    //adiciona apenas (v1,v2) 
    if(directed)
    {
      edges.push_back(Edge(v1,v2,w));
    }
    //grafo não direcionado (v1,v2) = (v2,v1)
    else
    {
      edges.push_back(Edge(v1,v2,w));
      edges.push_back(Edge(v2,v1,w));
    }
  }

  bool directed;
  int V;
  std::vector<Edge> edges;
};

#endif