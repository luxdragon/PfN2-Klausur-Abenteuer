#include <stdio.h>
#include <stdlib.h> //wichtig für Qsort
#include <math.h> ///wichtig für Sqrt()

typedef struct {
  double real, imag;
} Complex;

int compare(const void *a, const void *b) {
  const Complex *erste = a;
  const Complex *zweite = b;
  double wert1 = sqrt((erste->real)*(erste->real)+(erste->imag)*(erste->imag));
  double wert2 = sqrt((zweite->real)*(zweite->real)+(zweite->imag)*(zweite->imag));
  if (wert1 > wert2) {
    return 1;
  } else {
    return -1;
  }
}
void sort_complex(Complex *tab, size_t len) {
  qsort(tab, len, sizeof(Complex), compare);
}

int main(void) {
  //nur zum Überprüfen
  Complex z1;
  z1.real = 5;
  z1.imag = 2;
  Complex z2;
  z2.real = -1;
  z2.imag = 2;
  Complex z3;
  z3.real = 7;
  z3.imag = 10;
  Complex arr[] = {z1, z2, z3};
  sort_complex(arr, 3);
  for (int i = 0; i < 3; i++) {
    printf("Realwert: %lf, Imaginärwert: %lf\n", arr[i].real, arr[i].imag);
  }
  return 0;
}
