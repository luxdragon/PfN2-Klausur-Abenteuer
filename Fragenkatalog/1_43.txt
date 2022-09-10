/*
Es soll die Funktion qsort genutzt werden, welche bereits in stdlib.h
existiert und deren Vorwärts-Deklaration gegeben ist.

Wie man aus der Deklaration erkennen kann, geht es in der Aufgabe vor allem
um die Implementierung der compare Funktion

Was die compare-Funktion leisten muss, also wie sie funktioniert, ließt man
im Zweifelsfall besser nochmal nach, z.b. hier:
https://www.geeksforgeeks.org/comparator-function-of-qsort-in-c/

in short:
<0 The element pointed by p1 goes before the element pointed by p2
0  The element pointed by p1 is equivalent to the element pointed by p2
>0 The element pointed by p1 goes after the element pointed by p2

*/

//#### gefragte Funktionen ####

#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int first;
  unsigned long second;
} IntUlongPair;

int compare(const void *a, const void *b){ //void pointer sind wildcards und können in pointer jedes Typs konvertiert werden, was im folgenden getan wird
  const IntUlongPair *x = a;
  const IntUlongPair *y = b;
  /*Das hier ist der geforderte Fall, dass die structs erstmal aufsteigend nach den int's sortiert werden soll*/
  if((x->first - y->first) < 0){ //wenn das der Fall true, dann ist das Element auf das a zeigt kleiner als das Element auf das b zeigt. Nach der Funktion von qsort, wird dann aufsteigend sortiert
    return -1;
  }
  else if((x->first - y->first) > 0){ // diese weitere Fallunterscheidung ist genau genommen unnötig, steht hier aber trotzdem für besseres Verständnis. Sie ist unnötig, weil in allen anderen Fällen als oben absteigend sortiert werden soll.
    return 1;
  }
  /* In allen anderen Fällen ist gefordert, dass absteigend (nach den unsigned long's) sortiert werden soll */
  else{
    return 1;
  }
}

void sort_int_ulong_pairs(IntUlongPair *tab, size_t len){
  qsort(tab, len, sizeof(IntUlongPair), compare); 
}


//#### main und Hilfsfunktionen ####

void print_sorted_structs(IntUlongPair *arr, size_t len);
void print_struct(IntUlongPair *str);

int main(void){
  IntUlongPair struct1;
  struct1.first = 3;
  struct1.second = 3000;
  //print_struct(&struct1);

  IntUlongPair struct2;
  struct2.first = 42;
  struct2.second = 1337;
  //print_struct(&struct2);


  IntUlongPair struct3;
  struct3.first = 1;
  struct3.second = 5;
  //print_struct(&struct3);

  IntUlongPair struct4;
  struct4.first = 1;
  struct4.second = 9696;
  //print_struct(&struct4);

  IntUlongPair struct5;
  struct5.first = 5000;
  struct5.second = 4200;
  //print_struct(&struct5);

  IntUlongPair struct6;
  struct6.first = -3;
  struct6.second = 1;
  //print_struct(&struct6);

  IntUlongPair arr[6] = {struct1, struct2, struct3, struct4, struct5, struct6}; //intialisierung eines arrays das die structs enthält
  size_t len = 6;
  sort_int_ulong_pairs(arr, len);
  print_sorted_structs(arr, len);
}

void print_struct(IntUlongPair *s){
  printf("first: %d\n",s->first);
  printf("second: %ld\n\n",s->second);
}


void print_sorted_structs(IntUlongPair *arr, size_t len){
  printf("#Index\tfirst\tsecond\n");
  for(size_t i = 0; i < len; ++i){
    printf("%ld\t%d\t%lu\n", i, arr[i].first, arr[i].second);
  }
}
