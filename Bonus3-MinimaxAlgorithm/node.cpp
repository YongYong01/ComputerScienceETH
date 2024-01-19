#include "node.h"

Node::Node(int v, Node* l, Node* m) : value(v), left(l), right(m) {}

// POST: Delete a node and its subtree (if any) without memory leaks
Node::~Node(){
  // TODO
  delete left;
  delete right;
}