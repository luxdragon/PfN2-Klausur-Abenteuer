/*
Bei dieser Aufgabe muss man beachten, dass die Eingabe die Form
"./mini_add '18 + 24'" haben soll. Die ''-Anführungszeichen sorgen dafür, dass
der Ausdruck darin als ein einzelner String übernommen wird. Also steht
18 + 24 als string in argv[1].
*/

#include<stdio.h>
#include<stdlib.h>

void main(int argc, char *argv[]){
  int x,y;

  if(argc != 2 || sscanf(argv[1], "%d + %d", &x, &y) != 2){ //Prüfen ob die Eingabe die Richtige Form hat und gleichzeitiges einlesen
    fprintf(stderr, "%s: Must receive input in form 'x + y' as one string.\n", argv[0]); // printen der Fehlermeldung nach stderr
    exit(EXIT_FAILURE);
  }
  else{
    printf("%d + %d = %d\n",x, y, x + y);// Ausgabe in der gewünschten Form erzeugen.
  }
}
