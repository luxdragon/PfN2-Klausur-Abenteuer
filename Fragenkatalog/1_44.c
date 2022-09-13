/*
gutes Video zu binary search:
https://www.youtube.com/watch?v=B25Gu5r0xUg

Hier wurde der Vollständigkeit halber nicht nur der Fall >= (geq), sondern auch 
der Fall <= (seq) implementiert.

Um rauszufinden wie die gegebene Funktion verändert werden muss, empfehle ich
im Zweifelsfall den binary search anhand eines Beispiels durchzugehen und damit
den entsprechenden Zustand zu finden, mit dem man die geforderte Erweiterung
der Funktion erreichen kann.

Damit lässt sich dann auch direkt (neben dem geforderten greater equal (geq)
Fall), der Fall für smaller equal (seq) finden.

Ausgangspunkt ist der gegebene Code, der einem schon mal immer den key im Array
findet. Was aber wenn der Key nicht im Array ist? Das ist das, was man in dieser
Aufgabe betrachten soll.

Im folgenden wird der binary search Algorithmus an einem Beispielarray 
durchgeführt:

-Das Array muss aufsteigend sortiert sein!
r ist der rightpointer
l ist der leftpointer
* ist der midpointer = leftptr + (rightptr - leftptr)/2
key: 7

[2,4,6,8,10]
 l        r

[2,4,6,8,10]  // *midptr < key => leftptr = midptr+1
 l   *    r

[2,4,6,8,10]
     * l  r

[2,4,6,8,10] // *midptr > key => rightptr =  midptr-1
       l  r
       *

[2,4,6,8,10] // jetzt wäre (leftptr <= rightptr) false, dementsprechend würde NULL zurückegeben werden.
     r l   
       *       

=> für das geforderte geq würde man hier jedoch midptr/leftptr zurückgeben.
=> wäre seq gefordert gewesen, würde man rightptr zurückgeben.

Mit den gewonnenen Erkenntnissen, kann jetzt also die gegebene Funktion
modifiziert werden.
*/



//#### gefragte Funktion >= key (geq) ####
#include<stdio.h>

const size_t *binarysearch_geq(const size_t *leftptr, const size_t *rightptr, size_t key) {
  while (leftptr <= rightptr) {
    const size_t *midptr = leftptr + (size_t) (rightptr-leftptr)/2;
    if (key < *midptr){
      rightptr = midptr - 1;
    }
    else {
      if (key > *midptr){
        leftptr = midptr + 1;
      }
      else{
        return midptr; // für den Fall, dass der Key im array ist, stimmt das ja alles noch
      }
    }
  } // ab hier muss also verändert werden
  if(*leftptr > key){
    return leftptr;
  }
  else{
    return NULL;
  }
}


//##### zusätzliche Funktion für <= key (seq) ####

const size_t *binarysearch_seq(const size_t *leftptr, const size_t *rightptr, size_t key) {
  while (leftptr <= rightptr) {
    const size_t *midptr = leftptr + (size_t) (rightptr-leftptr)/2;
    if (key < *midptr){
      rightptr = midptr - 1;
    }
    else {
      if (key > *midptr){
        leftptr = midptr + 1;
      }
      else{
        return midptr;
      }
    }
  }
  if(*rightptr < key){
    return rightptr;
  }
  else{
    return NULL;
  }
}


//#### main und Hilfsfunktionen ####

void show_arr(size_t *arr, size_t len);

int main(void){
  size_t arr[] = {19, 27, 33, 39, 55, 76, 78, 79, 84, 91};
  size_t key_1 = 77;
  size_t key_2 = 33;

  const size_t *leftptr = arr;
  const size_t *rightptr = arr+9;

  show_arr(arr, 10);


  const size_t *geq = binarysearch_geq(leftptr, rightptr, key_1); // sollte also 78 liefern
  const size_t *seq = binarysearch_seq(leftptr, rightptr, key_1); // sollte also 76 liefern

  const size_t *geq_key2 = binarysearch_geq(leftptr, rightptr, key_2); // sollte also 33 liefern
  const size_t *seq_key2 = binarysearch_seq(leftptr, rightptr, key_2); // sollte also 33 liefern

  printf("geq mit key %ld liefert: %ld\n", key_1, *geq);
  printf("seq mit key %ld liefert: %ld\n", key_1, *seq);

  printf("geq mit key %ld liefert: %ld\n", key_2, *geq_key2);
  printf("seq mit key %ld liefert: %ld\n", key_2, *seq_key2);
  
}

void show_arr(size_t *arr, size_t len){
  printf("[ ");
  for(size_t i = 0; i < len; ++i){
    printf("%ld ", arr[i]);
  }
  printf("]\n\n");
}


