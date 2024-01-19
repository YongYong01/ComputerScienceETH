#include <iostream>
#include <vector>
#include "lookup.h"

int main() {
  std::vector<int> vec = std::vector<int>(0);
  int value;
  unsigned int length;
  unsigned int index;
  std::cin >> length;
  for (unsigned int i = 0; i < length; ++i) {
    std::cin >> value;
    vec.push_back(value);
  }
  std::cin >> index;
  std::cout << *lookup(vec, index) << "\n";
  return 0;
}