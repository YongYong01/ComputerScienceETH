#include <iostream>
#include "loop.h"

// Fill out the file with the required answers


/*

  Subtask 1: describe what the code snippet computes

  <The code asks for the user for 2 inputs. those two inputs will be counted together
  and displayed in the console. Afterwards it will ask if it will want to be run again.
  if 0 is pressed it will break the loop and stop the programm. If any other number than 0 will be entered
  (even if it says 0/1) it will stop the code, because it will only check, if the value is 0 to break the programm.>

*/

/*

  Subtask 2: decide which of the other two kind of loops would fit better, and
  describe why.

  
  <I would use a do-while loop, because it should first run the code and then
  check the condition at the end, if it wants to be run again.>

*/


/*
  Subtask 3: update the function below by rewriting the snippet into the 
  loop you specified in (2).
  Note: print the control message "Again? (0/1)" using the same format used
  in the snippet.
*/

void loop(){
  int again;
  do{
    int i1, i2;
    std::cin >> i1 >> i2;
    std::cout << i1 + i2 << "\n";
    std::cout << "Again? (0/1)\n";
    std::cin >> again;
  } while(again == 1);
  
  /*
  for (;;) {
    int i1, i2;
    std::cin >> i1 >> i2;
    std::cout << i1 + i2 << "\n";
    int again;
    std::cout << "Again? (0/1)\n";
    std::cin >> again;
    if (again == 0) break;
  }
  */
}