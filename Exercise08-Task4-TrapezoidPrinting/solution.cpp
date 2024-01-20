#include <assert.h>

#include <iostream>

#include "solution.h"

void print_row(unsigned int n_bricks, unsigned int offset_left) {
  // print spaces for offset
  for (unsigned int i = 0; i < offset_left; ++i) {
    std::cout << " ";
  }

  // print bricks
  for (unsigned int i = 0; i < n_bricks; ++i) {
    if (i != 0) {
      std::cout << " ";
    }
    std::cout << "0";
  }
  std::cout << std::endl;
}

void print_trapezoid(unsigned int base_width, unsigned int height,
                     unsigned int offset_left, bool upsidedown) {
  assert(base_width >= height);

  // TODO: Subtask 1
  if (height == 0){
    return;
  }
  else{
    if(upsidedown == false){
      print_trapezoid(base_width - 1, height - 1, offset_left + 1, false);
      print_row(base_width, offset_left);
    }
    else{
      print_row(base_width, offset_left);
      print_trapezoid(base_width - 1, height - 1, offset_left + 1, true);
    }
  }
}

void print_diamond(unsigned int center_width) {
  // TODO: Subtask 2
  // upper
  for (unsigned int i = 1; i <= center_width; ++i) {
    print_row(i, center_width - i);
  }

  // lower
  for (unsigned int i = center_width - 1; i > 0; --i) {
    print_row(i, center_width - i);
  }
}

void print_hourglass(unsigned int base_width) {
  // TODO: Subtask 3
  // lower
  for (unsigned int i = base_width; i > 0; --i) {
    print_row(i, base_width - i);
  }
  // upper
  for (unsigned int i = 1; i <= base_width; ++i) {
    print_row(i, base_width - i);
  }

  
}