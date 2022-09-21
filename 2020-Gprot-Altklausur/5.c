/*
Selbe Aufgabe wie aus dem Fragenkatalog
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


char *random_sequence_prob(const char *alphabet, const double *prob, size_t n){
  char *res = malloc(n * sizeof(char));
  size_t k = strlen(alphabet);
  double s = 0.0;

  double *prob_tab = malloc((n+1)*sizeof(double));
  prob_tab[0] = 0.0;
  for(size_t i = 1; i < k+1; ++i){
    s += prob[i-1];
    prob_tab[i] = s;
  }

  for(size_t j = 0; j < n; ++j){
    double ran = drand48();
    for(size_t h = 1; h < k+2; ++h){
      if(prob_tab[h-1] <= ran && ran < prob_tab[h]){
        res[j] = alphabet[h-1];
      }
    }
  }
  return res;
}


int main(void){
  srand48(time(NULL));
  const char *alph = "acgt";
  const double prob[] = {0.1,0.2,0.3,0.4};
  size_t n = 15;

  char *res = random_sequence_prob(alph, prob, n);
  printf("%s\n", res);
  free(res);
}
