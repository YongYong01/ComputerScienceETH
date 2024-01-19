#pragma once

#include <vector>
using iterator = std::vector<unsigned int>::const_iterator;

// PRE:   iterator pair [begin,end) specifies a valid range
//        within a vector (begin is included, end is not) containing numbers 
//        in [0, 2147483647]. The range in the vector comprises at least two elements.
// POST:  returns the largest absolute difference between two neighbouring numbers in the vector. 
//
// Example:
//  * [1, 5, 2, 5, 7, 6] ~~> 4
//  * [2, 9, 1] ~~> 8
int my_abs(int value) {
    if (value < 0) {
        return -value;
    } else {
        return value;
    }
}

unsigned int largest_difference(iterator begin, iterator end) {
  //TODO
  unsigned int largest = 0;
  for(auto i = begin; std::next(i) != end; i++){
    unsigned int diff = my_abs(*i - *(std::next(i)));
    if(largest < diff){
      largest = diff;
    }
  }
  return largest;
}