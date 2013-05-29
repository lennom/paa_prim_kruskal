#ifndef _MINIMUM_SPAMMING_TREE_H_
#define _MINIMUM_SPAMMING_TREE_H_

#include <vector>
#include <iostream>

class MST  
{
public:
  MST(bool _directed = false) : directed(_directed)
  {
    V = 0;
    E = 0;
  }

  MST(int nNodes, bool _directed = false) : directed(_directed)
  {
    V = nNodes;
    for(int i = 0 ; i < nNodes; i++)
    {
      edges.push_back(std::vector<int>(0));
    }
  }

  ~MST() {}

  void add_edge(int v1, int v2)
  {
    if(v1 > V || v2 > V)
    {
      std::cout << "Não foi possível adicionar a aresta, vértices não indexado" << std::endl;
      return;
    }

    //adiciona apenas (v1,v2) 
    if(directed)
    {
      edges[v1].push_back(v2);
    }
    //grafo não direcionado (v1,v2) = (v2,v1)
    else
    {
      edges[v1].push_back(v2);
      edges[v2].push_back(v1);
    }
  }

  bool directed;
  unsigned int V;
  unsigned int E;
  std::vector<std::vector<int>> edges;
};

#endif