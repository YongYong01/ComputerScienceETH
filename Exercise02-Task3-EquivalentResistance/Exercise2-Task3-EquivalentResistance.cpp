// Please write your solution here.
#include <iostream>
int main() {
  unsigned int R1;
  unsigned int R2;
  unsigned int R3;
  unsigned int R4;
  
  // input
  std::cout << "Please give input for R1: ";
  std::cin >> R1;
  std::cout << "Please give input for R2: ";
  std::cin >> R2;
  std::cout << "Please give input for R3: ";
  std::cin >> R3;
  std::cout << "Please give input for R4: ";
  std::cin >> R4;
  
  // computation
  unsigned int R12 = R1 + R2;
  unsigned int R34 = R3 + R4;
  unsigned int deno = R12 * R34;
  unsigned int nume = R34 + R12;
  unsigned int mod = (deno%nume)*2/nume;
  unsigned int R = deno/nume;
  
  // for debugging
  std::cout << "R12: " << R12 << " R34: " << R34 << " deno: " << deno << " nume: " << nume << " mod: " << mod << " R: " << R << " ";
  
  // check for comma
  if (mod >= 1){
    std::cout << ++R;
  }
  else{
    std::cout << R;
  }
  return 0;
}