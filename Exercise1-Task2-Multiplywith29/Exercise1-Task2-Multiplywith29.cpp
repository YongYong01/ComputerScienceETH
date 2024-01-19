// TODO: Implement.
#include <iostream>

int main() {
  
  int a;
  
  std::cout << "Please enter a integer (var a) for the multiplication of 29*a\n";
  std::cin >> a;
  
  // Calculation with binary
  int N1 = a;
  int N2 = N1 + N1;
  int N4 = N2 + N2;
  int N8 = N4 + N4;
  int N16 = N8 + N8;
  
  int result = N16 + N8 + N4 + N1;
  
  
  std::cout << result;
  return 0;
}