#include<stdio.h>

typedef int *(*FuncType) (const char *, char *, int, double); //Funktion soll einen Pointer auf int zurückgeben

int func(FuncType f);

int *funcparam(const char *, char *, int, double); //muss in der "Bauart" nach dem obigen typedef dem Funktionstyp Functype entsprechen, weil func() nur solche Funktionen bekommen kann

