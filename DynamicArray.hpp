#pragma once

#include <cstddef>
#include <stdexcept>
template <typename T>
class DynamicArray {
private:
    T* data_;
    size_t size_;
    size_t capacity_;

    void resize(size_t new_c) {
        T* new_data_ = new T[new_c];
        for (int i = 0; i < size_; i++) {
            new_data_[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data_;
        capacity_ = new_c;
    }
public:
    T* begin() { return data_; } // return beginning address for begin()
    T* end() { return data_ + size_; } // return address after the last element for end()

    const T* begin() const { return data_; } // return beginning address for begin()
    const T* end() const { return data_ + size_; } // return address after the last element for end()
                                       //
    DynamicArray() : data_(new T[10]), size_(0), capacity_(10) {}

    DynamicArray(size_t cap) : data_(new T[cap]), size_(0), capacity_(cap) {}

    ~DynamicArray() {
        delete[] data_;
    }

    // rule of 3:
    // Requires deconstructor, so also define:
    // - copy constructor
    // - copy assignment operator
    // Copy constructor - copy other DynamicArray to this
    DynamicArray(const DynamicArray& other) {
        capacity_ = other.capacity_;
        size_ = other.size_;
        data_ = new T[capacity_];
        for (int i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
    }

    // Copy assignment
    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) return *this;

        delete[] data_; // clean old
        capacity_ = other.capacity_;
        size_ = other.size_;
        data_ = new T[capacity_];
        for (int i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }

        return *this;
    }

    // append element to the end of the array
    void push_back(const T& value) { // pass by reference to avoid unnecessary copying
        if (size_ == capacity_) {
            // resize
            resize(capacity_ * 2);
        }
        data_[size_] = value;
        size_++;
    }

    // Remove last element (pop)
    void pop_back() {
        if (size_ == 0) {
            throw std::out_of_range("Array is empty, nothing to pop."); // throw error if array is empty, nothing to pop
        }
        size_--;
    }

    // access element
    T& operator[](size_t index) {
        return data_[index];
    }

    // access for const (not modifiable)
    const T& operator[](size_t index) const {
        return data_[index];
    }

    // safe access (throws IOB)
    T& at(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range.");
        }
        return data_[index];
    }

    size_t size() {
        return size_;
    }

    size_t get_capacity_() {
        return capacity_;
    }
};
