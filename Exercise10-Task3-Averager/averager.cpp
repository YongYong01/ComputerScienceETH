#include "averager.h"

// Write implementation of methods of class Averager here

void Averager::add_value(double value){
  sum += value;
  ++count;
  return;
}

double Averager::get_average(){
  if(count == 0){
    return 0.0;
  }
  double average;
  average = sum / count;
  return average;
}

void Averager::reset(){
  sum = 0;
  count = 0;
}