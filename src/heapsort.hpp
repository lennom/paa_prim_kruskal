#ifndef _HEAPSORT_HPP_
#define _HEAPSORT_HPP_

#include <vector>
#include <iostream>
#include <algorithm> // for std::make_heap, std::sort_heap

template <typename Iterator>
void heapsort_algorithm(Iterator begin, Iterator end)
{
    std::make_heap(begin, end);
    std::sort_heap(begin, end);
}
 
template <typename Iterator>
void heapsort_verbose(Iterator begin, Iterator end)
{
    std::make_heap(begin, end);
    while (begin != end)
        std::pop_heap(begin, end--);
}

void heapsort(std::vector<int> &v)
{
  heapsort_algorithm(v.begin(), v.end());
}

void heapsort(int v[])
{
  //vector.size()
  const int VSIZE = sizeof(v)/sizeof(*v);

  heapsort_algorithm(v, v+VSIZE);
}

//da pra tentar deixar mais genérico depois, mas por enquanto
//deixa assim que funciona
template <typename Iterator>
void heapsort_algorithm_Edges(Iterator begin, Iterator end)
{
  std::make_heap(begin, end, Edge_compare);
  std::sort_heap(begin, end, Edge_compare);
}

void heapsortEdges(std::vector<Edge> &v)
{
  heapsort_algorithm_Edges(v.begin(), v.end());
}

#endif