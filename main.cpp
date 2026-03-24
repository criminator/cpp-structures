#include "LinkedList.hpp"
#include "DynamicArray.hpp"
int main() {
  DynamicArray<int> myarr;
  std::cout << "Size: " << myarr.size() << std::endl;
  myarr.push_back(10);
  myarr.push_back(20);
  myarr.push_back(30);
  myarr.push_back(40);
  myarr.push_back(50);
  std::cout << "Array: [";
  for (int i = 0; i < myarr.size(); i++) {
    if (i < myarr.size() - 1) {
      std::cout << myarr.at(i) << ", ";
    } else {
      std::cout << myarr.at(i) << "]\n";
    }
  }

  size_t sum = 0;
  for (auto& num : myarr) {
    sum += num;
  }

  std::cout << "Sum: " << sum << "\n";

  return 0;
}
