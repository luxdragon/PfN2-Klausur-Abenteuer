#include <stdio.h>
#include <limits.h> //für UINT32_MAX

void enumerate_series(void) {
  size_t i = 1;
  __uint32_t s = 1;
  printf("%u\n", s);
  while (s < __UINT32_MAX__) {
    double faktor = (double) (2*(2*i-1)) / (i+1);
    s = (__uint32_t) s*faktor;
    i++;
    printf("%u\n", s);
  }
}



int main(void) {
  enumerate_series();
  return 0;
}
