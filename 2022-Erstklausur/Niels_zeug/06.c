/*
Das Programm ist noch ziemlich kaputt und ich weiß noch nicht 100% wieso, aber ich hatte keine Lust mehr

*/

#include<stdio.h>
#include<limits.h>

void enumerate_series(void){
  __uint32_t s = 1;
  size_t i = 1;
  printf("%d\n", s);
  while(s < __UINT32_MAX__){
    double f = (2*(2*i-1))/(i+1);
    long c = (long) s*f;
    if(c > __UINT32_MAX__){
      break;
    }
    s = s * f;
    printf("%ld\n", s);
    i++; //nicht vergessen!!!
  }
}

int main(void){
  enumerate_series();
}

