#include <iterator>
template <typename T>
class Array {
private:
  T* data;
  size_t size;
  size_t capacity;
  
public:
  Array() : data(new T[100]), size(0), capacity(100) {}

  ~Array() {
    delete[] data;
  }

  void push_back(T value) {
    if (size == capacity) {
      // resize
      size_t new_capacity = capacity * 2;
      T* new_data = new T[new_capicity];
      for (int i = 0; i < size; i++) {
        new_data[i] = data[i]; // copies each element into new data
      }
      delete[] data;
      data = new_data;
      capacity = new_capacity;

      printf("\033[91mERROR: capacity full.");
      return;
    }
    data[size] = value;
    size++;
  }
  

};
