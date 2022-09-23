#include <stdio.h>
#include <stdlib.h> //für Qsort
#include <string.h> //für strcmp

static const char *months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
//static bedeutet in diesem Kontext "global"

typedef struct {
  int year;
  const char *month;
} Date;

int checkmate(const void *x, const void *y) {
  Date *a = x;
  Date *b = y;
  if (a->year > b->year) {
    return 1; //1 wenn wir was wechseln sollen
  } else if (a->year < b->year) {
    return -1; //wenn wir nichts machen wollen
  } else {
    int i, j;
    for (i = 0; strcmp(a->month, months[i]) != 0; i++); //wir wandeln den Monat in eine Zahl um
    for (j = 0; strcmp(b->month, months[j]) != 0; j++); //ACHTUNG: b->month == months[i] funktioniert nicht, weil Zeiger verglichen werden
    if (i > j) {
      return 1;
    } else {
      return -1;
    }
  }
}

void sort_dates(Date *tab, size_t len) {
  qsort(tab, len, sizeof(Date), checkmate);
}

int main(void) {
  Date d1;
  d1.year = 1995;
  d1.month = "Jun";

  Date d2;
  d2.year = 913;
  d2.month = "Sep";

  Date d3;
  d3.year = 2022;
  d3.month = "Aug";

  Date d4;
  d4.year = 2022;
  d4.month = "Jan";

  Date d5;
  d5.year = 2000;
  d5.month = "Mar";

  //diese habe ich schamlos von Niels geklaut :D
  Date tab[] = {d1,d2,d3,d4,d5};
  size_t tab_len = 5;
  sort_dates(tab, tab_len);

  for(size_t i = 0; i < tab_len; ++i){
    printf("%ld\t%d\t%s\n", i, tab[i].year, tab[i].month);
  }
  return 0;
}
