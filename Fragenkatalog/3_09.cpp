/*

Die Idee ist die beiden Variablen zu vertauschen, indem man den jewils anderen
in den Speicherbereich des ersten schreibt.

Dafür braucht man eine zusätzliche Variable in welcher einer der Werte
zwischengespeichert wird

*/

//#### gefragte Funktion ####

#include<iostream>

template<typename T>
void swap(T &a, T &b){ //sind das Referenzen und wie unterscheiden sie sich von Zeigern? Den Tutor fragen.
  T temp = a;
  a = b;
  b = temp;
}



//#### main ####

int main(void){
  float a = 15.0;
  float b = 42.1337;

  swap(a,b);

  std::cout << a << std::endl;
  std::cout << b << std::endl;

}
