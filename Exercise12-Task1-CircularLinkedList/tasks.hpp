#pragma once

#include <cassert>
#include "CircularLinkedList.hpp"



// PRE: -
// POST: insert a new Node containing the value at the beginning of the list
void CircularLinkedList::insertAtBegin(unsigned int value) {
  assert(value > 0);
  // TODO
  Node* newNode = new Node(value);
  
  // begin with new node
  newNode->next = sentinel->next;
  sentinel->next = newNode;
}

// PRE: -
// POST: insert a new Node containing the value at the end of the list
void CircularLinkedList::insertAtEnd(unsigned int value) {
  assert(value > 0);
  // TODO
  // new node
  Node* newNode = new Node(value);
  
  // find the last node
  Node* lastNode = sentinel;
  while (lastNode->next->value != 0) {
    lastNode = lastNode->next;
  }
  
  // new node at the end
  lastNode->next = newNode;
  newNode->next = sentinel;
}

// PRE: -
// POST: removes *all* the nodes with the provided value from the list
//       and deallocates the memory of the deleted nodes.
void CircularLinkedList::removeValues(unsigned int value) {
  assert(value > 0);
  // TODO
  Node* currentNode = sentinel->next;
  Node* previousNode = sentinel;
  
  while (currentNode->value != 0) {
    if (currentNode->value == value) {
      // Remove the node with the specified value
      previousNode->next = currentNode->next;
      delete currentNode;
      currentNode = previousNode->next;
    } else {
      // Move to the next node
      previousNode = currentNode;
      currentNode = currentNode->next;
    }
  }
}

// POST: Deconstructs the whole list, which includes deallocating 
//       all its nodes and the sentinel
CircularLinkedList::~CircularLinkedList() {
  // TODO
  Node* currentNode = sentinel->next;
  while (currentNode->value != 0) {
    Node* nextNode = currentNode->next;
    delete currentNode;
    currentNode = nextNode;
  }
  
  // Deallocate the sentinel
  delete sentinel;
}
