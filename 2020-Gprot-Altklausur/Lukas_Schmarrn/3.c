//Die Aufgabe habe ich gemacht, allerdings wurde sie beim Kopieren gelöscht :(
#include <stdio.h>
#include <stdlib.h> //für qsort
#include <string.h> //für strcmp

typedef struct {
  char *strptr;
  int intval;
} StringIntPair;

int gkog(const void *a, const void *b) {
  StringIntPair *x = a;
  StringIntPair *y = b;
  if(strcmp(x->strptr, y->strptr) > 0){ //ich habe statt strcmp vergleich() geschrieben
    return -1;
  } else if (strcmp(x->strptr, y->strptr) < 0) {
    return 1;
  } else {
    if (x->intval > y->intval) {
      return 1;
    } else {
      return -1;
    }
  }
}

void sort_string_int_pairs(StringIntPair *tab, unsigned long len) {
  qsort(tab, len, sizeof(StringIntPair), gkog);
}



int main(void) {
  StringIntPair ein;
  StringIntPair zwei;
  StringIntPair drei;
  ein.strptr = "abc";
  ein.intval = 15;
  zwei.strptr = "bcd";
  zwei.intval = 2;
  drei.strptr = "bcd";
  drei.intval = 3;
  StringIntPair tabl[] = {drei, ein, zwei};
  sort_string_int_pairs(tabl, 3);
  for (int i = 0; i < 3; i++) {
      printf("%s%d\n", tabl[i].strptr, tabl[i].intval);
  }
  return 0;
}
