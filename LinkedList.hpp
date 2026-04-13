#pragma once

#include <cstddef>
#include <iostream>
#include "Node.hpp"

template <typename T>
class LinkedList {
private:
    Node<T>* head = nullptr;
    size_t size_ = 0;
public:
    LinkedList() = default;

    // Destructor (just call clear)
    ~LinkedList() {
        clear();
    }

    // Copy constructor
    LinkedList(const LinkedList& other) : head(nullptr), size_(0) {
        Node<T>* curr = other.head;
        while (curr != nullptr) {
            push_back(curr->value);
            curr = curr->next;
        }
    }

    // for LinkedList = otherLinkedList
    LinkedList& operator=(const LinkedList& other) {
        if (this == &other) return *this;

        clear();

        Node<T>* curr = other.head;
        while (curr != nullptr) {
            push_back(curr->value);
            curr = curr->next;
        }
        return *this;
    }

    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            size_++;
            return;
        }
        Node<T>* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
        size_++;
    }

    bool insert(size_t key, const T& value) {
        if (key > size_) {
            return false;
        }
        Node<T>* node = new Node<T>(value);
        if (key == 0) {
            node->next = head;
            head = node;
            size_++;
            return true;
        }
        Node<T>* curr = head;
        for (size_t i = 0; i < key - 1; i++) {
            curr = curr->next;
        }
        node->next = curr->next;
        curr->next = node;
        size_++;
        return true;
    }

    // check if empty
    bool empty() const { return size_ == 0; }

    // get first element
    T& front() { return head->value; }
    // and for const -> doesnt change anything in the list
    const T& front() const { return head->value; }

    // Remove the head
    void pop_front() {
        if (!head) return;
        Node<T>* old = head;
        head = head->next;
        delete old;
        size_--;
    }

    // Remove a node at a given index
    bool remove(size_t index) {
        if (index >= size_) {
            return false;
        }
        if (index == 0) {
            pop_front();
            return true;
        }
        Node<T>* curr = head;
        for (size_t i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        // at this point, curr is at index - 1
        Node<T>* toDelete = curr->next;
        curr->next = toDelete->next;
        delete toDelete;
        size_--;
        return true;
    }

    // return the size
    size_t size() const { return size_; }

    // clear
    void clear() {
        Node<T>* curr = head;
        while (curr != nullptr) {
            Node<T>* next = curr->next;
            delete curr;
            curr = next;
        }
        head = nullptr;
        size_ = 0;
    }

    // print
    void print() const {
        Node<T>* curr = head;
        while (curr->next != nullptr) {
            std::cout << curr->value << " -> ";
            curr = curr->next;
        }
        std::cout << curr->value << "\n";
    }

    // get head
    Node<T>* getHead() { return head; }
};
