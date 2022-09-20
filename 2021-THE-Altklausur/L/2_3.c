#include <stdio.h>
#define TOM 0.001 //der TOM Wert wäre bestimmt kleiner, vielleicht die maschinelle Genauigkeit/Epsilon von double

double invert_decreasing_function(double (*f)(double), double l, double r, double y) {
    double left = l;
    double right = r;
    while ((right-left)>TOM) {
        double mid = (left+right)/2;
        if (f(mid) > y) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return (double) (left+right)/2;
}

double g(double x) {
    double y = 1 - x*x; //Parabel mit Nullstellen bei x=+-1, monoton fallend ab x=0.
    return y;
}

int main(void) {
    printf("Ergebnis: g(%lf)=0\n", invert_decreasing_function(g, 0.7, 2, 0)); //wir erwarten g(1.000...)=0
    return 0;
}
