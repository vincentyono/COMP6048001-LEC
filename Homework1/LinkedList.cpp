#include "LinkedList.h"
#include "Node.h"
#include <iostream>

template <typename T> LinkedList<T>::LinkedList() {
  this->head = nullptr;
  this->count = 0;
}

template <typename T> LinkedList<T>::~LinkedList() {
  Node<T> *current = this->head;
  while (current != nullptr) {
    Node<T> *next = current->next;
    delete current;
    current = next;
  }
  this->head = nullptr;
}

template <typename T> bool LinkedList<T>::isEmpty() const {
  return this->head == nullptr;
}

template <typename T> int LinkedList<T>::size() const { return this->count; }

template <typename T> void LinkedList<T>::append(T data) {
  if (this->head == nullptr) {
    this->head = new Node<T>(data);
    return;
  }

  Node<T> *current = this->head;
  while (current->next != nullptr) {
    current = current->next;
  }
  current->next = new Node<T>(data);
  this->count++;
}

template <typename T> void LinkedList<T>::insertFirst(T data) {
  Node<T> *node = new Node<T>(data);
  node->next = this->head;
  this->head = node;
  this->count++;
}

template <typename T> void LinkedList<T>::print() const {
  Node<T> *current = this->head;
  while (current->next != nullptr) {
    std::cout << current->data << " -> ";
    current = current->next;
  }
  std::cout << current->data << std::endl;
}

template <typename T> void LinkedList<T>::ReversePrint() const {
  ReversePrint(this->head->next);
  std::cout << this->head->data << " -> ";
}

template <typename T> void LinkedList<T>::ReversePrint(Node<T> *ptr) const {
  if (ptr == nullptr)
    std::cout << "nullptr" << std::endl;
  if (ptr != nullptr) {
    ReversePrint(ptr->next);
    std::cout << ptr->data << " -> ";
  }
}

template <typename T> void LinkedList<T>::ReversePrintIterative() const {
  T *arr = new T[this->count + 1];
  Node<T> *current = this->head;
  for (int i = 0; i <= this->count; i++) {
    arr[i] = current->data;
    current = current->next;
  }
  for (int i = this->count - 1; i >= 0; i--) {
    std::cout << arr[i] << " -> ";
  }
  std::cout << "nullptr" << std::endl;
}

template <typename T> void LinkedList<T>::remove(T data) {
  Node<T> *current = this->head;
  Node<T> *prev;
  while (current->next != nullptr) {
    if (current->data == data) {
      break;
    }
    prev = current;
    current = current->next;
  }

  if (current->data == data) {
    prev->next = current->next;
    this->count--;
  }
}

template <typename T> void LinkedList<T>::removeFirst() {
  Node<T> *current = this->head;
  this->head = this->head->next;
  this->count--;
}

template <typename T> void LinkedList<T>::removeLast() {
  Node<T> *current = this->head;
  Node<T> *prev;
  while (current->next != nullptr) {
    prev = current;
    current = current->next;
  }
  prev->next = nullptr;
  this->count--;
}

template <typename T> T LinkedList<T>::getHead() const {
  return this->head->data;
}
