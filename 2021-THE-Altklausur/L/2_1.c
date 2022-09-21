#include <stdio.h>
#include <stdlib.h> //wird für Malloc und drand48() gebraucht
#include <time.h> //für die Initalisierung von drand48()

char *random_sequence_iid(const char *alphabet, size_t n) {
  char *sequenz = malloc(n*sizeof(char));
  //size_t len = sizeof(alphabet)/sizeof(char) -1; //wunderschöner Fehler
  size_t len;
  for (len = 0; alphabet[len] != '\0'; len++); //wie man eigentlich die Länge bestimmt
  //printf("Len: %ld und frac: %f", sizeof(alphabet), frac); //schaut euch das an!!
  for (size_t i = 0; i < n; i++) {
    float wert = drand48();
    size_t j = (size_t) wert * len;
    sequenz[i] = alphabet[j];
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
