/*
Data structure to store a set S of n elements where each element
v E S has an associated key k(v)

*/


#ifndef __PRIORITY_QUEUE_CHANGE_KEY_HPP__
#define __PRIORITY_QUEUE_CHANGE_KEY_HPP__

template<class T>
class PQueue_CKey
{
  T extractMin();
  
  void add(T);
  
  void del(T);

  //O(lgn)
  void changeKey();
};


#endif