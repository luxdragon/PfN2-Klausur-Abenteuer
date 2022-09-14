/*
Hier ist die memoization Technik gefragt, die auch als peer taching Aufgabe
und in einer Übungsaufgabe dran kam.

numerical.pdf Folie 92
Die komplette Lösung für diese Aufgabe steht im Prinzip auf F.93
Die Übungsaufgabe war 9.3 Teil 2; subset sum problem in c++

Die Idee ist einfach gesagt, dass man sich über eine geeignete Daten-Struktur
merkt, ob ein Wert schon einmal berechnet wurde. Dann können alle Operationen
die eigentlich zu diesem Wert führen würden übersprungen werden.

So wie das hier implementiert ist, bedeutet das, dass jedes n und jedes k 
eine Instanz der struct Definedvalue sein muss.

*/

//#### gefragte Lösung #### 

#include<stdio.h>
#include<stdbool.h> //für Datentyp bool

typedef struct {
  size_t value;
  bool defined;
} Definedvalue;

size_t evalbinom_memo(Definedvalue **tab, size_t n, size_t k){
  if(k == 0 || n == k){
    return 1;
  }
  if(n == 0){
    return 0;
  }
  if(!tab[n-1][k-1].defined){ // der Fall, dass der vorherige Binomialkoeffizient noch nicht berechnet wurde => dann muss er natürlich berechnet werden?
    tab[n-1][k-1].value = evalbinom_memo(tab, n-1, k-1);
    tab[n-1][k-1].defined = true;
  }
  if(!tab[n-1][k].defined){
    tab[n-1][k].value = evalbinom_memo(tab, n-1, k);
    tab[n-1][k].defined = true;
  }
  return safe_add(tab[n-1][k-1].value, tab[n-1][k].value); // safe add ist Addition die sicherstellt, dass kein overflow auftritt
}
