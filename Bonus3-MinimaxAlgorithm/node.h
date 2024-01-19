#pragma once

#include <vector>
#include <iostream>

class Node {
public:
  // POST: create a node with given fields.
  Node(int, Node*, Node*);
  
  const int value; // current value of the node
  
  Node* left; // INV: if non-nullptr, leads to an allocated node
  Node* right; // INV: if non-nullptr, leads to an allocated node
  
  // POST: Delete a node and its subtree (if any) without memory leaks
  ~Node(); 
};
