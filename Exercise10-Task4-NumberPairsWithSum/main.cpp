#include <iostream>
#include <string>
#include <sstream>

#include "pair_sum.h"

int main() {
  
  // Note: You do not need to understand std::getline, std::stringstream and 
  //       how this works.
  
  // get line from cin
  std::string line;
  std::getline(std::cin, line);
  std::stringstream line_ss(line);
  
  // get target sum (first int)
  int sum;
  line_ss >> sum;
  
  // get vector (remaining ints)
  std::vector<int> vec;
  int value;
  while (line_ss >> value){
    vec.push_back(value);
  }

  // compute result
  std::cout << "number of pairs with sum " << sum << ": ";
  std::cout << pairs_with_sum(sum, vec.begin(), vec.end());
}