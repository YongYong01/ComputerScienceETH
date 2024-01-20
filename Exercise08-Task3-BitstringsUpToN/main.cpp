#include <iostream>
#include <string>
#include <vector>

#include "solution.h"

int main() {
  std::cout << "Bitstring length: ";
  unsigned int n;
  std::cin >> n;
  
  std::vector<std::string> bitstrings = all_bitstrings_up_to_n(n);
  
  std::cout << "Bitstrings up to length " << n << std::endl;
  for (unsigned int i = 0; i < bitstrings.size(); ++i) {
    std::cout << bitstrings.at(i) << std::endl;
  }

  return 0;
}