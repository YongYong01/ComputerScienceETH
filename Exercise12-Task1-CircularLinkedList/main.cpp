// ----------------------------------------------------------------------
// NOTE: You most likely don't need to read and understand
// the content of this file
// ----------------------------------------------------------------------

#include <cassert>
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include "tasks.hpp"

void on_terminate() noexcept {
  if (auto current_exception = std::current_exception()) { 
    try {
      // Rethrow to recognize exception type  
      rethrow_exception(current_exception);
    } catch (const MissingImplementationException&) {
      // Silently discard these exceptions
    }
  }
}

std::string emptyAsText(bool empty) {
  return empty ? "List empty" : "List not empty";
}

bool interactWithUser() {
  CircularLinkedList list;
  std::string op;

  // Input and execute queue commands, until the user exits the program
  while (true) {
    std::cin >> op;
    if (op == "insertAtBegin" || op == "ib") {
      unsigned int value;
      std::cin >> value;
      list.insertAtBegin(value);
    }
    else if (op == "insertAtEnd" || op == "ie") {
      unsigned int value;
      std::cin >> value;
      list.insertAtEnd(value);
    }
    else if (op == "remove" || op == "r") {
      unsigned int value;
      std::cin >> value;
      list.removeValues(value);
    }
    else if (op == "show" || op == "s") {
      // output the queue
      std::cout << list << '\n';
    }
    else if (op == "exit" || op == "e") {
      return false;
    } 
    else if (op == "exitSafe" || op == "es") {
      return true;
    } 

    else {
      std::cout << "Unknown command: " << op << '\n';
    }
  }
}


int main () {
  allocations = 0;
  std::set_terminate(&on_terminate);
  std::cout << "enter commands, any of \n";
  std::cout << "ib <V> ";
  std::cout << "| ie <V> ";
  std::cout << "| remove <V> ";
  std::cout << "| show ";
  std::cout << "| exitSafe ";
  std::cout << "| exit \n";
  bool checkMemory = interactWithUser();

  if (checkMemory && allocations != 0) {
    std::cout << "Memory leak: Your program does not deallocate all "
                "allocated memory" << '\n';
    return 1;
  } else {
    return 0;
  }
}
