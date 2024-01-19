#pragma once

/////////////////////////////////////////////////////////////////////////////
// DECLARATIONS
/////////////////////////////////////////////////////////////////////////////


struct Node {
  Node(const int _value, Node* _next) : value(_value), next(_next) { }
  const int value;
  Node* next;
};

class Queue {
public:
  // PRE:  -
  // POST: Valid and empty queue.
  Queue();

  // PRE:  Valid queue.
  // POST: Valid queue with new node having value i added at end of queue.
  void enqueue(int value);

  // PRE:  Valid and non-empty queue.
  // POST: Removes first node from queue.
  //       Returns content of first node.
  int dequeue();

  // PRE:  Valid queue.
  // POST: Returns true if queue is empty, false otherwise.
  bool is_empty() const;

  // PRE:  Valid queue.
  // POST: Outputs queue content to the standard output in sequence from first to last.
  void print() const;
  
  // PRE: Valid queue
  // POST: Outputs queue content to the standard output in reverse order, from last to first.
  void print_reverse() const;
  
  // PRE: -
  // POST: Ensures class invariant.
  void check_invariant() const;

private:

  // Class invariant: first == nullptr iff last == nullptr
  Node* first; // pointer to first element of queue or nullptr is queue is empty.
  Node* last;  // pointer to last element of queue or nullptr if queue is empty.
};
