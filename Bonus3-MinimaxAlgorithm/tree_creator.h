#pragma once

// POST: read integers from stream is and create binary tree.
bool create_tree(std::istream& is, Node*& root);

void print_tree(Node*& root);
