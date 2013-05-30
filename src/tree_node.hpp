#ifndef _PATH_COMPRESSION_HPP_
#define _PATH_COMPRESSION_HPP_

template<class T>
class Tree_node  
{
public:
  Tree_node()
  {
    m_head = NULL;
  }

  ~Tree_node()
  {
    m_head = NULL;
  }

  void Make_Set(T value)
  {
    m_value = value;
    m_head = NULL;
    height = 0;
  }

  Tree_node* Find_Set_Reference()
  {
    Tree_node* aux = this;
    while(aux->m_head != NULL)
      aux = aux->m_head;
    
    return aux;
  }

  void Union(Tree_node* u, Tree_node* v)
  {
    Tree_node* t1 = u->Find_Set_Reference(); 
    Tree_node* t2 = v->Find_Set_Reference();
    if(t1->height >= t2->height)
    {
      t1->m_head = t2;
      t2->height = std::max(t2->height, t1->height+1);
    }
    else if(t1->height < t2->height)
    {
      t2->m_head = t1;
      t1->height = std::max(t1->height, t2->height+1);
    }
  }

  T Find_Set()
  {
    Tree_node* aux = this;
    while(aux->m_head != NULL)
      aux = aux->m_head;
    
    return aux->m_value;
  }

  Tree_node* m_head;
  T m_value;
  int height;
};
#endif