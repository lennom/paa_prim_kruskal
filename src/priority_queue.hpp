#ifndef _PRIORITY_QUEUE_HPP_
#define _PRIORITY_QUEUE_HPP_

#include <queue>
#include <functional>

void priority_queue_example()
{
  std::cout << "MAX priority queue" << std::endl;
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

  std::cout << "MIN priority queue" << std::endl;
  std::priority_queue<int, std::vector<int>, std::greater<int>> q2;

  q2.push(2);
  q2.push(4);
  q2.push(1);
  q2.push(0);
  q2.push(9);
  q2.push(100);
  q2.push(40);
  q2.push(10);
  q2.push(3);
  q2.push(8);

  int pqueue2 = (int)q2.size();
  for(int i = 0 ; i < pqueue2 ; i++) {std::cout << q2.top() << std::endl; q2.pop();}

}

#endif