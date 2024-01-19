#include "solutions.h"

// Fill out each function with the appropriate expression

bool task1(unsigned int a, unsigned int b) { 
  // a greater than  b and the difference between a and b is smaller than 15.
  return a > b && (a-b) < 15; // Replace with your solution 
}


bool task2(unsigned int a) { 
  // a is an even natural number greater than 3.
  return a > 3 && a%2 == 0; // Replace with your solution
}


bool task3(unsigned int a, unsigned int b, unsigned int c) { 
  // a is at most 5 times greater than b (but can also be smaller than b) 
  // and at least 5 times greater than c.
  return ((b > a) || (a <= 5*b)) && (a >= 5*c); // Replace with your solution
}


bool task4(bool a, bool b, bool c) { 
  // Either a and b are both false or c is true, but not both.
  return ((a == false && b == false) || c == true) && !((a == false && b == false) && c == true); // Replace with your solution 
}


bool task5(bool a, unsigned int b) { 
  // a is false and b is zero.
  return (a == false) && (b == false); // Replace with your solution
}