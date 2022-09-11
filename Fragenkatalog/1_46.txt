/*
Die Idee ist die Stelle im Array zu suchen, an welcher das Element das erste 
mal größer ist, als das Element das eingefügt werden soll.

Bis zu dieser Stelle wird jetzt vom Ende des Arrays angefangen
alles um eine Stelle nach hinten verschoben.
Das ist praktisch, weil an der letzten Stelle des Arrays "nichts" steht.
Dieses "nichts" ist hier mit 0 initialisiert, könnte aber natürlich alles 
mögliche sein.

Dieses "nichts" steht dann am Ende an der Stelle, an welcher dann das neue
Element eingefügt wird.

Über eine Assertion wird nochmals sichergestellt, dass die pointer dann wirklich
auf die gleiche Stelle im Array zeigen. (das ist aber eigentlich nicht nötig, da
der Logik nach das immer gegeben ist)

*/

//#### gefragte Funktion ####
#include<stdio.h>
#include<assert.h>


void insert_sorted_array(int *arr, size_t len, int elem){
  int *ptr = arr;
  while(*ptr < elem){
    ptr++;
  }
  int *rev_ptr = arr+len; //fängt am Ende an (inlusive der zusätzlichen Stelle); len bezieht sich nur auf Anzahl der Elemente
  while(rev_ptr != ptr){
    int temp = *rev_ptr;
    *rev_ptr = *(rev_ptr-1);
    *(rev_ptr-1) = temp;
    rev_ptr--;
  }
  assert(ptr == rev_ptr);
  *ptr = elem;
}

//#### main und Hilfsfunktionen ####

void show_arr(int *arr, size_t len);

int main(void){
  int arr[] = {19, 27, 33, 39, 55, 76, 78, 79, 84, 91, 0}; // ich habe hier den Extraeintrag/den Extraplatz mit 0 initialisiert
  size_t len = 10;
  int elem_add = 42;

  insert_sorted_array(arr, len, elem_add);
  show_arr(arr, len+1);

}

void show_arr(int *arr, size_t len){
  printf("[ ");
  for(size_t i = 0; i < len; ++i){
    printf("%d ", arr[i]);
  }
  printf("]\n\n");
}
