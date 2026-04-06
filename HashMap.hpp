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
// Let's just start with 10 buckets_
private:
    DynamicArray<LinkedList<HashNode<K, V>>> buckets_;
    size_t numBuckets_;

public:
    HashMap(size_t initialbuckets_ = 10) : buckets_(initialbuckets_), numBuckets_(initialbuckets_) {}

    void insert(const K& key, const V& value) {
        size_t index = hash(key) % numBuckets_;
        LinkedList<HashNode<K, V>>& bucket = buckets_[index];

        for (auto& node : bucket) {
            if (node.key == key) {
                node.value = value;
                return;
            }
        }

        bucket.push_back(HashNode<K, V>(key, value));
        numBuckets_++;
    }

    // how is this possible for a generic K?
    // here we use std::hash<K> to generate a hash function
    // the limitation of this is that it only works if
    // a specialization exists for type K.
    size_t hash(const K& key) const { // implement hash function
        return std::hash<K>{}(key); // returns hash function for builtin types
    }

    void print() const {
        for (auto& bucket : buckets_) {
            auto curr = bucket;

            while (curr) {
                std::cout << "[" << curr.key << ": " << curr.value << "]";
                if (curr.next) {
                    std::cout << " --> ";
                } else {
                    std::cout << "\n";
                }
                curr = curr.next;
            }
        }

    }
};
