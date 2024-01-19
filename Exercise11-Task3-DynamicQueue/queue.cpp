#include <iostream>
#include <cassert>
#include "queue.h"

/////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION
/////////////////////////////////////////////////////////////////////////////

Queue::Queue(): first(nullptr), last(nullptr) /*TODO*/ {
  //TODO
}

void Queue::enqueue(int value) {
  // TODO
  Node* new_node = new Node(value, nullptr);

  // if empty initialize
  if (last == nullptr) {
    first = new_node;
    last = new_node;
  } 
  else {
    // new pointer if not empty
    last->next = new_node;
    last = new_node;
  }
}

int Queue::dequeue() {
  // TODO
  // Save the value of the first node
  int dequeued_value = first->value;

  // Move to the next node in the queue
  first = first->next;

  if (first == nullptr) {
    last = nullptr;
  }

  return dequeued_value;
}

bool Queue::is_empty() const {
  // TODO
  if (last == nullptr) {
    return true;
  }
  else{
    return false;
  }
}

void print_node_reverse(Node* n){
  if (n != nullptr) {
    print_node_reverse(n->next);
    std::cout << n->value << " ";
  }
}

void Queue::print_reverse() const {
  std::cout << "[";
  if (first != nullptr) {
    print_node_reverse(first->next);
    std::cout << first->value;
  }
  std::cout << "]";
}

// PRE: -
// POST: print the sequence of integers in nodes reachable from n,
//       in order, with one space before each integer.
void print_node(Node* n) {
  if (n != nullptr) {
    std::cout << " " << n->value;
    print_node(n->next);
  }
}


void Queue::print() const {
  std::cout << "[";
  if (first != nullptr) {
    std::cout << first->value;
    print_node(first->next);
  }
  std::cout << "]";
}
