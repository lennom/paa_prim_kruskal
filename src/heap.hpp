#ifndef _HEAP_HPP_
#define _HEAP_HPP_

#include <vector>
#include <iostream>

#include "vertex.hpp"
#include "mst.hpp"

//Implementação de um heap com change Key para vértices de um grafo
class Heap_min_Vertex
{
public:
  Heap_min_Vertex()
  {
  }

  Heap_min_Vertex(int n)
  {
    for(int i = 0 ; i < n ; i++)
    {
      insert(Vertex(i, std::numeric_limits<int>::max(), -1));
    }
  }

  ~Heap_min_Vertex()
  {
    heap.clear();
    position.clear();
  }

  void clear()
  {
    heap.clear();
    position.clear();
  }

  void insert(Vertex element)
  {
    heap.push_back(element);
    position.push_back(heap.size() - 1);
    heapifyup(position[heap.size() - 1]);
  }

  Vertex deletemin()
  {
    Vertex min = heap.front();
    position[min.id] = heap.size() - 1;
    heap[0] = heap[(int)heap.size() - 1];
    position[heap[0].id] = 0;
    heap.pop_back();
    heapifydown(position[heap[0].id]);
    return min;
  }

  Vertex pop()
  {
    return deletemin();
  }

  void print()
  {
    std::cout << "Heap = ";
    for(int i = 0 ; i < (int)heap.size() ; i++)
    {
      std::cout << "(" << heap[i].id << ", " 
        << heap[i].prev << ", " 
        << heap[i].weight << ")" << " ";  
    }
    std::cout << std::endl;
  }

  int size()
  {
    return (int)heap.size();
  }

  bool is_empty()
  {
    return heap.empty();
  }

  void decrease_key(int id, int weight)
  {
    heap[position[id]].weight = weight;
    heapifyup(position[id]);
  }

  void positions()
  {
    std::cout << "Positions: ";
    for(int i = 0 ; i < (int)position.size(); i++)
    {
      std::cout << i << "-" << position[i] << "  ";
    }
    std::cout << std::endl;
  }

  void set_previous(int id, int prev)
  {
    heap[position[id]].prev = prev;
  }

  void test()
  {
    Heap_min_Vertex v;
    v.insert(Vertex(0, 60, -1));
    v.insert(Vertex(1, 70, -1));
    v.insert(Vertex(2, 10, -1));
    v.insert(Vertex(3, 20, -1));
    v.insert(Vertex(4, 40, -1));
    v.insert(Vertex(5, 50, -1));
    v.insert(Vertex(6, 60, -1));
    v.insert(Vertex(7, 70, -1));
    v.insert(Vertex(8, 10, -1));

    v.decrease_key(7, 5);

    v.print();
  }

  int get_cost(int id)
  {
    return heap[position[id]].weight;
  }

private:
  int left(int parent)
  {
    int i = ( parent << 1 ) + 1; // 2 * parent + 1
    return ( i < (int)heap.size() ) ? i : -1;
  }

  int right(int parent)
  {
    int i = ( parent << 1 ) + 2; // 2 * parent + 2
    return ( i < (int)heap.size() ) ? i : -1;
  }

  int parent(int child)
  {
    if (child != 0)
    {
      int i = (child - 1) >> 1;
      return i;
    }
    return -1;
  }

  void heapifyup(int index)
  {
    while ( ( index > 0 ) && ( parent(index) >= 0 ) &&
      ( heap[parent(index)].weight > heap[index].weight ) )
    {
      Vertex tmp = heap[parent(index)];
      int tmpPos = position[tmp.id];
      
      position[tmp.id] = index;
      position[heap[index].id] = tmpPos;

      heap[parent(index)] = heap[index];
      heap[index] = tmp;
      index = parent(index);
    }
  }

  void heapifydown(int index)
  { 
    int child = left(index);
    if ( ( child > 0 ) && ( right(index) > 0 ) &&
         ( heap[child].weight > heap[right(index)].weight ) )
    {
        child = right(index);
    }
    if ( child > 0 && (heap[index].weight > heap[child].weight) )
    {
      Vertex tmp = heap[index];
      int tmpPos = position[tmp.id];

      position[tmp.id] = child;//position[heap[child].id];
      position[heap[child].id] = tmpPos;

      heap[index] = heap[child];
      heap[child] = tmp;
      heapifydown(child);
    }
  }

  std::vector<int> position;
  std::vector<Vertex> heap;
};

//Implementação de um heap para um tipo qualquer de dados
template<class T>
class Heap_min
{
public:
  Heap_min()
  {
  }

  ~Heap_min()
  {
    heap.clear();
  }

  void insert(T element)
  {
    heap.push_back(element);
    heapifyup(heap.size() - 1);
  }

  T deletemin()
  {
    T min = heap.front();
    heap[0] = heap.at((int)heap.size() - 1);
    heap.pop_back();
    heapifydown(0);
    return min;
  }

  T pop()
  {
    return deletemin();
  }

  void print()
  {
    std::vector<int>::iterator pos = heap.begin();
    std::cout << "Heap = ";
    while ( pos != heap.end() ) {
      std::cout << *pos << " ";
      ++pos;
    }
    std::cout << std::endl;
  }

