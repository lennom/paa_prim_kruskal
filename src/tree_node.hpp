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
    int cam_medio = 1;
    /*if(this->m_head == NULL)
    {
      printf("%d\n", cam_medio);
      return this;
    }*/
    Tree_node* aux = this;
    while(aux->m_head != NULL)
    {
      aux = aux->m_head;
      cam_medio++;
    }
    //m_head = aux;
    printf("%d\n", cam_medio);
    return aux;
  }

  void Union_Sets(Tree_node* t1, Tree_node* t2)
  {
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
    int cam_medio = 1;
    /*if(this->m_head == NULL)
    {
      printf("%d\n", cam_medio);
      return this->m_value;
    }*/
    Tree_node* aux = this;
    while(aux->m_head != NULL)
    {
      aux = aux->m_head;
      cam_medio++;
    }
    //m_head = aux;
    printf("%d\n", cam_medio);
    return aux->m_value;
  }

  Tree_node* m_head;
  T m_value;
  int height;
};
#endif