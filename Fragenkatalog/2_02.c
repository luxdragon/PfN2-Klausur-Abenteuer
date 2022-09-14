/*
Wieder muss erreicht werden, dass sich die Wahrscheinlichkeiten über das
Intervall [0,1) verteilen um das gleiche wie in der letzten Aufgabe zu erreichen

Das ist zu erreichen indem man aus dem gegebenen prob array ein array aus
Partialsummen berechnet:
{0.1,0.2,0.3,0.4} => {0.1,0.3,0.6,1.0}

Dabei darf man nicht vegessen, dass man noch den zusätzlichen Eintrag 0.0 am
Anfang braucht, damit alle Fälle abgedeckt sind:
{0.1,0.2,0.3,0.4} => {0.1,0.3,0.6,1.0} => {0.0,0.1,0.3,0.6,1.0}

Damit ergeben sich die den Wahrscheinlichkeiten entsprechenden Intervalle.


Es gibt bestimmt auch eine elegantere Variante das zu lösen.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

size_t ran2index(double ran, double *probs_cummulative, size_t len){ //hier wird aus der Zufallszahl der Index in alphabet ermittelt
  for(size_t i = 1; i < len+1; ++i ){ // hier len+1, weil das probs_cummulative array um 1 größer ist als das alphabet
    if((probs_cummulative[i-1] <= ran) && (ran < probs_cummulative[i])){
      return i-1; // das ist dann der entsprechende Index des Buchstabens im alphabet array
    }
  }
}

char *random_sequence_prob(const char *alphabet,const double *prob,size_t n){
  char *seq = malloc(n * sizeof(char));
  size_t len = strlen(alphabet);
  double sum_prob = 0;
  double probs_cummulative[len+1]; // len+1 weil die 0.0 auch Platz haben muss

/*Initialisierung des Arrays das die Partialsummen trägt */
  probs_cummulative[0] = 0.0;
  for(size_t i = 0; i < len; ++i){
    sum_prob += prob[i];
    probs_cummulative[i+1] = sum_prob;
  }

  for(size_t j = 0; j < n; ++j){
    double ran = drand48();
    size_t idx = ran2index(ran, probs_cummulative, len);
    seq[j] = alphabet[idx];
  }
  return seq;
}


int main(void){
  srand48(time(NULL));
  const char *alph = "acgt";
  const double prob[] = {0.1,0.2,0.3,0.4};
  size_t n = 15;

  char *res = random_sequence_prob(alph, prob, n);

  printf("%s\n",res); //das funktioniert, obwohl der string nicht \0 terminiert ist
}
