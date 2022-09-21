#include<stdio.h>
#include<math.h>

#define TOL 0.00001


double invert_decreasing_function(double (*f)(double), double l, double r, double y){
  double left = l;
  double right = r;
  while((right-left) > TOL){
    double mid = (left+right)/2;
    if(f(mid) > y){
      left = mid;
    }
    else{
      right = mid;
    }
  }
  return (double) (left+right)/2;
}

double func(double x){
  return (((4*pow(x,3)-6*pow(x,2)+1)*sqrt(x+1))/(3-x));
}


int main(void){
  double res = invert_decreasing_function(func, 0.2, 1.0584, 0);
  printf("%lf\n", res);
}
