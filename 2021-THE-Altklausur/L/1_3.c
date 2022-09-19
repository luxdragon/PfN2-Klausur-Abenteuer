#include <stdio.h>

size_t replace_line_terminator(unsigned char *s, size_t n)  {
  //ist \r ein eingenes Zeichen? Ja, sieht man aus den Beispielen.
  size_t m = 0
  for (size_t i = 0; i < n-m; i++) {
    if (s[i] == '\r') {
      //Verschiebung nach links, d.h. \r wird mit \n ersetzt und so weiter und so weiter
      for (size_t j = i; j < n-m; j++) {
        s[j] = s[j+1];
      }
      m++;
    }
  }
  return n-m;
}

int main(void) {
  unsigned char wort[] = "acgt\r\nabc\r\n"; //das wird "azgpfftnjrnabezenjrnjnnn" ausgesprochen
  printf("Test: %ld\n", replace_line_terminator(wort, 11));
  printf("Der neue String ist: %s\n", wort); //yay es klappt :D
  return 0;
}
