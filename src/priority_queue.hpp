#ifndef _PRIORITY_QUEUE_HPP_
#define _PRIORITY_QUEUE_HPP_

#include <queue>

void priority_queue_example()
{
  std::priority_queue<int> q1;

  q1.push(2);
  q1.push(4);
  q1.push(1);
  q1.push(0);
  q1.push(9);
  q1.push(100);
  q1.push(40);
  q1.push(10);
  q1.push(3);
  q1.push(8);

  int pqueue = (int)q1.size();
  for(int i = 0 ; i < pqueue ; i++) {std::cout << q1.top() << std::endl; q1.pop();}
}

#endif