/*
Die Idee ist die beiden ersten Fibonacci-Zahlen (alos die base cases sozusagen)
zu initialisieren und dann ab dem Index 2 über das erstellte Array mit der
größe des max_index+1 zu iterieren.
Da max_index selber auch im Array sein soll, ist es denke ich wichtig, dass
dass man die Größe max_index+1 wählt, um von 0 bis max_index im Array zu haben.

Beim Iterieren kann man nun einfach die beiden Zahlen am Index i-1 und i-2 zu
dem aktuellen Element an Index i addieren. Fibonacci-Zahlen eben :D
*/

//#### gefragte Funktion ####

#include<stdio.h>
#include<stdlib.h>

size_t *fibonacci_sequence(size_t max_index){
  size_t *fib = malloc((max_index+1) * sizeof(size_t)); //max_index+1 ist wichtig, da der max_index ja auch noch im Array sein soll
  fib[0] = 0;
  fib[1] = 1;
  for(size_t i = 2; i <= max_index; ++i){
    fib[i] = fib[i-2] + fib[i-1]; //da die ersten beiden fib Zahlen fest und schon initialisiert sind, kann man die neuen einfach immer jeweils aus den letzten beiden berechnen
  }
  return fib;
}

//#### main und Hilfsfunktionen ####

void show_sizet_array(size_t *arr, size_t len);
void show_fib_array(size_t *arr, size_t len);

int main(void){
  size_t max_index = 20;
  size_t *res = fibonacci_sequence(max_index);
  show_sizet_array(res, max_index);
  show_fib_array(res, max_index);
  free(res);
}

void show_sizet_array(size_t *arr, size_t len){
  printf("[ ");
  for(size_t i = 0; i <= len; ++i){
    printf("%ld ", arr[i]);
  }
  printf("]\n\n");
}

void show_fib_array(size_t *arr, size_t len){
  printf("#Index\tfib_num\n");
  for(size_t i = 0; i <= len; ++i){
    printf("%ld\t%ld\n",i, arr[i]);
  }
}
