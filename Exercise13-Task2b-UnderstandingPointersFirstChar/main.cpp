#include <iostream>
#include <string>
#include "first_char.h"

int main() {
    std::string s;
    char c;
    // read until newline
    std::getline( std::cin, s);
    // read character c
    std::cin >> c;
    const char* ptr = first_char(s.c_str(), c);
    if (ptr) {
      std::cout << ptr - s.c_str() << "\n";
    } else {
      std::cout << "Not found.\n";
    }
    return 0;
}