/*

*/

#include<stdio.h>

typedef double (*CombinerFunc)(double a, double b);

void add_generic_3D(CombinerFunc f, double ***a, double ***b, double ***c, int m, int n, int l){
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      for(int k = 0; k < l; k++)
        c[i][j][k] = f(a[i][j][k], b[i][j][k]);
}

double add_sum(double a, double b){
  return a+b;
}

double add_product(double a, double b){
  return a*b;
}
