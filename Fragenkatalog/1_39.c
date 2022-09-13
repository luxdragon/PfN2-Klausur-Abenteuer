/*
Die Idee ist mit einem Pointer über den String zu gehen und zu schauen, ob das 
Element auf das der Pointer zeigt, isdigit(), islower() oder isupper() 
entspricht. Wenn das der Fall ist, wird der jeweilige Zähler hochgezählt und 
der Pointer erhöht.
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

//#### gefragte Funktion ####

typedef struct{
  size_t digit_count, lower_count, upper_count;
} Charclass_counts;

Charclass_counts *char_classify(const char *s){
  Charclass_counts *class = malloc(sizeof(Charclass_counts));
  class->digit_count, class->lower_count, class->upper_count = 0;
  while(*s != '\0'){
    if(isdigit(*s) != 0){
      class->digit_count++;
      s++;
    }
    else if(isupper(*s) != 0){
      class->upper_count++;
      s++;
    }
    else if(islower(*s) != 0){
      class->lower_count++;
      s++;
    }
    else{
      s++;
    }
  }
  return class;
}


//#### main ####
int main(void){
  char *s = "Extr3m_l4ngEr kr4SSeR BeIspiEl2tr7nG";
  Charclass_counts *res = char_classify(s);
  printf("Anzahl digit: %ld\n",res->digit_count);
  printf("Anzahl lower: %ld\n",res->lower_count);
  printf("Anzahl upper: %ld\n",res->upper_count);
}
