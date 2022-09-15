/*

Wurde meines Wissens auch nicht in der VL behandelt
numeric.pdf Folie 110

Maschinen-Genauigkeit epsilon:
Kleinste Fließkommazahl welche, wenn sie zu 1.0 addiert wird, immer noch das
Ergebnis >1.0 ergibt.

Für alle Werte x < epsilon gilt 1.0 + x = 1.0

hier für double gefragt
Das könnte man natürlich noch für floar und long double machen
*/

#include<stdio.h>

int main(void){

  //###### gefragtes Codefragment ####

  double f, eps = (double) 1.0;
  for(f = (double) 1.0; (double) 1.0 + f > (double) 1.0; f /= (double) 2.0){
    eps = f;
  }

  //#### Ende ####

  printf("%e\n", eps);

}


/* Alternativ:
#include <stdio.h>
double find_epsilon(void) {
  double epsilon = 0.5; //idealerweise ein Bruch 1/2, 1/4 oder 2^(-n) für Schnelligkeit
  while ((1+epsilon) != 1) {
    epsilon /= 2.0;
  }
  return epsilon;
}
int main(void) {
  printf("Der Epsilon von Doubles ist: %lf", find_epsilon());
  return 0;
} */
