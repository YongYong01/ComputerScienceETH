#include <iostream>
#include "DualNumber.h"

int main () {
  DualNumber dn1;
  DualNumber dn2;
  
  std::cout << "Enter the first dual number (both coefficients separated by a space): ";
  std::cin >> dn1;
  std::cout << "Enter the second dual number (both coefficients separated by a space): ";
  std::cin >> dn2;
  std::cout << "Enter the operation (+, -, *, all) : ";
  std::string operation;
  std::cin >> operation;

  if (operation == "+") {
    std::cout << (dn1 + dn2) << std::endl;
  } else if (operation == "-") {
    std::cout << (dn1 - dn2) << std::endl;
  } else if (operation == "*") {
    std::cout << (dn1 * dn2) << std::endl;
  } else {
    std::cout << dn1 << " + " << dn2 << " = " << (dn1 + dn2) << std::endl;
    std::cout << dn1 << " - " << dn2 << " = " << (dn1 - dn2) << std::endl;
    std::cout << dn1 << " * " << dn2 << " = " << (dn1 * dn2) << std::endl;
  }
}