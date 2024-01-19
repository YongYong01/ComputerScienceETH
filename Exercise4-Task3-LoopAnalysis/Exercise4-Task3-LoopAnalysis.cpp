#include <iostream>
#include "loop.h"

// Fill out the file with the required answers


/*

  Subtask 1: Describe the output of the program as a function of its input n.

  <The program asks for an input n. The input n gives the amount of times the code should run
  it first looks if the value is bigger than 0. It sets a bool e to true. Afterwards it runs
  and looks if n is equal to 0. If not it will multiply x with 2 and in the last if statement
  it will decrease it by 1. It runs as long n is not 0. So for example the input 3 will deliver
  1*2*2*2=8. So 2^3.>

*/

/*

  Subtask 2: For which values of n do you expect a correct output x? Explain why.

  <It will display for all positive integers. 
  n=0 the loop will not execute, because n > 0.
  n=1 the loop will execute once multiplying x by 2 and the nterminate. Therefore the
  programm terminates for n = 1
  T>

*/


/*

  Subtask 3: Show that this program terminates for all values of n found in (2).
  
  <he code will terminate for every k + 1
  n = k + 1 and it will run as long as n > 0. k + 1 > 0. With each iteration the
  n will decrease by 1.
  n = k so therefore for n = k + 1 and it will terminate for after the delivered input.>
  
*/

/*
  Subtask 4: Provide a more elegant implementation of this function using 
  another type of loop.
*/

void loop(){
  
  unsigned int n;
  std::cin >> n;
  
  unsigned int x = 1;
  
  for (; n > 0; --n) {
        x *= 2;
    }
  /*
  if (n > 0) {
    bool e = true;
    do {
      if (--n == 0) { 
        e = false;
      }
      x *= 2;
    } while (e);
  }
  */
  std::cout << x << std::endl;
  
}

