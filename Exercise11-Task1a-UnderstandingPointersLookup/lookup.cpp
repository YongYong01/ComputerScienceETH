#include "lookup.h"

// PRE:  0 <= i < vec.size()
// POST: Returns the address of the i-th element of vec.
const int* lookup(const std::vector<int>& vec, const int i) {
  // TODO
  return &vec.at(i);
}