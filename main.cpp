#include "LinkedList.hpp"
#include "DynamicArray.hpp"
#include "HashMap.hpp"

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

  HashMap<int, int> mymap;
  mymap.put(10, 20);
  mymap.put(100, 400);
  mymap.put(120, 12345);
  mymap.put(140, 20);
  int* val = mymap.get(120);
  std::cout << *val << std::endl;

  size_t sum = 0;
  for (auto& num : myarr) {
    sum += num;
  }

  LinkedList<int> mylist = LinkedList<int>();
  mylist.push_back(10);
  mylist.push_back(20);
  mylist.push_back(30);
  mylist.push_back(40);
  mylist.print();
  std::cout << "Remove element at index 1 of ll (20)\n";
  mylist.remove(1);
  mylist.print();


  std::cout << "Sum: " << sum << "\n";

  return 0;
}
