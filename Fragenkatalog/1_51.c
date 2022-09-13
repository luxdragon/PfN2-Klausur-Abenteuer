/*
*/

#include<stdio.h>


size_t count_match_pairs(const int *a, size_t alen, const int*b, size_t blen){
  const int *aptr = a; // sowas ist immer praktisch, um die ursprünglichen Pointer zu bewahren
  const int *bptr = b;
  size_t sum = 0;
  while(aptr != a+alen-1 || bptr != b+blen-1){ //so lange wie nicht beide Enden der Arrays erreicht wurden
    if(*aptr < *bptr){
      if(aptr < a+alen-1){ // Pointer kann nur dann erhöht werden, wenn das Ende des Arrays noch nicht erreicht wurde
        aptr++;
      }
      else{
        break;
      } 
    }
    else if(*bptr < *aptr){
      if(bptr < b+blen-1){ // Pointer kann nur dann erhöht werden, wenn das Ende des Arrays noch nicht erreicht wurde
        bptr++;
      }
      else{
        break;
      } 
    }
    else{ //genau der Fall an dem die Werte auf die aptr und bptr zeigen gleich sind
      sum++;
      if(aptr < a+alen-1){
        aptr++;
      }
      else{
        bptr++;
      }
    }
  }
  return sum;
}

int main(void){
  int arr[] = {19, 27, 33, 39, 55, 76, 78, 79, 84, 91};
  size_t alen = 10;
  int brr[] = {18, 27, 32, 55, 56, 75, 78, 84, 92}; //es sollten also 4 Paare gefunden werden: 27,55,78,84
  size_t blen = 9;
  size_t res = count_match_pairs(arr, alen, brr, blen);
  printf("Pairs: %ld\n", res);
}
