#include <stdio.h>
#include <stdlib.h> //wird für Malloc und drand48() gebraucht
#include <time.h> //für die Initalisierung von drand48()

char *random_sequence_iid(const char *alphabet, size_t n) {
  char *sequenz = malloc(n*sizeof(char));
  size_t len = sizeof(alphabet)/sizeof(char) -1;
  float frac = (float) 1/len;
  printf("Len: %ld und frac: %f", sizeof(alphabet), frac); //schaut euch das an!!
  for (size_t i = 0; i < n; i++) {
    float wert = drand48();
    for (size_t j = 1; j <= len; j++) {
      if (wert <= frac*j && wert > frac*(j-1)) {
        sequenz[i] = alphabet[j-1];
      }
    }

  }
  return sequenz;
}

int main(void) {
  srand48(time(NULL));
  char *arr = "acgt";
  char *zufallsequenz = random_sequence_iid(arr, 20);
  printf("%s", zufallsequenz);
  free(zufallsequenz); //SUPER WICHTIG!
  return 0;
}
