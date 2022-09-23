#include <iostream>
template<typename T>

void swap(T &a, T &b){
  T temp = a;
  a = b;
  b = temp;
}

int main(void) {
  int a = 15;
  int b = 20;
  swap(a,b);
  std::cout << a << std::endl << b << std::endl;
  return 0;
}
