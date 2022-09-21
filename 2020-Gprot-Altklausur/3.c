/* 
Nach was sollen die strings hier sortiert werden? Länge? Lexikographisch?
Gute Aufgabenstellung auf jeden Fall.

Außerdem: compare Funktion aus der c-Standard-Bib heißt für mich, dass man 
string.h benutzen darf oder?

Ich entscheide mich mal für die lexikographische Ordnung und benutze strcmp()

Lösung mit strlen wäre analog

Lösung ohne string.h: Keine Ahnung

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
  char *strptr;
  int intval;
} StringIntPair;

int compare(const void *a, const void *b){
  const StringIntPair *aptr =  a;
  const StringIntPair *bptr =  b;
  int res = strcmp(aptr->strptr, bptr->strptr); //strcmp gibt nicht nur -1,0,1 zurück
  //printf("%d\n",res);
  if(res < 0){ //a ist lexikographisch kleiner als b
    return 1; // soll ja absteigend geordnet werden => b kommt vor a
  }
  else if(res > 0){ //a ist lexikographisch größer als b
    return -1; // soll ja absteigend geordnet werden => a kommt vor b
  }
  else{
    if(aptr->intval < bptr->intval){
      return 1;
    }
    else{
      return -1;
    }
  }
}

void sort_string_int_pairs(StringIntPair *tab, size_t len){
  qsort(tab, len, sizeof(StringIntPair), compare);
}



int main(void){
  StringIntPair s1;
  s1.strptr = "Stefaaaan";
  s1.intval = 7;

  StringIntPair s2;
  s2.strptr = "PfN2";
  s2.intval = 15;

  StringIntPair s3;
  s3.strptr = "Antwortaufalles";
  s3.intval = 42;

  StringIntPair s4;
  s4.strptr = "NoteinKlausur";
  s4.intval = 1;

  StringIntPair s5;
  s5.strptr = "PfN2";
  s5.intval = -15;

  StringIntPair tab[] = {s1,s2,s3,s4,s5};
  size_t tab_len = 5;
  sort_string_int_pairs(tab, tab_len);
  
  for(size_t i = 0; i < tab_len; ++i){
    printf("%ld\t%s\t%d\n", i,tab[i].strptr, tab[i].intval);
  }
}
