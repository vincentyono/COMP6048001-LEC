#include "LinkedList.h"
#include "Node.h"
#include "StackLinkedList.h"
#include <iostream>

int main() {
  StackLinkedList<std::string> *stack = new StackLinkedList<std::string>();
  stack->push("Apple");
  std::cout << "Stack Top: " << stack->top() << ", Count: " << stack->size()
            << std::endl; // Apple
  stack->push("Pear");
  std::cout << "Stack Top: " << stack->top() << ", Count: " << stack->size()
            << std::endl; // Apple
  stack->pop();
  std::cout << "Stack Top: " << stack->top() << ", Count: " << stack->size()
            << std::endl; // Apple

  LinkedList<int> *linkedlist = new LinkedList<int>();
  linkedlist->append(3);
  linkedlist->insertFirst(2);
  linkedlist->append(4);
  linkedlist->insertFirst(1);
  linkedlist->append(5);
  linkedlist->ReversePrint();
  linkedlist->ReversePrintIterative();

  return 0;
}