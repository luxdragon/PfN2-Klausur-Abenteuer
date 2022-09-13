#include<stdio.h>

#define MAX(X,Y) (X > Y ? X : Y) //Definition des Makros

void main(void){
  printf("%d\n", MAX(42, 1337)); //Test ob dieses Makro das Maximum liefert
}
