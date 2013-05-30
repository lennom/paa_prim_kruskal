#ifndef _COUNTING_SORT_HPP_
#define _COUNTING_SORT_HPP_

#include "mst.hpp"
#include <vector>
#include <iostream>

void CountingSort(std::vector<int> A, std::vector<int> &B, int k)
{
  std::vector<int> C;
  for(int i = 0 ; i <= k ; i++)
  {
    C.push_back(0);
  }
  for(int i = 0 ; i < (int)A.size() ; i++)
  {
    B.push_back(0);
  }

  for(int i = 0 ; i < (int)A.size() ; i++)
  {
    C[A[i]] += 1;
  }
  for(int i = 1 ; i <= k ; i++)
  {
    C[i] = C[i] + C[i-1];
  }
  
  for(int j = (int)A.size()-1 ; j >= 0 ; j--)
  {
    B[C[A[j]]-1] = A[j];
    C[A[j]] = C[A[j]]- 1;
  }
}

void CountingSortEdges(std::vector<Edge> A, std::vector<Edge> &B, int k)
{
  std::vector<int> C;
  for(int i = 0 ; i <= k ; i++)
  {
    C.push_back(0);
  }
  for(int i = 0 ; i < (int)A.size() ; i++)
  {
    B.push_back(Edge());
  }

  for(int i = 0 ; i < (int)A.size() ; i++)
  {
    C[A[i].weight] += 1;
  }
  for(int i = 1 ; i <= k ; i++)
  {
    C[i] = C[i] + C[i-1];
  }
  
  for(int j = (int)A.size()-1 ; j >= 0 ; j--)
  {
    B[C[A[j].weight]-1] = A[j];
    C[A[j].weight] = C[A[j].weight]- 1;
  }
}

#endif