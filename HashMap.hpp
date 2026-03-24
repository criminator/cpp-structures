#pragma once

#include "HashNode.hpp"

template<typename K, typename V>
class HashMap {
private:
  HashNode<K, V>* head;
  size_t size_;

public:
  HashMap() : head(nullptr), size_(0) {}

  // put a value at the end of the list
  void put(const K& key, const V& val) {
    if (size_ == 0) {
      head = new HashNode<K, V>(key, val);
      size_++;
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
    HashNode<K, V>* newNode = new HashNode<K, V>(key, val);
    newNode->next = head;
    size_++;
    head = newNode;
  }

  // return the value at the key
  V* get(const K& k) {
    HashNode<K, V>* curr = head;
    while (curr != nullptr) {
      if (curr->key == k) return &curr->value;
      curr = curr->next;
    }
    return nullptr;
  }
};
