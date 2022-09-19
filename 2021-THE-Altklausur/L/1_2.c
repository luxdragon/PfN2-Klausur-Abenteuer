//Idee ist im C-Skript Seite 346-348
//---------Dateianfang von list.c
include <stdio.h>
include "bintree.h"

typedef struct{
  void *left;
  void *right;
  int data;
}Bintree; //apropos Strukturen, wie funktioniert Padding mit Zeigern?

//Implementierungen von Funktionen, z.B.

void printer(int zahl) {
  printf("Deine Zahl ist: %d", zahl);
}
/* ---------Dateiende von list.c

---------Dateianfang von list.h */

include <stdio.h>

typedef struct Bintree;
//hier würde man dann die Funktionen benutzen, z.B.

printer(43);

/*---------Dateiende von list.h */

//mein Verständnis von Data hiding in C ist immer noch schwammig :/
