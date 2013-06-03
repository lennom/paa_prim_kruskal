/*
Data structure to store a set S of n elements where each element
v E S has an associated key k(v)

*/
#ifndef __PRIORITY_QUEUE_CHANGE_KEY_HPP__
#define __PRIORITY_QUEUE_CHANGE_KEY_HPP__

#include <vector>

template<class T>
class PQueue_CKey
{
public:
  PQueue_CKey()
  {
    data.clear();
  }

  void min_heapfy()
  {
    std::make_heap(data.begin(), data.end());
    std::sort_heap(data.begin(), data.end());
  }


  T extractMin()
  {
    T res = data[0];
    data.erase(data.begin(), data.begin()+1);
    
    min_heapfy();

    return res;
  }
  
  void add(T){}
  
  void del(T){}

  //O(lgn)
  void changeKey(){}

  std::vector<T> data;
};


#endif