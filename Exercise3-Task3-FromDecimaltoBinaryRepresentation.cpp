// Write your solution here ...
#include <iostream>

int main(){
  unsigned int n;
  unsigned int r;
  

    // Input
    std::cout << "Please enter a number which will be converted to binary: ";
    std::cin >> n;

    unsigned int original = n;
    
    if (n == 0) {
        std::cout << "Binary representation: 0" << std::endl;
        return 0;
    }

    std::cout << "Binary representation: ";
    
    // Computation
    int count = 0;
    
    while (n > 0) {
        r = n % 2;
        n /= 2;
        
        ++count;
    }
    
    // Get highest power of 2
    unsigned int power = 1;
    for (int i = 1; i < count; i++) {
        power *= 2;
    }

    // Output
    while (power > 0) {
        r = original / power % 2;
        power /= 2;
        std::cout << r;
    }

    return 0;
}