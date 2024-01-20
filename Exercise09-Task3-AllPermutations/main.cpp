#include <iostream>
#include <string>

#include "solution.h"

int main() {
  
  std::cout << "String: ";
  std::string s;
  std::cin >> s;

  StringSet permutations = all_permutations(s);
  std::cout << "Permutations: " << std::endl << permutations << std::endl;

  return 0;
}