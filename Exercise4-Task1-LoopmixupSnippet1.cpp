#include <iostream>
#include "loop.h"

// Fill out the file with the required answers


/*

  Subtask 1: describe what the code snippet computes

  <First the Code asks for an input this input is saved in Variable n. 
  Afterwards if n is not 0 it loops the value while n is bigger than 0.
  In that loop it will multiply with f and gives f a new value. After this calculation
  the value n will be reduced by 1. It will repeat until n = 0. So the output is
  n factorial (n!) for example if I input 5 it will calculate 5*4*3*2*1 and outputs 120>

*/

/*

  Subtask 2: decide which of the other two kind of loops would fit better, and
  describe why.
  
  <A for loop would be better, because it's easier to read and more it's use 
  in this task is more appropriate, because we know the amount of iterations
  this code will run.>

*/


/*
  Subtask 3: update the function below by rewriting the snippet into the 
  loop you specified in (2)
*/

void loop(){
  
  unsigned int n;
  std::cin >> n;
  unsigned int f = 1;
  if (n != 0) {
    for (unsigned int i = 0; i < n; --n){
      f = f * n;
    }
    /*
    do {
      f = f * n;
      --n;
    } while (n > 0);
    */
  }
  
  std::cout << f << std::endl;
  
}

