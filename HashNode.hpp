#pragma once

template <typename K, typename V>
struct HashNode {
public:
    K key;
    V value;
    HashNode<K, V>* next;

    HashNode(const K& k, const V& val) : key(k), value(val), next(nullptr) {}
};
