/*
Man macht es über Iteratoren
*/

#include<iostream>
#include<vector>


int main(void){
  std::vector<int> vec;  
  for(auto i = vec.begin; i < vec.end; ++i){
    std::cout << *i << std::endl;
  }
}
