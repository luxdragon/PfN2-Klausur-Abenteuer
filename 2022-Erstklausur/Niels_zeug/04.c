/*
Die Frage die sich mir direkt stellt ist folgende:
Wie soll man es hinbekommen die month strings gemäß der Jahresabfolge zu ordnen?
Weil das ist weder lexikographische Ordnung noch Ordnung nach der Länge.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
  int year;
  const char *month;
} Date;

static const char *months[] = {"Jan","Feb", "Mar", "Apr", "May", "Jun", "Jul",
                              "Aug", "Sep", "Oct", "Nov", "Dec"};


int compare(const void *a, const void *b){
  const Date *x = a;
  const Date *y = b;
  if(x->year < y->year){
    return -1;
  }
  else if(x->year > y->year){
    return 1;
  }
  else{
    for(size_t i = 0; i<12; ++i){
      if(strcmp(x->month,months[i]) == 0){
        return -1;
      }
      else if(strcmp(y->month, months[i]) == 0){
        return 1;
      }
    }
  }
}

void sort_dates(Date *tab, size_t len){
  qsort(tab, len, sizeof(Date), compare);
}

int main(void){
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


  Date tab[] = {d1,d2,d3,d4,d5};
  size_t tab_len = 5;
  sort_dates(tab, tab_len);

  for(size_t i = 0; i < tab_len; ++i){
    printf("%ld\t%d\t%s\n", i, tab[i].year, tab[i].month);
  }
}