  void print_tree()
  {
    std::vector<int>::iterator pos = heap.begin();
    std::cout << "Heap = ";
    while ( pos != heap.end() ) {
      std::cout << *pos << " ";
      ++pos;
    }
    std::cout << std::endl;
  }

  int size()
  {
    return (int)heap.size();
  }

  void test()
  {
    Heap_min<int>* myheap = new Heap_min<int>();
    myheap->insert(700);
    myheap->print();
    myheap->insert(500);
    myheap->print();
    myheap->insert(100);
    myheap->print();
    myheap->insert(800);
    myheap->print();
    myheap->insert(200);
    myheap->print();
    myheap->insert(400);
    myheap->print();
    myheap->insert(900);
    myheap->print();
    myheap->insert(1000);
    myheap->print();
    myheap->insert(300);
    myheap->print();
    myheap->insert(600);
    myheap->print();

    int heapSize = myheap->size();
    for ( int i = 0; i < heapSize; i++ )
      std::cout << "Get min element = " << myheap->deletemin() << std::endl;

    delete myheap;
  }

  bool is_empty()
  {
    return ((int)heap.size() == 0);
  }

private:
  int left(int parent)
  {
    int i = ( parent << 1 ) + 1; // 2 * parent + 1
    return ( i < (int)heap.size() ) ? i : -1;
  }

  int right(int parent)
  {
    int i = ( parent << 1 ) + 2; // 2 * parent + 2
    return ( i < (int)heap.size() ) ? i : -1;
  }

  int parent(int child)
  {
    if (child != 0)
    {
      int i = (child - 1) >> 1;
      return i;
    }
    return -1;
  }

  void heapifyup(int index)
  {
    while ( ( index > 0 ) && ( parent(index) >= 0 ) &&
      ( heap[parent(index)] > heap[index] ) )
    {
      T tmp = heap[parent(index)];
      heap[parent(index)] = heap[index];
      heap[index] = tmp;
      index = parent(index);
    }
  }

  void heapifydown(int index)
  {
    int child = left(index);
    if ( ( child > 0 ) && ( right(index) > 0 ) &&
         ( heap[child] > heap[right(index)] ) )
    {
        child = right(index);
    }
    if ( child > 0 && (heap[index] > heap[child]))
    {
        T tmp = heap[index];
        heap[index] = heap[child];
        heap[child] = tmp;
        heapifydown(child);
    }

    /*int left_child = left(index);
    int right_child = right(index);
    if( left_child > 0 && (heap[index].weight > heap[left_child].weight) )
    {
      T tmp = heap[index];
      heap[index] = heap[left_child];
      heap[left_child] = tmp;
      heapifydown(left_child);
    }
    if( right_child > 0 && (heap[index].weight > heap[right_child].weight) )
    {
      T tmp = heap[index];
      heap[index] = heap[right_child];
      heap[right_child] = tmp;
      heapifydown(right_child);
    }*/

    /*int child = left(index);
    if ( ( child > 0 ) && ( right(index) > 0 ) &&
      ( heap[child] > heap[right(index)] ) )
    {
      child = right(index);
    }
    if ( child > 0 )
    {
      int tmp = heap[index];
      heap[index] = heap[child];
      heap[child] = tmp;
      heapifydown(child);
    }*/
  }

  std::vector<T> heap;
};

class Heap_min_Edge
{
public:
  Heap_min_Edge()
  {
    heap.clear();
  }

  ~Heap_min_Edge()
  {
    heap.clear();
  }

  void insert(Edge element)
  {
    heap.push_back(element);
    heapifyup(heap.size() - 1);
  }

  Edge deletemin()
  {
    Edge min = heap.front();
    heap[0] = heap.at((int)heap.size() - 1);
    heap.pop_back();
    heapifydown(0);
    return min;
  }

  Edge pop()
  {
    return deletemin();
  }

  int size()
  {
    return (int)heap.size();
  }
  
  bool is_empty()
  {
    return ((int)heap.size() == 0);
  }

private:
  int left(int parent)
  {
    int i = ( parent << 1 ) + 1; // 2 * parent + 1
    return ( i < (int)heap.size() ) ? i : -1;
  }

  int right(int parent)
  {
    int i = ( parent << 1 ) + 2; // 2 * parent + 2
    return ( i < (int)heap.size() ) ? i : -1;
  }

  int parent(int child)
  {
    if (child != 0)
    {
      int i = (child - 1) >> 1;
      return i;
    }
    return -1;
  }

  void heapifyup(int index)
  {
    while ( ( index > 0 ) && ( parent(index) >= 0 ) &&
      ( heap[parent(index)].weight > heap[index].weight ) )
    {
      Edge tmp = heap[parent(index)];
      heap[parent(index)] = heap[index];
      heap[index] = tmp;
      index = parent(index);
    }
  }

  void heapifydown(int index)
  {
    int child = left(index);
    if ( ( child > 0 ) && ( right(index) > 0 ) &&
         ( heap[child].weight > heap[right(index)].weight ) )
    {
        child = right(index);
    }
    if ( child > 0 && (heap[index].weight > heap[child].weight) )
    {
        Edge tmp = heap[index];
        heap[index] = heap[child];
        heap[child] = tmp;
        heapifydown(child);
    }
  }

  std::vector<Edge> heap;
};

#endif