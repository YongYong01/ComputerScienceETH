//write your solution here
#include<iostream>

int main(){
  double m = 0.0;
  double sum = 0.0;
  int power = 1;
  
  // computation
  
  do{
    
    std::cout << "Give input for approximation of Pi: ";
    std::cin >> m;
    if(m < 0){
      std::cout << "Invalid input. PLease enter a positive integer m >= 0" << std::endl;
    }
    else{
      break;
    }
  }while (true);
 
  
  for(int i = 0; i < m; ++i){
    //std::cout << i << std::endl;
    sum += power / (2.0 * i + 1.0);
    power *= -1;
  } 

  std::cout << 4 * sum;
  
  return 0;
}