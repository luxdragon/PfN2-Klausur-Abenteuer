/*
Analog zu Fragenkatalog 4.3
*/

#include<iostream>

size_t f(size_t n){
  return n<=1 ? 1 : (f(n-1) + f(n-2));
}

typedef void (*PFNThreadFunc)(size_t thread_id, size_t task_num, void *thread_data);

void eval_f(size_t thread_id, size_t task_num, void *thread_data){
  size_t *table = (size_t *) thread_data;
  table[task_num] = f(table[task_num]);
}
