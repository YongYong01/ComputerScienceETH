#include "smart.h"
#include "tracker.h"

Smart::Smart() /* TODO */ {
  // TODO
  count = nullptr;
  ptr = nullptr;
}

Smart::Smart(tracked* t) /* TODO */ {
  // TODO
  count = nullptr;
  ptr = t;
  if (t != nullptr) {
    count = new unsigned int(1);
  }
}

Smart::Smart(const Smart& src) /* TODO */ {
  // TODO
  count = src.count;
  ptr = src.ptr;
  if (count != nullptr) {
    ++*count;
  }
}

Smart::~Smart() {
  // TODO
  if (count != nullptr && --*count == 0) {
    delete count;
    delete ptr;
  }
}

Smart& Smart::operator=(const Smart& src) {
  // TODO
  if (ptr != src.ptr){
    Smart copy(src);
    std::swap(count, copy.count);
    std::swap(ptr, copy.ptr);
  }
  return(*this);
}

tracked& Smart::operator*() {
  return *ptr;
}

const tracked& Smart::operator*() const {
  return *ptr;
}

tracked* Smart::operator->() {
  return ptr;
}

const tracked* Smart::operator->() const {
  return ptr;
}

bool Smart::operator==(const Smart& cmp) const {
  return (ptr == cmp.ptr);
}

bool Smart::operator!=(const Smart& cmp) const {
  return !(*this == cmp);
}

unsigned int Smart::get_count() const{
  if (this -> count == nullptr)
    return 0;
  else
    return *(this->count);
}

void your_own_tests() {
  // EXTRA TESTS ?
  // Test 1: Create empty Smart object
  Smart emptySmart;
  assert(emptySmart.get_count() == 0);

  // Test 2: Creating a Smart object with a tracked object
  tracked* obj = new tracked;
  Smart smartWithObject(obj);
  assert(smartWithObject.get_count() == 1);

  // Test 3: Copy constructor and reference counting
  Smart copySmart(smartWithObject);
  assert(smartWithObject.get_count() == 2);
  
  delete obj;
}
