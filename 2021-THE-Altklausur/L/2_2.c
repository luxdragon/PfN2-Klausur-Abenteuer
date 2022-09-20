/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h> //wird für Malloc und drand48() gebraucht
#include <time.h> //für die Initalisierung von drand48()
//die Idee zu dieser Aufgabe findet man im Numerical-Skript auf den Folien 18-22 

typedef int bool; //für bool-Werten
const bool true = 1;
const bool false = 0;
//alternativ: #include <stdbool.h> und nicht <bool.h>

double estimate_volume(bool (*is_inside)(double, double, double), size_t num_points) {
    size_t hits = 0;
    for (size_t i = 0; i < num_points; i++) {
        double a = drand48(), b = drand48(), c = drand48();
        if (is_inside(a,b,c)) {
            hits++;
        }
    }   
    return (double) hits / num_points;
}

bool czech(double x, double y, double z) { //das ist eine kleine Ecke im Quader
    if (x < 0.25 && y > 0.75 && z < 0.25) {
        return true;
    } else {
        return false;
    }
}

int main(void) {
    srand48(time(NULL));
    printf("%lf m2\n", estimate_volume(czech, 10000)); //wir erwarten 1/64, also 0,015625 m^3
    return 0;
}
