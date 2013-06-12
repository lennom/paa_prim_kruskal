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

  void Union(int t1, int t2)
  {
     if(abs(sets[t1]) >= abs(sets[t2]))
    {
      sets[t1] = -1*std::max(abs(sets[t1]), abs(sets[t2]) + 1);
      sets[t2] = t1;
    }
    else if(abs(sets[t1]) < abs(sets[t2]))
    {
      sets[t2] = -1*std::max(abs(sets[t2]), abs(sets[t1]) + 1);
      sets[t1] = t2;
    }
  }

  int Find_Set(int index)
  {
    //int cam_medio = 0;
    if(sets[index] < 0)
    {
      //printf("%d\n", cam_medio);
      return index;
    }
    int i = index;
    while(sets[i] >= 0)
    {
      i = sets[i];
      //cam_medio++;
    }
    sets[index] = i;
    //printf("%d\n", cam_medio);
    return i;
  }

  int height(int set)
  {
    int a = Find_Set(set);
    return abs(sets[a]+1);
  }

  void print()
  {
    for(int j = 0 ; j < (int)sets.size() ;j++)
    {
      std::cout << sets[j] << " ";
    }
    std::cout << std::endl;
  }

  std::vector<int> sets;
};

#endif