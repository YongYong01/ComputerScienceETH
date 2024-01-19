//write your solution here
//write your solution here
#include<iostream>

int main(){
  double m = 0.0;
  double sum = 0.0;
  double pi1 = 1.0;
  double pi2 = 1.0;
  double temp = 0.0;
  
  // computation
  
  do{
    
    std::cout << "Give input for approximation of Pi m(m >= 1): ";
    std::cin >> m;
    if(m < 1){
      std::cout << "Invalid input. PLease enter a positive integer m >= 0" << std::endl;
    }
    else{
      break;
    }
  }while (true);
 
  
  for(int i = 1; i < m; ++i){
    //std::cout << i << pi << std::endl;
    
    temp = ((2 * i) + 1);
    
    pi1 *= i;
    pi2 *= temp;
    
    sum += pi1 / pi2;
  } 

  std::cout << 2 * (1 + sum);
  
  return 0;
}