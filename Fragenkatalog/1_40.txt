/*
man muss beachten, dass die jeweilige Partialsumme den Wert im Array
an der aktuellen Stelle überschreiben soll.

Die Idee ist, dass man ab der Stelle 1 im Array mit der Iteration anfängt und
immer zum iten Element das i-1te Element addiert. Damit erwischt man am Ende
alle Werte und bekommt ein Array mit allen Partialsummen aus dem Array was im
Vorgang überschrieben wurde.
*/

//#### gefragte Funktion ####

#include<stdio.h>

static void partialsums(int *a, size_t n){ //endlich ist der void nicht mehr so chaotisch, so eine Erleichterung. Oder kann mir jemand sagen was static void ist?
  for(size_t i = 1; i<n; ++i){
    a[i] += a[i-1];
  }
}


//#### main und Hilfsfunktionen ####

void show_arr(int *arr, size_t n);

int main(void){
  int arr[] = {0,1,2,3,4,5,6,7,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
  size_t n = 25;
  partialsums(arr, n);
  show_arr(arr, n);
}

void show_arr(int *arr, size_t len){
  printf("[ ");
  for(size_t i = 0; i<len; ++i){
    printf("%d ", arr[i]);
  }
  printf("]\n\n");
}

//Tutor fragen: wie funktioniert static in C und in C++?
