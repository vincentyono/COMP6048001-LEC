#include "StackLinkedList.h"
#include "LinkedList.h"
#include <iostream>

template <typename T> StackLinkedList<T>::StackLinkedList() {
  this->list = new LinkedList<T>();
  this->count = 0;
}

template <typename T> StackLinkedList<T>::~StackLinkedList() {
  delete this->list;
}

template <typename T> void StackLinkedList<T>::push(T data) {
  this->list->insertFirst(data);
  this->count++;
}
template <typename T> void StackLinkedList<T>::pop() {
  this->list->removeFirst();
  this->count--;
}
template <typename T> T StackLinkedList<T>::top() const {
  return this->list->getHead();
}

template <typename T> int StackLinkedList<T>::size() const {
  return this->count;
}