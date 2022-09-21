//ein dreifacher Pointer... es wird immer besser

typedef void (*f)(double ***, double ***, double ***, int, int, int) CombinerFunction;

void add_generic_3D(CominerFunction f, double ***c, double ***a, double ***b, int m, int n, int l) {
    f(c, a, b, m, n, l);
}

CombinerFunction add_sum(double ***c, double ***a, double ***b, int m, int n, int l) {
  //der gleiche Inhalt wie bei add_sum_3D
}

CombinerFunction add_product(double ***c, double ***a, double ***b, int m, int n, int l) {
  //der gleiche Inhalt wie bei add_product_3D
}
