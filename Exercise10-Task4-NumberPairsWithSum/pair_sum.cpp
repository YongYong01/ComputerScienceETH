#include "pair_sum.h"

unsigned int pairs_with_sum(int sum, iterator begin, iterator end){
  // TODO
   unsigned int count = 0;

    for (auto i = begin; i != end; ++i) {
        for (auto j = std::next(i); j != end; ++j) {
            // Check sum
            if (*i + *j == sum) {
                ++count;
            }
        }
    }

    return count;
}