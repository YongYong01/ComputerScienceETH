#include "DualNumber.h"

DualNumber operator+(const DualNumber& dn1, const DualNumber& dn2) {
  // TODO: Task 1
  DualNumber resultsum;
  resultsum.a = dn1.a + dn2.a;
  resultsum.b = dn1.b + dn2.b;
  return resultsum;
}

DualNumber operator-(const DualNumber& dn1, const DualNumber& dn2) {
  // TODO: Task 2
  DualNumber resultdif;
  resultdif.a = dn1.a - dn2.a;
  resultdif.b = (dn1.b - dn2.b);
  return resultdif;
}

DualNumber operator*(const DualNumber& dn1, const DualNumber& dn2) {
  // TODO: Task 3
  DualNumber resultmult;
  resultmult.a = dn1.a * dn2.a;
  resultmult.b = (dn1.a * dn2.b) + (dn1.b * dn2.a);
  return resultmult;
}