#pragma once
#include <stdlib.h>
#include "HashNode.hpp"

template<typename K, typename V>
class HashMap {
private:
  HashNode<K, V>* head;
  size_t size_;

public:
  void put(K key, V val) {
    if (size_ == 0) {
      head = new HashNode<K, V>(key, val);
      return;
    }
    HashNode<K, V>* curr = head;
    while (curr) {
      if (curr->key == key) {
        curr->value = val;
        return;
      }
      curr = curr->next;
    }
    HashNode<K, V>* newNode = new HashNode(key, val);
    newNode->next = head;
    head = newNode;
  }
};
