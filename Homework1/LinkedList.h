#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <typename T> class LinkedList {
public:
  LinkedList();
  ~LinkedList();
  bool isEmpty() const;
  int size() const;
  void append(T data);
  void insertFirst(T data);
  void print() const;
  void ReversePrint() const;
  void ReversePrint(Node<T> *ptr) const;
  void ReversePrintIterative() const;
  void remove(T data);
  void removeFirst();
  void removeLast();
  T getHead() const;

private:
  Node<T> *head;
  int count;
};

#include "LinkedList.cpp"

#endif