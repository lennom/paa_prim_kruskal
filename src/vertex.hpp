#ifndef __VERTEX_HPP__
#define __VERTEX_HPP__


class Vertex
{
public:
  Vertex(int i, int w, int p)
    : id(i), weight(w), prev(p)
  {}

  Vertex()
    : id(-1), weight(-1), prev(-1)
  {}

  Vertex& operator=(const Vertex& l)  
  {  
    this->id = l.id;
    this->weight = l.weight;
    this->prev = l.prev;

    return *this;
  }  

  int id;
  int weight;
  int prev;
};


#endif