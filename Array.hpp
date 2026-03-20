#include <iterator>
template <typename T>
class Array {
private:
  T* data;
  size_t size;
  size_t capacity;
  
public:
  Array() : data(new T[100]), size(0), capacity(100) {}

  void push_back(T value) {
    if (size > capacity) {
      // resize
      printf("\033[91mERROR: capacity full.");
      return;
    }
    data[size] = value;
    size++;
  }
  

};
