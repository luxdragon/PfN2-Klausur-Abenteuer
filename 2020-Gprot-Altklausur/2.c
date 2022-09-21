#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int *merge_arrays(const int *a, unsigned long alen, const int *b, unsigned long blen){
  int *merged_arr = malloc((alen+blen) * sizeof(int)); //alen+blen zu klammern ist ein kleiner aber wichtiger Fehler der einem passieren kann, ich spreche aus Erfahrung xD
  size_t i = 0;
  int *aptr = a;
  int *bptr = b;
  while((aptr < a+alen) && (bptr < b+blen)){
    if(*aptr < *bptr){
      merged_arr[i] = *aptr;
      i++;
      aptr++;
    }
    else if(*bptr < *aptr){
      merged_arr[i] = *bptr;
      i++;
      bptr++;
    }
    else if(*aptr == *bptr){
      merged_arr[i] = *aptr;
      i++;
      merged_arr[i] = *bptr;
      i++;
      aptr++;
      bptr++;
      }
    }
    while(aptr < a + alen){
      merged_arr[i] = *aptr;
      aptr++;
      i++;
    }
    while(bptr < b + blen){
      merged_arr[i] = *bptr;
      bptr++;
      i++;
    }
  assert(i == alen+blen); //optional aber schön
  return merged_arr;
}


int main(void){
  int arr[] = {2,3,6,11,14};
  size_t alen = 5;
  int brr[] = {1,5,6,11,12,16,42};
  size_t blen = 7;

  int *res = merge_arrays(arr, alen, brr, blen);

  for(size_t i = 0; i < alen+blen; ++i){
    printf("%d ", res[i]);
  }
  printf("\n");
  free(res);
}
