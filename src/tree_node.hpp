#ifndef _PATH_COMPRESSION_HPP_
#define _PATH_COMPRESSION_HPP_

template<class T>
class Tree_node  
{
public:
  pc_node()
  {
    m_head = NULL;
  }

  ~pc_node()
  {
    m_head = NULL;
  }

  void Make_Set(T value)
  {
    m_value = value;
    m_head = NULL;
    height = 0;
  }

  void Union(ubr_node* t1, ubr_node* t2)
  {
    if(t1->height == t2->height)
    {
      t1->m_head = t2;
    }

  }

  T Find_Set()
  {
    return m_head;
  }

  ubr_node* m_head;
  T m_value;
  int height;
};
#endif