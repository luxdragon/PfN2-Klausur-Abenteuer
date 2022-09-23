#include <stdio.h>
#include <stdlib.h> //für EXIT_FAILURE und EXIT_SUCCESS

typedef int *(*FuncType) (const char *, char *, int, double);
//ein Zeiger auf eine Funktion, die einen Zeiger/Array liefert. Wieso habe ich nicht Theologie gewählt?
int func(FuncType f);

int *funcparam(const char *a, char *b, int c, double d); //liefert einen Zeiger


return func(funcparam) == -1 ? EXIT_FAILURE : EXIT_SUCCESS;
