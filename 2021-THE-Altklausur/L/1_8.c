#include<stdio.h>
#include<stdlib.h>

double estimate_volume(bool (*is_inside)(double, double, double), size_t num_points){
  unsigned long count = 0;
  for(size_t i = 0; i < n; ++i){
    double x = drand48();
    double y = drand48();
    double z = drand48();
    if(is_inside(x,y,z)){
      count++;
    }
  }
  return (double) count/n;
}
