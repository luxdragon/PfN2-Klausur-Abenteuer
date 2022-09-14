/*

*/

#include<stdio.h>


double chi_square(const size_t *p_arr, const size_t *q_arr,size_t n){
  double sum = 0;
  for(size_t i = 0; i<n; ++i){
    sum += (double) ((p_arr[i] - q_arr[i]) * (p_arr[i] - q_arr[i]))/p_arr[i]; // typecast zu double ist wichtig, weil mit size_t gerechnet wird
  }
  return sum;
}
