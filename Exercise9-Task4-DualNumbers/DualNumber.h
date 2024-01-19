#pragma once

#include <iostream>

struct DualNumber {
  double a;
  double b;
};


// Return the dual number corresponding to the sum dn1 + dn2
DualNumber operator+(const DualNumber& dn1, const DualNumber& dn2);

// Return the dual number corresponding to the difference dn1 - dn2
DualNumber operator-(const DualNumber& dn1, const DualNumber& dn2);

// Return the dual number corresponding to the product dn1 * dn2
DualNumber operator*(const DualNumber& dn1, const DualNumber& dn2);

// Stream operators. You don't need to understand these.
std::ostream& operator<<(std::ostream& out, const DualNumber& dn);
std::istream& operator>>(std::istream& in, DualNumber& dn);
