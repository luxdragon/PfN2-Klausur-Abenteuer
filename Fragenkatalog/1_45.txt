/*
Hier muss man beachten, dass bei einem Array mit n Einträgen höchstens n
Vergleiche n Vergleiche des Schlüssels mit dem Array erlaubt sind.


Diese Implementierung funktioniert nur bei aufsteigend geordneten Arrays.
Implementierung für <= vielleicht ungleich komplizierter?

Zu beachten: Normales linear search funktioniert auch bei ungeordneten arrays

*/

//#### gefragte Funktion ####

#include<stdio.h>

const size_t *linearsearch_sm_geq(const size_t *leftptr, const size_t *rightptr, size_t key){
  while(leftptr != rightptr){
    if(*leftptr >= key){
      return leftptr;
    }
    leftptr++;
  }
  return NULL;
}




//#### main und Hilfsfunktionen ####

int main(void){
  const size_t arr[] = {19, 27, 33, 39, 55, 76, 78, 79, 84, 91};
  size_t key = 34; //hier beliebigen key zum Testen eintragen

  const size_t *leftptr = arr;
  const size_t *rightptr = arr+9;

  const size_t *ptr = linearsearch_sm_geq(leftptr, rightptr, key);
  printf("%ld\n", *ptr);
}
