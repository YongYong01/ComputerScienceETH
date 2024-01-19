#include "num_elements.h"

// PRE: a <= b are valid pointers to elements of the same contiguous memory block.
// POST: Returns the number of elements in between those pointers (starting at a, not including b).
int num_elements(const int* a, const int* b) {
  // TODO
  if (a <= b) {
    return b - a;
  } else {
    return 0;
  }
}