#include <iostream>
#include <unordered_set>
#include "tracker.h"

using ms = std::unordered_set<const tracked*>;

namespace {

  struct Manager {
    ms tracker;
    static ms& getManager() {
      static Manager m;
      return m.tracker;
    }
  };

}

void tracked::check(const std::string& s) const {
  ms& m(Manager::getManager());
  if (m.find(this) == m.end()) {
    std::cout << "Error: you are accessing unallocated memory (" << s << ")" << std::endl;
    std::terminate();
  }
}

void tracked::checkc(const std::string& s) const {
  ms& m(Manager::getManager());
  if(m.find(this) != m.end()) {
    std::cout << "Error: you are somehow constructing an object within previously allocated memory (" << s << ")" << std::endl;
    std::terminate();
  }
}

tracked::tracked() : _value(), _next() {
  checkc("default constructor");
  Manager::getManager().insert(this);
}

tracked::tracked(const tracked& t) : _value(t._value), _next(t._next) {
  checkc("default constructor");
  t.check("copy constructor source");
  Manager::getManager().insert(this);
}

tracked& tracked::operator=(const tracked& t) {
  t.check("assignment operator source");
  check("assignment operator target");
  _value = t._value;
  _next = t._next;
  return (*this);
}

tracked::~tracked() {
  check("deleting tracked object");
  Manager::getManager().erase(this);
}

int& tracked::value() {
  check("value accessor");
  return _value;
}

const int& tracked::value() const {
  check("const value accessor");
  return _value;
}

Smart& tracked::next() {
  check("next accessor");
  return _next;
}

const Smart& tracked::next() const {
  check("const next accessor");
  return _next;
}


unsigned int count_tracked() {
  return Manager::getManager().size();
}



