#pragma once

#include <iostream>

// ----------------------------------------------------------------------
// NOTE: Use struct Node in your implementation
// ----------------------------------------------------------------------
static int allocations;

struct Node {
  // For simplicity, all member variables are public
  unsigned int value; // value 0 reserved for the sentinel
  Node* next;

  // Node constructor
  Node(unsigned int _value): value(_value), next(nullptr) {

    // For bookkeeping allocations, please ignore
    ++allocations;
  }


  // ----------------------------------------------------------------------
  // NOTE: You most likely don't need to read or understand any code
  // further down.
  // ----------------------------------------------------------------------
  
  // Deconstructor: destructs this node only
  ~Node() {
    // For bookkeeping allocations, please ignore
    --allocations;
  }

  // Prevent copying of nodes
  Node(const Node& n) = delete;
  Node operator=(const Node& n) = delete;
};

std::ostream& operator<<(std::ostream& out, const Node& node) {
  out << "(" << node.value << ")";
  return out;
}
