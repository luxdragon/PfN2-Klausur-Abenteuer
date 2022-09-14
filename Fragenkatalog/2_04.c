/*
Es soll die in der Vorlesung vorgestellte Technik verwendet werden

F. 86 numerical slides


*/


#include<stdio.h>
#include<stdlib.h>
#include<limits.h> //für MAKRO ULONG_MAX

unsigned long safe_add(unsigned long a, unsigned long b){
  if(a == 0){ // eigentlich optional
    return b;
  }
  if(b == 0){ // eigentlich optional
    return a;
  }
  if(a > ULONG_MAX - b){
    fprintf(stderr, "%s overflow(%lu + %lu)\n", __func__, a, b);
    exit(EXIT_FAILURE);
  }
  return a+b;
}

/* Es gibt auch eine Lösung bei der man limits.h nicht braucht:

unsigned long safe_add(a,b) {
  unsigned long summe = a+b;
  if ((summe)<b && (summe)<a) {
    fprintf(stderr, "Integer overflow");
    return EXIT_FAILURE;
  } else {
    return a+b;
  }
}

int main(void) {
  unsigned long groesste_zahl = (unsigned long) -5;
  unsigned long zahl = 7;
  unsigned long summe = safe_add(groesste_zahl, zahl);
  printf("Die summe ist: %lu", summe);
  return EXIT_SUCCESS;
}
Das funktioniert, weil wenn wir die größte unsigned long Zahl, ULONG_MAX, um 1 inkrementieren,
dann bekommen wir einfach wieder 0 bzw. der Zähler wird resettiert. 
 */
