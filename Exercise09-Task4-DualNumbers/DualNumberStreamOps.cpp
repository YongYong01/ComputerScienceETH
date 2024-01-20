#include "DualNumber.h"

#include <cmath>

std::ostream& operator<<(std::ostream& out, const DualNumber& dn) {
  return out << "(" << dn.a 
             << ((dn.b < 0.0) ? " - " : " + ") 
             << "e*" << std::abs(dn.b) << ")";
}

std::istream& operator>>(std::istream& in, DualNumber& dn) {
  return in >> std::skipws >> dn.a >> std::ws >> dn.b;
}