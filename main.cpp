#include "LinkedList.hpp"
#include "Array.hpp"
int main() {
  std::cout << "Hello\n";
  Array<int> myarr = Array();
  myarr->push_back(10);
  printf("%d", myarr);


  return 0;
}
