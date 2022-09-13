/* structs und unions sind z.B. zusammengesetzte Datentypen */

#include<stdio.h>

/* Deklaration von struct*/
struct Datum{
  int day;
  char *month;
  int year;
};

/* Dekleration von union*/
union int_or_float{
  int x;
  float y;
};

/* alternativ und noch leichter zu merken:
typedef union {
  int x;
  float y;
} int_or_float; */

int main(void){
  struct Datum date; //Deklaration einer Instanz von Datum

  /* Zuweisungen für struct: */
  date.day = 27;
  date.month = "September";
  date.year = 2022;
  printf("%d-%s-%d\n\n", date.day, date.month, date.year);



  union int_or_float z; //Deklaration einer Instanz von int_or_float
  z.x = 7;
  z.y = 1337.42;

  printf("%d\n", z.x);
  printf("%f\n", z.y);

  /* man kann dann sehen, dass z.x nicht mehr gespeichert ist */
  /* würde man aber z.y zuerst deklarieren und dann z.x, wäre der Wert von z.y
  nur noch ungefähr gespeichert. Warum? Guckt euch Videos dazu an*/
}
