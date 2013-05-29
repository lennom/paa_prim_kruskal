#ifndef _PATH_COMPRESSION_HPP_
#define _PATH_COMPRESSION_HPP_

template<class T>
class Path_Compression  
{
public:
    Path_Compression();
    void SetValue( T obj_i );
    T Getalue();
    
    void Make_Set();
    void Union();
    T Find_Set();
 
  /*Operations:
  Make-Set(x): create a new set Sx, whose only member 
  is x (assuming x is not already in one of the sets).
  Union(x, y): replace two disjoint sets Sx
  and Sy represented by x and y by their union.
  Find-Set(x): find and return the representative of the 
  set Sx that contains x.
  */
 
private:
    T m_Obj;
};

#endif