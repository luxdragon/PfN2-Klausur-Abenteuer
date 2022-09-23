/*
Eine von den cpp Aufgaben vom Fragebogen
*/
#include<iostream>

template<typename T>
void swap(T &a, T &b){ //muss Adressen bekommen
  T temp = a;
  a = b;
  b = temp;
}

int main(void){
  int a = 5;
  int b = 10;

  swap(a,b); //swap kann mit den Variablen selber aufgerufen werden, da die Adressen da automatisch mit dabei sind
  std::cout << a << " " << b << std::endl; // man sieht in a steht jetzt 10 und in b steht 5
}
