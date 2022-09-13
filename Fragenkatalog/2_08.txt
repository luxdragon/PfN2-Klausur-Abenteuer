/*
Ab F.101 numerical.pdf

golden section search verkleinert iterativ das Interval das x_min enthält

(Für diese Methode muss die Funktion nicht stetig sein)

f muss unimodal sein (gegeben)

- Es gibt also ein Intervall [l,r] das x_min enthält ; GR = (sqrt(5)-1)/2 



in jedem Schritt wird d aus neuen Intervallgerenzen berechnet:

d = GR * (r - l)

l wird um +d geändert = x_1

r wird um -d geändert = x_2

f(x_1) und f(x_2) werden berechnet und verglichen.


f(x_1) < f(x_2) => x_2 wird neues l, x_1 wird neues x_2, r wird nicht verändert
(führt dazu, dass ein Großteil des linken Anfangs-Intervalls verworfen wird)


f(x_1) > f(x_2) => x_1 wird neues r, x_2 wird neues x_1, l wird nicht verändert
(führt dazu, dass ein Großteil des rechten Anfangs-Intervalls verworfen wird)


=> iterativer Prozess, das Intervall wird immer kleiner und 
nähert sich immer weiter dem Minimum an. 
Nach z Iterationen kann man den Durchschnitt m aus den Intervallgrenzen
berechnen und hat eine gute Näherung für das Minimum

Zur Verwendung des golden ratios: Folie 108

*/



//############### Beispiel; nicht Teil der Lösung! #####################

// Ich hab das mal richtig platt für 3(x-1)^2-15 gemacht ; Minimum (1,-15):
// um das zu verallgemeinern, müsste man die gewählte Funktion noch dynamisch einbinden

#include<stdio.h>
#include<math.h>

double search_min_golden_section_search_example(double interval_start, double interval_end, size_t number_its){
  double res_x;
  double GR =(double) (sqrt(5) - 1)/2;
  double l = interval_start;
  double r = interval_end;
  for(size_t i = 0; i<number_its; ++i){
    double d = (double) GR * (r - l);
    double x_1 = l + d;
    double x_2 = r - d;

    double fx_1 = 3*((x_1-1)*(x_1-1))-15;
    double fx_2 = 3*((x_2-1)*(x_2-1))-15;

    if(fx_1 < fx_2){
      l = x_2;
      //x_1 = x_2; // man müsste hier also nicht x_1 nochmal berechnen im nächsten Schritt, das wäre der Vorteil des GR
    }

    else if(fx_1 > fx_2){
      r = x_1;
      //x_2 = x_1; // man müsste hier also nicht x_2 nochmal berechnen im nächsten Schritt, das wäre der Vorteil des GR
    }
    //printf("new intervall [%lf , %lf]\n", l, r); // zum an und abschalten ob die neu gefundenen Intervalle mit angezeigt werden sollen
  }
  res_x =(double) (r+l)/2;
  double res_y = 3*((res_x-1)*(res_x-1))-15;

  printf("Minimum found at (%lf , %lf) after %ld iterations\n\n", res_x, res_y, number_its);
  return res_x;
}

int main(void){
  double res_x;
  for(size_t i = 0; i < 50; i++){
    double res_x = search_min_golden_section_search_example(-100.0, 100.0, i);
  }
}

/* Ergebnis:
Minimum found at (0.000000 , -12.000000) after 0 iterations

Minimum found at (38.196601 , 4135.761406) after 1 iterations

Minimum found at (14.589803 , 539.048267) after 2 iterations

Minimum found at (-0.000000 , -12.000000) after 3 iterations

Minimum found at (9.016994 , 177.816596) after 4 iterations

Minimum found at (3.444185 , 2.922126) after 5 iterations

Minimum found at (-0.000000 , -12.000000) after 6 iterations

Minimum found at (2.128624 , -11.178626) after 7 iterations

Minimum found at (0.813062 , -14.895162) after 8 iterations

Minimum found at (1.626124 , -13.823907) after 9 iterations

Minimum found at (1.123624 , -14.954151) after 10 iterations

Minimum found at (0.813062 , -14.895162) after 11 iterations

Minimum found at (1.005000 , -14.999925) after 12 iterations

Minimum found at (0.886376 , -14.961269) after 13 iterations

Minimum found at (0.959689 , -14.995125) after 14 iterations

Minimum found at (1.005000 , -14.999925) after 15 iterations

Minimum found at (0.976996 , -14.998413) after 16 iterations

Minimum found at (0.994303 , -14.999903) after 17 iterations

Minimum found at (1.005000 , -14.999925) after 18 iterations

Minimum found at (0.998389 , -14.999992) after 19 iterations

Minimum found at (1.002475 , -14.999982) after 20 iterations

Minimum found at (0.999950 , -15.000000) after 21 iterations

Minimum found at (1.001510 , -14.999993) after 22 iterations

Minimum found at (1.000546 , -14.999999) after 23 iterations

Minimum found at (0.999950 , -15.000000) after 24 iterations

Minimum found at (1.000318 , -15.000000) after 25 iterations

Minimum found at (1.000090 , -15.000000) after 26 iterations

Minimum found at (0.999950 , -15.000000) after 27 iterations

Minimum found at (1.000037 , -15.000000) after 28 iterations

Minimum found at (0.999983 , -15.000000) after 29 iterations

Minimum found at (1.000016 , -15.000000) after 30 iterations

Minimum found at (0.999996 , -15.000000) after 31 iterations

Minimum found at (1.000008 , -15.000000) after 32 iterations

Minimum found at (1.000000 , -15.000000) after 33 iterations

Minimum found at (0.999996 , -15.000000) after 34 iterations

Minimum found at (0.999999 , -15.000000) after 35 iterations

Minimum found at (1.000000 , -15.000000) after 36 iterations

Minimum found at (0.999999 , -15.000000) after 37 iterations

Minimum found at (1.000000 , -15.000000) after 38 iterations

Minimum found at (1.000000 , -15.000000) after 39 iterations

Minimum found at (1.000000 , -15.000000) after 40 iterations

Minimum found at (1.000000 , -15.000000) after 41 iterations

Minimum found at (1.000000 , -15.000000) after 42 iterations

Minimum found at (1.000000 , -15.000000) after 43 iterations

Minimum found at (1.000000 , -15.000000) after 44 iterations

Minimum found at (1.000000 , -15.000000) after 45 iterations

Minimum found at (1.000000 , -15.000000) after 46 iterations

Minimum found at (1.000000 , -15.000000) after 47 iterations

Minimum found at (1.000000 , -15.000000) after 48 iterations

Minimum found at (1.000000 , -15.000000) after 49 iterations

*/
