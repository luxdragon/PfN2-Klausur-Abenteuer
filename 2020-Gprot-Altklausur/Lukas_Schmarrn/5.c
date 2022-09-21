//Die Aufgabe habe ich gemacht, allerdings wurde sie beim Kopieren gelöscht :(
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//hier dürfen wir einfach die lineare Suche anwenden.
char *random_sequence_prob(const char *alphabet, const double *prob, size_t n) {
  size_t len;
  for (len = 0; alphabet[len] != '\0'; len++);
  char *sequenz = malloc(n);
  for (size_t i = 0; i < n; i++) {
    double wert = drand48();
    double cum_prob = 0;
    for (size_t j = 0; j < len; j++) {
      cum_prob += prob[j];
      printf("%lf\n", prob[j]);
      if (wert <= cum_prob) {
        sequenz[i] = alphabet[j];
        break;
      }
    }
  }
  return sequenz;
}

int main(void) {
  srand48(time(NULL));
  char alphabet[] = "abcd";
  double probabilities[] = {0.1, 0.2, 0.3, 0.4};
  char *sequenz = random_sequence_prob(alphabet, probabilities, 20);
  printf("%s", sequenz);
  free(sequenz);
  return 0;
}
