#pragma once

#include <assert.h>

#include <iostream>
#include <set>
#include <vector>

// This file contains several function declarations for sets. The implementation 
// is in `set.tpp`. However, there is no need for you to understand any impleme-
// tation details. Please refer to the set demo for further guidance.
template <typename T>
class Set {
 public:
  Set(const Set& other);
  // Creates an empty set
  Set();
  // Creates a new set from a set of elements
  Set(const std::set<T>& elements);
  // Creates a new set from a single element
  Set(T element);

  // Returns the number of elements in the set
  unsigned int size() const;
  // Inserts an element into the set
  void insert(T element);
  // Removes an element from the set
  void remove(T element); 
  bool contains(T element) const;

  bool is_subset(const Set& other) const;
  bool is_superset(const Set& other) const;
  bool is_equal(const Set& other) const;
  bool is_unequal(const Set& other) const;
  bool is_strict_subset(const Set& other) const;
  bool is_strict_superset(const Set& other) const;
  
  // Copies the other set
  Set<T>& operator=(const Set<T>& other);

  bool operator<(const Set<T>& other) const;
  bool operator>(const Set<T>& other) const;
  bool operator==(const Set<T>& other) const;

  // Returns the i-th element in the Set
  const T& at(unsigned int i) const;
  // Returns a set with all elements from the current and the other set
  Set<T> operator+(const Set<T>& other) const;
  // Returns a set with all elements from the current set that are not in the other set 
  Set<T> operator-(const Set<T>& other) const;

  // Returns the intersetction of elements with the other set
  Set<T> intersection(const Set<T>& other) const;

  const std::set<T>& elements() const;
  
 private:
  std::set<T> m_elements;
};

template <typename T>
Set<T> set_union(const std::vector<Set<T>>& sets);

// Prints all elements in `set` to output `os`
template <typename T>
std::ostream& operator<<(std::ostream& os, const Set<T>& set);

template <typename T>
std::istream& operator>>(std::istream& is, Set<T>& set);


#include "set.tpp"
