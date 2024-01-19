#include <iostream>
#include <climits>
#include "node.h"
#include "tree_creator.h"

// POST: Return the best possible value for the maximizing player from this 
//       position in the tree. This function does NOT modify the tree.
int minimax(Node* position, bool colour) {
  // TODO: Implement.
  // Base case: if the node is a leaf, return value
  if (position->left == nullptr && position->right == nullptr){
    return position->value;
  }
  
  // Recursive Function (colour = true is Anna)
  if (colour){
    int maxScore = INT_MIN; // negative infinity (for pruning)
    if (position->left != nullptr){
      maxScore = std::max(maxScore, minimax(position->left, !colour));
    }
    if (position->right != nullptr){
      maxScore = std::max(maxScore, minimax(position->right, !colour));
    }
    return maxScore;
  }
  // colour = false is Ralph
  else{ 
    int minScore = INT_MAX; // positive infinity (for pruning)
    if (position->left != nullptr) {
      minScore = std::min(minScore, minimax(position->left, !colour));
    }
    if (position->right != nullptr) {
      minScore = std::min(minScore, minimax(position->right, !colour));
    }
    return minScore;
  }
  return 0;
}


// POST: Performs Alpha Beta pruning to remove the branches that are not
//       worth considering. The function only performs pruning and does NOT
//       modify the values of the nodes.
int alpha_beta_pruning(Node* position, int alpha, int beta, bool colour) {
  // TODO: Implement.
  if (position->left == nullptr && position->right == nullptr){
    return position->value;
  }
  
  // Recursive Function (colour = true is Anna)
  if (colour) {  // Maximizing player (Anna - purple)
    int maxScore = INT_MIN;
    if (position->left != nullptr) {
      maxScore = std::max(maxScore, alpha_beta_pruning(position->left, alpha, beta, !colour));
      alpha = std::max(alpha, maxScore);
    }
    if (beta <= alpha) {
      delete position->right;
      position->right = nullptr;
      return maxScore;  // Prune the right child
    }
    if (position->right != nullptr) {
      maxScore = std::max(maxScore, alpha_beta_pruning(position->right, alpha, beta, !colour));
      alpha = std::max(alpha, maxScore);
    }
    return maxScore;
  } else {  // Minimizing player (Raphi - black)
    int minScore = INT_MAX;
    if (position->left != nullptr) {
      minScore = std::min(minScore, alpha_beta_pruning(position->left, alpha, beta, !colour));
      beta = std::min(beta, minScore);
    }
    if (beta <= alpha) {
      delete position->right;
      position->right = nullptr;
      return minScore;  // Prune the right child
    }
    if (position->right != nullptr) {
      minScore = std::min(minScore, alpha_beta_pruning(position->right, alpha, beta, !colour));
      beta = std::min(beta, minScore);
    }
    return minScore;
  }
}

// Do not change the code after this point
int main() {
  Node* root;
  
  bool success = create_tree(std::cin, root);
  if (!success) {
    std::cout << "Error: Could not create the tree." << '\n';
    return 1;
  }
  
  std::cout << "\n>> " << minimax(root, true) << " << " << '\n';
  alpha_beta_pruning(root, INT_MIN, INT_MAX, true);
  print_tree(root);
  std::cout << "\n>> " << minimax(root, true) << " << " << '\n';
    
  // Release all the allocated memory.
  delete root;
  
  return 0;
}
