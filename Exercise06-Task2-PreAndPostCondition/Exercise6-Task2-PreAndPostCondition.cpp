// PRE:  (n != 0) || (x != 0)
// POST: returns n^x
unsigned int f1(unsigned int n, unsigned int x) {
  unsigned int res = 1;
  for (; x > 0; x--) {
    res *= n;
  }
  return res;
}

// PRE:  n != 0
// POST: returns number of digits of n
unsigned int f2(unsigned int n) {
  unsigned int i = 0;
  while (n > 0) {
    n = n / 10;
    ++i;
  }
  return i;
}

// PRE:  n > 1
// POST: returns true if n is a prime number, else false
bool f3(unsigned int n) {
  unsigned int i = 2;
  for (; n % i != 0; ++i);
  return n == i;
}

// PRE:  n must be a perfect square (multiplication of two identical integers)
// POST: returns (non-negative) square root of n
unsigned int f4(unsigned int n) {
  unsigned int i = 0;
  while (i * i != n) {
    ++i;
  }
  return i;
}
