#include <iostream>
#include "Node.hpp"

template <typename T>
class LinkedList {
public:
  Node<T>* head;
  size_t size;

  void push_back(const T& node) {
    if (!head) {
      head = node;
      return;
    }
    Node<T>* curr = head;
    while (curr->next != nullptr) {
      curr = curr->next;
    }
    curr->next = node;
    size++;
  }

  void insert(int key, const T& node) {
    if (key >= size || key < 0) {
      std::cout << "\033[91mKey out of range.\033[0m\n";
      return;
    }
    if (key == 0) {
      node->next = head;
      head = node;
      return;
    }
    Node<T>* curr = head;
    for (int i = 0; i < key - 1; i++) {
      curr = curr->next;
    }
    Node<T>* temp = curr->next;
    curr->next = node;
    node->next = temp;
  }
};
