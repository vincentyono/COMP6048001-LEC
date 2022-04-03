#ifndef NODE_H
#define NODE_H

template <typename T> struct Node {
  Node(T data);
  ~Node();
  T data;
  Node<T> *next;
};

#include "Node.cpp"

#endif