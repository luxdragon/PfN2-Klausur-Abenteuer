/*
Die Idee ist den neuen pointer zu erhöhen und dann den ursprünglichen pointer
(der noch auf den Anfang des strings zeigt) vom neuen abzuziehen.
Die Differenz ist die Länge des strings
*/

//#### gefragt Funktion ####
#include<stdio.h>


size_t strlen_ptr(const char *s){
  const char *ptr = s;
  while(*ptr != '\0'){
    ptr++;
  }
  return ptr-s;
}

//#### main ####
int main(void){
  char *s = "Beispielstring"; // Länge: 14
  printf("%ld\n", strlen_ptr(s));
}
