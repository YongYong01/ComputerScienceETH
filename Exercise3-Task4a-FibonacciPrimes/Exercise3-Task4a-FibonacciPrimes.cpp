// Write your solution here ...
#include <iostream>

int main(){
  int m;
  int a = 0;
  int b = 1;
  int f = 0;
  int count = 0;
  
  // input
  std::cout << "Print amount of primes in Fibonacci Sequence: ";
  std::cin >> m;
  
  // computation
  while(f <= m){
    if (f > 1 && f == 2){
      std::cout << f << std::endl;
      ++count;
    }
    else if(f >= 2){
      bool isPrime = true;
      // prime recognition
      for (int d = 2; d * d <= f; ++d){
        if (f%d == 0){
          isPrime = false;
          break;
        }
      }
      if (isPrime){
        // Output 1
        std::cout << f << std::endl;
        ++count;
      }
    }
    // Fibonacci Sequence
    f = a+b;
    a = b;
    b = f;
  }
  
  // Output 2
  std::cout << count;
  
  return 0;
}