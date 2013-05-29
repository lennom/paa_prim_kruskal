#ifndef _UNION_BY_RANK_H_
#define _UNION_BY_RANK_H_

template<class T>
class Union_by_rank  
{
public:
    Union_by_rank();
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