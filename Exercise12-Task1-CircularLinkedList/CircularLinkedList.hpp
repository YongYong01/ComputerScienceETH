#pragma once

// ----------------------------------------------------------------------
// NOTE: You most likely only need to know that CircularLinkedList has a
//       member variable sentinel of type Node*.
// ----------------------------------------------------------------------


// The CircularLinkedList class contains a circular linked list that starts at member 
// variable sentinel, and it provides suitable functionality (e.g., insert a new 
// element), and basic memory management.

#include <cassert>
#include <iostream>
#include <stdexcept>
#include "Node.hpp"

class CircularLinkedList {

public:

  // declared as public for simplicity
  Node* sentinel;
  
  // constructor: initialize an empty queue
  CircularLinkedList() {
    sentinel = new Node(0);
    sentinel->next = sentinel;
  }

  // TODO: implement
  ~CircularLinkedList();
  
  // TODO: implement
  void insertAtEnd(unsigned int value);
  
  // TODO: implement
  void insertAtBegin(unsigned int value);
  
  // TODO: implement
  void removeValues(unsigned int value);


  // ----------------------------------------------------------------------
  // NOTE: You most likely don't need to read or understand any code
  // further down.
  // ----------------------------------------------------------------------  


  void show(std::ostream& out) const {
    out << "List=[";
    Node* node = sentinel->next;
    while (node->value != 0) {
      out << *node;
      if (node->next->value != 0) out << "=>";
      node = node->next;
    }
    out << "]";
  }


  // Prevent copying a CircularLinkedList
  CircularLinkedList(const CircularLinkedList&) = delete;
  CircularLinkedList operator=(const CircularLinkedList&) = delete;  
};

std::ostream& operator<<(std::ostream& out, const CircularLinkedList& list) {
  list.show(out);
  return out;  
}

struct MissingImplementationException: public std::exception {
  const char* what() const noexcept {
    return "An implementation is missing";
  }
};

inline void todo() {
  throw MissingImplementationException();
}
