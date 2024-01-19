#pragma once

#include <vector>

using iterator = std::vector<int>::const_iterator;

//post: returns the number of indices (i,j), i<j of a vector v
//      that corresponds to the given iterator range such that
//      v[i] + v[j] == sum.
unsigned int pairs_with_sum(int sum, iterator begin, iterator end);
