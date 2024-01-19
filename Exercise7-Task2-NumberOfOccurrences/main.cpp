#include <iostream>
#include <vector>

void vectorinput (std::vector<int>& input, int n) {
  input.push_back(n);
}

int numoccur (std::vector<int>& input, int lastdigit, int& count){
  for (unsigned int i = 0; i < input.size() - 1; ++i){
    if(input.at(i) == lastdigit){
      count++;
    }
  }
  return count;
}

// TODO
int main() {
  int count = 0;
  int lastdigit = 0;
  int n = 0;
  bool stop = false;
  std::vector<int> input;
  // TODO
  
  do{
    std::cin >> n;
    vectorinput(input, n);
    if(n < 0){
      stop = true;
      std::cin >> n;
      lastdigit = n;
      vectorinput(input, n);
    }
  }while(!stop);
  
  numoccur(input, lastdigit, count);
  std::cout << count;
  
  
  /*for (int i = 0; i < input.size(); i++){
    std::cout << input[i];
  }*/
  
  return 0;
}
