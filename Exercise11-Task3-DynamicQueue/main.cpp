#include <iostream>
#include "queue.h"


/////////////////////////////////////////////////////////////////////////////
// TEST MAIN FUNCTION
/////////////////////////////////////////////////////////////////////////////

// The following main function implements the testing harness.
// Note: We use *(ref). as the operator -> is not introduced in the lecture.
int main() {
  Queue q;
  q.check_invariant();

  // parse and process the test data until the end marker occurs.
  // The format of the test data is:
  // <function> <parameter>
  // where <parameter> is optional and specific to the function.
  while (std::cin.good()) {

    // get <function>, exit if end marker occurs
    std::string function;
    std::cin >> function;
    if (function == "end") {
      break;
    }

    if (function == "dequeue") {
      std::cout << q.dequeue() << "\n";

    } else if (function == "enqueue") {
      int value; // parameter "value"
      std::cin >> value;
      q.enqueue(value);

    } else if (function == "is_empty") {
      std::cout << q.is_empty() << "\n";

    } else if (function == "print") {
      q.print();
      std::cout << "\n";

    } else if (function == "print_reverse") {
      q.print_reverse();
      std::cout << "\n";

    } else {
      std::cout << "unknown function: " << function << "\n";
      break;
    }
    
    q.check_invariant();
      
  }
  return 0;
}
