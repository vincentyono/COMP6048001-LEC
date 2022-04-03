#ifndef STACKLINKEDLIST_H
#define STACKLINKEDLIST_H

#include "LinkedList.h"

template <typename T> class StackLinkedList {
public:
  StackLinkedList();
  ~StackLinkedList();
  void push(T data);
  void pop();
  T top() const;
  int size() const;

private:
  LinkedList<T> *list;
  int count;
};

#include "StackLinkedList.cpp"

#endif