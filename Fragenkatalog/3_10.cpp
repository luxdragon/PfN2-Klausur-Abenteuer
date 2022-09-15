/*
https://en.wikipedia.org/wiki/Euclidean_distance

*/

//#### gefragte Funktion ####

#include<iostream>
#include<cmath>


template<typename T>
T distance_template(T x1, T y1, T x2, T y2){
  return sqrt(((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1)));
}



//#### main #####

int main(void){
  double x1 = 2.42;
  double y1 = 4.1337;

  double x2 = 7.42;
  double y2 = 15.1337;


  std::cout << distance_template(x1, y1, x2, y2) << std::endl;
}
