#include <string>
#include <iostream>
#include "complex.h"

int main() {
    // input operation and operands
    std::string op;
    Complex c1, c2, res;
    bool bres;
    std::cin >> op >> c1;
    
    if (op != "inout" && op != "neg") {
        std::cin >> c2;
    }
    
    // check for valid input
    if (std::cin.fail())
      std::cout << "Invalid input!" << std::endl;
    else{
    
      // execute operation
      if      (op == "add")   { res = c1 + c2;    }
      else if (op == "sub")   { res = c1 - c2;    }
      else if (op == "mul")   { res = c1 * c2;    }
      else if (op == "div")   { res = c1 / c2;    }
      else if (op == "eq")    { bres = (c1 == c2); }
      else if (op == "ne")    { bres = (c1 != c2); }
      else if (op == "inout") { res = c1;         }
      else if (op == "neg")   { res = -c1;        }
      
      if      (op == "add")   { std::cout << c1 << " + " << c2;    }
      else if (op == "sub")   { std::cout << c1 << " - " << c2;    }
      else if (op == "mul")   { std::cout << c1 << " * " << c2;    }
      else if (op == "div")   { std::cout << c1 << " / " << c2;    }
      else if (op == "eq")    { std::cout << c1 << " == " << c2;   }
      else if (op == "ne")    { std::cout << c1 << " != " << c2;   }
      else if (op == "inout") { std::cout << c1;                   }
      else if (op == "neg")   { std::cout << " - " << c1;          }
      
      std::cout << " evaluates to ";
      if (op == "eq" || op == "ne")
        std::cout << bres << "\n";
      else
        std::cout << res << "\n";
    }
      
    return 0;
}