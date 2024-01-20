#include "run_length.h"

void start(int value){
  if (value == 0){
    std::cout << "1 ";
    return;
  }
  if (value == 1){
    std::cout << "0 ";
    return;
  }
  else{
    std::cout << "not valid";
    return;
  }
}

void end(int value){
  if (value == 0){
    std::cout << "-1";
    return;
  }
  if (value == 1){
    std::cout << " -1";
    return;
  }
  else{
    std::cout << "not valid";
    return;
  }
}

void decode()
{
  // implement decode function
  // NOTE: do not printout new line (i.e., std::endl or '\n')
  
  int number;
  int amount;
  start(1);
  while (true) {
    std::cin >> number;
    if (number == -1) {
      end(1);
      break;
    }

    // Check
    if (!(number >= 0 && number <= 255)) {
      std::cout << "error";
      return;
    }

    amount = number;

    std::cin >> number;

    // Check
    if (!(number >= 0 && number <= 255)) {
      std::cout << "error";
      return;
    }

    // Output
    for (int i = 0; i < amount; ++i) {
      std::cout << number << " ";
    }
  }

  //std::cout << "-1";
}


void encode()
{
  // implement encode function
  // NOTE: do not printout new line (i.e., std::endl or '\n')
  // Output the start of the sequence
  start(0);

  int prev_value;
  int run_length = 0;

  int value;
  while (std::cin >> value) {
    // number to big
      if (value < 0 || value > 255) {
          break;
      }

      if (run_length == 0) {
          run_length = 1;
          prev_value = value;
      } else if (value != prev_value || run_length == 255) {
          
          std::cout << run_length << " " << prev_value << " ";
          run_length = 1;
          prev_value = value;
      } else {
          // Value matches and continue
          run_length++;
      }
  }

  // Output
  if (run_length > 0) {
      std::cout << run_length << " " << prev_value << " ";
  }

  // Output end
  if (value != -1) {
      std::cout << "error";
  } else {
      end(0);
  }
}