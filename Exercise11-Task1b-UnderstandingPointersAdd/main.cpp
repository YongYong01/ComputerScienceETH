#include <iostream>
#include "add.h"

int main() {
  int a, b, res;
  std:: cin >> a >> b;
  add(&res, &a, &b);
  std::cout << res << "\n";
  return 0;
}