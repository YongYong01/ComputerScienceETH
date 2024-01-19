#include <iostream>
#include <list>
#include <cmath>
#include "node.h"

bool create_tree(std::istream& is, Node*& root) {
    int value;
    std::list<Node*> nodes;
    while (is >> value) {
      Node* node = new Node(value, nullptr, nullptr);
      nodes.push_back(node);
    }
    
    if(ceil(log2(nodes.size()))!= floor(log2(nodes.size()))){
      std::cout << "This is not a full binary tree." << std::endl;
      return false;
    }
    
    while(nodes.size() != 1){
      std::list<Node*> parentNodes;
      while(!nodes.empty()){
        Node* leftNode = nodes.front();
        nodes.pop_front();
        Node* rightNode = nodes.front();
        nodes.pop_front();
        Node* parentNode = new Node(0, leftNode, rightNode);
        parentNodes.push_back(parentNode);
      }
      nodes = parentNodes;
    }
    root = nodes.front();
    return true;
}

void print_tree(Node*& root){
  if(!root->left && !root->right){// It's a leaf!
    std::cout << root->value;
  }
  else{// It's an internal node
    std::cout << "[";
    if(root->left){
      print_tree(root->left);
    }
    if(root->left && root->right){
      std::cout << ",";
    }
    if(root->right){
      print_tree(root->right);
    }
    std::cout << "]";
  }
}