#include "LinkedList.h"
#include "Node.h"
#include "StackLinkedList.h"
#include <iostream>

int main() {
  StackLinkedList<std::string> *stack = new StackLinkedList<std::string>();

  std::cout << "===========Testing Stack===========" << std::endl;

  stack->push("Apple");                              // ["Apple"]
  std::cout << "Top: " << stack->top() << std::endl; // Top: Apple
  stack->push("Ball");                               // ["Apple", "Ball"]
  std::cout << "Top: " << stack->top() << std::endl; // Top: Ball
  stack->pop();                                      // ["Apple"]
  std::cout << "Top: " << stack->top() << std::endl; // Top: Apple
  stack->push("Cat");                                // ["Apple", "Cat"]
  std::cout << "Top: " << stack->top() << std::endl; // Top: Cat

  std::cout << "===========Testing LinkedList===========" << std::endl;

  LinkedList<int> *linkedlist = new LinkedList<int>();
  linkedlist->append(3); // [3]
  linkedlist->print();
  linkedlist->insertFirst(2); // [2, 3]
  linkedlist->print();
  linkedlist->append(4); // [2, 3, 4]
  linkedlist->print();
  linkedlist->append(5); // [2, 3, 4, 5]
  linkedlist->print();
  linkedlist->insertFirst(1); // [1, 2, 3, 4, 5]
  linkedlist->print();

  std::cout << "===========Testing ReversePrint===========" << std::endl;

  linkedlist
      ->ReversePrint(); // Time complexity of recursive ReversePrint = O(n)
  linkedlist->ReversePrintIterative(); // Time complexity of Iterative
                                       // ReversePrint = O(n)

  return 0;
}