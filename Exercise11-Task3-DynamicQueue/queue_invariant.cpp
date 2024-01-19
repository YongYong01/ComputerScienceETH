#include <cassert>
#include "queue.h"

void Queue::check_invariant() const {
  assert((first == nullptr) == (last == nullptr));
}