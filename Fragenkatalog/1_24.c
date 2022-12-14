/*
Die Idee ist die Anzahl der Elemente mit Hilfe von sizeof() zu bestimmen.
Anzahl der Elemente = sizeof(ckeywords)/sizeof(char *).
Damit hat man eine Anzahl über die man iterieren kann. Mit jeder Iteration
bekommt man den Anfang eines neuen Eintrags (eines neuen Wortes).
Diese sind jeweils \0 terminiert. Das heißt man kann über dieses einzelne Wort
bis \0 interieren und jedes mal einen counter hochzählen.
Der counter zählt somit die Summe der Länger aller Wörter.
Erwartetes Ergebnis:
Anzahl Einträge: 32
Summe aller Längen: 166
*/

#include<stdio.h>

int main(void){
  char *ckeywords[] // das hier ist ein array mit pointern auf char's.
  = {"auto", "double", "int", "struct", "break", "else", "long",
      "switch", "case", "enum", "register", "typedef", "char",
      "extern", "return", "union", "const", "float", "short",
      "unsigned", "continue", "for", "signed", "void", "default",
      "goto", "sizeof", "volatile", "do", "if", "static",
      "while"};

  size_t count = 0;

  size_t n_elems = sizeof(ckeywords)/sizeof(char *);
  for(size_t i = 0; i < n_elems; i++){
    for(size_t j = 0; ckeywords[i][j] != '\0'; j++){ //weil ckeywords ein array ist, das auf arrays zeigt, kann man so auf die einzelnen Buchstaben zugreifen
      count++;
    }
  }

  printf("Anzahl der Einträge = %ld\n", n_elems);
  printf("Summe der Länger aller Einträge = %ld\n", count);
}
