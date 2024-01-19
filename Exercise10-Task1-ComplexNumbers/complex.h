#pragma once

#include <iostream>
#include <cmath>

// TODO: Write structure declaration/operators forward declarations here.
struct Complex{
  double re;
  double im;
};

// ...

// reads a complex number from input
// returns a boolean to indicate whether the input was valid or not
bool read_input(std::istream& in, Complex& a);

// input operator
// sets fail bit if input is not a valid complex number

// Input and Output
std::istream& operator>>(std::istream& in, Complex& a);
std::ostream& operator<<(std::ostream& os, const Complex& a);

// arithmetic operations
Complex operator+(const Complex& a, const Complex& b);
Complex operator-(const Complex& a, const Complex& b);
Complex operator*(const Complex& a, const Complex& b);
Complex operator/(const Complex& a, const Complex& b);

// negation
Complex operator-(const Complex& a);

// equal and not equal
bool operator==(const Complex& a, const Complex& b);
bool operator!=(const Complex& a, const Complex& b);