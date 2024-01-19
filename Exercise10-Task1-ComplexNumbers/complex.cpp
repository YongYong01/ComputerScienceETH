#include "complex.h"

bool read_input(std::istream& in, Complex& a){
  unsigned char c;
   if(!(in >> c) || c != '['
      || !(in >> a.re)
      || !(in >> c)
      || c != ','
      || !(in >> a.im)
      /* TODO: Finish implementation */
      || !(in >> c) || c != ']')
      return false;
    else 
      return true;
}

std::istream& operator>>(std::istream& in, Complex& a) {
    if(!read_input(in, a)) {
        in.setstate(std::ios::failbit);
    }
    return in;
}


// TODO: Write all the operators and functions implementations here.
std::ostream& operator<<(std::ostream& os, const Complex& a){
    return os << '[' << a.re << ',' << a.im << ']';
}

Complex operator+(const Complex& a, const Complex& b){
  Complex res;
  res.re = a.re + b.re;
  res.im = a.im + b.im;
  return res;
}

Complex operator-(const Complex& a, const Complex& b){
  Complex res;
  res.re = a.re - b.re;
  res.im = a.im - b.im;
  return res;
}

Complex operator*(const Complex& a, const Complex& b){
  Complex res;
  res.re = a.re * b.re - a.im * b.im;
  res.im = a.re * b.im + a.im * b.re;
  return res;
}

Complex operator/(const Complex& a, const Complex& b){
  Complex res;
  double divisor = b.re * b.re + b.im * b.im;
  res.re = (a.re * b.re + a.im * b.im)/divisor;
  res.im = (a.im * b.re - a.re * b.im)/divisor;
  return res;
}

// negation
Complex operator-(const Complex& a){
  Complex res;
  res.re = -a.re;
  res.im = -a.im;
  return res;
}

bool operator==(const Complex& a, const Complex& b){
  double tolerance = 1e-6;
  return std::abs(a.re - b.re) < tolerance && std::abs(a.im - b.im) < tolerance;
}

bool operator!=(const Complex& a, const Complex& b){
  return !(a == b);
}