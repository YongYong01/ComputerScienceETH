#include <iostream>
#include <istream>
#include <vector>
#include "functions.h"


// ----------------------------------------------------------------------
// NOTE: You most likely don't need to read and understand
// the content of this file
// ----------------------------------------------------------------------

int main() {
  std::cout << "Enter a sequence of non-negative numbers terminating with '-1'\n";
  std::vector<unsigned int> numbers = {};
  int number;
  do {
    std::cin >> number;
    if (number != -1)
      numbers.push_back(number);
  } while (number != -1 && std::cin.good());
  
  const char marker = '|';

  std::cout << "largest difference between two neighbouring numbers = "
            << marker
            << largest_difference(numbers.begin(), numbers.end()) 
            << marker
            << '\n';
            
  return 0;
}
