#include<iostream>

//### gefragte Funktion

template<typename T>
T getmin(T a, T b){
  return a < b ? a : b; //sehr fancy :)
}


//#### main ####

int main(void){
  int c = 3;
  int d = 4;
  float e = 5.0;
  float f = 6.0;
  double h = 3000.0;
  double i = 2500.0;

  std::cout << getmin(c,d) << std::endl;
  std::cout << getmin(e,f) << std::endl;
  std::cout << getmin(h,i) << std::endl;
}
