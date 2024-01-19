#include <iostream>
#include <vector>
#include <cassert>
#include "averager.h"

int main() {
  
  unsigned int num_averagers;
  std::cin >> num_averagers;
  
  std::vector<Averager> averagers = std::vector<Averager>(num_averagers);
  std::string operation;
  unsigned int averager_id;

  // query for new operations until end of stream is reached
  while (std::cin >> operation) {
    //get the averager id
    std::cin >> averager_id;
    assert(averager_id < num_averagers);
    if (operation == "add") {
      double value;
      std::cin >> value;
      averagers.at(averager_id).add_value(value);
    } else if (operation == "get") {
      std::cout << averagers.at(averager_id).get_average() << " ";
    } else if (operation == "reset") {
      averagers.at(averager_id).reset();
    }
  }

  return 0;
}
