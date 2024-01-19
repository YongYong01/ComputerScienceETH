#pragma once

#include <string>
#include <cassert>
#include "smart.h"

// tracked: linked list node using smart pointers instead of regular pointer
//          for next field, and such that all objects of that type are
//          tracked during execution.
struct tracked {
  // regular default/copy constructor, assignment operator, destructor
  // (except for the tracking part)
  tracked();
  tracked(const tracked&);
  tracked& operator=(const tracked&);
  ~tracked();
  // POST: Access fields. Attempt to detect illegal memory accesses.
  int& value();
  Smart& next();
  const int& value() const;
  const Smart& next() const;
private:
  int _value;
  Smart _next;
  void check(const std::string&) const;
  void checkc(const std::string&) const;
};

// POST: return number of elements of struct tracked currently in existence.
unsigned int count_tracked();
