#pragma once

#include <cstddef>
#include <functional>
#include "HashNode.hpp"
#include "DynamicArray.hpp"
#include "LinkedList.hpp"

template<typename K, typename V>
class HashMap {
  // HashMap
  // will contain a list of LinkedList objects
  // I will use DynamicArray as the array implementation and LinkedList for the linked list
  // Let's just start with 10 buckets
private:
  DynamicArray<LinkedList<HashNode<K, V>>> buckets;
  size_t numBuckets;

public:
  HashMap(size_t initialBuckets = 10) : buckets(initialBuckets), numBuckets(initialBuckets) {}

  void insert(const K& key, const V& value) {
    size_t index = hash(key) % numBuckets;
    LinkedList<HashNode<K, V>>& bucket = buckets[index];

    for (auto& node : bucket) {
      if (node.key == key) {
        node.value = value;
        return;
      }
    }

    bucket.push_back(HashNode<K, V>(key, value));

  }

  // how is this possible for a generic K?
  // here we use std::hash<K> to generate a hash function
  // the limitation of this is that it only works if
  // a specialization exists for type K.
  size_t hash(const K& key) const { // implement hash function
    return std::hash<K>{}(key); // returns hash function for builtin types
  }

  void print() const {

  }

};
