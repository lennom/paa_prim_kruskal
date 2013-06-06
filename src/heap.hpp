#ifndef _HEAP_HPP_
#define _HEAP_HPP_

#include <vector>
#include <iostream>

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
      int tmp = heap[parent(index)];
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
    if ( child > 0 )
    {
      int tmp = heap[index];
      heap[index] = heap[child];
      heap[child] = tmp;
      heapifydown(child);
    }
  }

  std::vector<T> heap;
};

#endif