#ifndef _UNION_FIND_HPP_
#define _UNION_FIND_HPP_

#include <vector>
#include <cstdio>

class Union_Find
{
public:
  Union_Find(int size)
  {
    for(int i = 0 ; i < size ; i++)
    {
      sets.push_back(-1);
      //cada um é seu próprio set
    }
  }

  ~Union_Find()
  {
    sets.clear();
  }

  void union_sets(int s1, int s2)
  {
    int t1 = find_set(s1);
    int t2 = find_set(s2);

    //se altura de t1 for maior
    if(abs(sets[t1]) >= abs(sets[t2]))
    {
      sets[t1] = -1*std::max(abs(sets[t1]), abs(sets[t2]) + 1);
      sets[t2] = t1;
    }
    else  //altura de t2 é maior
    {
      sets[t2] = -1*std::max(abs(sets[t2]), abs(sets[t1]) + 1);
      sets[t1] = t2;
    }
  }

  int find_set(int index)
  {
    if(sets[index] < 0)
    {
      return index;
    }
    int i = index;
    while(sets[i] >= 0)
    {
      i = sets[i];
    }
    sets[index] = i;
    return i;
  }

  int height(int set)
  {
    int a = find_set(set);
    return abs(sets[a]+1);
  }

  std::vector<int> sets;
};

#endif