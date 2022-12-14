/*
Wie man das hier machen kann, orrientiert sich in der Implementierung sehr stark
an dem, wie es in der VL gemacht wurde.

numeric. c Folien/Screencasts
Für die folgenden numeric Aufgaben lohnt es sich, die nochmal anzuschauen.
Die Screencasts zu numeric fangen btw. an mit: "Uns bleibt leider nur wenig
Zeit..."

Die Idee dieser Aufgabe ist einen Würfel folgendermaßen zu simulieren:
int ergebnis = 1 + 6*drand48()
zu finden auf Folie 9

das funktioniert, da drand48() bei Aufruf Zahl x zurückgibt mit 0<=x<1
Dementsprechend ist das Ergebnis der oberen Rechnung eine der Zahlen 1,2,3,4,5,6
Das ist auch deswegen der Fall, da int's immer abgerundet werden.

Für den gezinkten Würfel muss man das Intervall [0,1) entsprechend den Vorgaben
in 6 Teile teilen.
Wie viel 'range' für welche Zahl im Intervall vorgesehen ist, repräsentiert die
jeweilige Wahrscheinlichkeit.
So erhält z.B. der Fall dass eine 6 gewürfelt werden soll, bei weitem
am meisten 'range', damit die Wahrscheinlichkeit steigt, dass das Ergebnis von
drand48() in diesem Teil des Intervalls liegt.

Die Verteilung für diese Wahrscheinlichkeiten ist also:

0.0 <= x < 0.1 -> 1 gewürfelt
0.1 <= x < 0.2 -> 2 gewürfelt
0.2 <= x < 0.3 -> 3 gewürfelt
0.3 <= x < 0.4 -> 4 gewürfelt
0.4 <= x < 0.5 -> 5 gewürfelt
0.5 <= x < 1.0 -> 6 gewürfelt


*/

#include<stdio.h>
#include<stdlib.h> //für srand und drand
#include<time.h> //zur Initialisierung von srand48() in main

int gezinkter_wuerfel(void){
  float x = drand48();
  if(0 <= x && x < 0.1){
    return 1;
  }
  else if(0.1 <= x && x < 0.2){
    return 2;
  }
  else if(0.2 <= x && x < 0.3){
    return 3;
  }
  else if(0.3 <= x && x < 0.4){
    return 4;
  }
  else if(0.4 <= x && x < 0.5){
    return 5;
  }
  else{
    return 6;
  }
}

int fairer_wuerfel(void){
  return 1 + 6*drand48(); //drand48() wird nie gleich 0.
}

int main(void){
  srand48(time(NULL)); //Initialisierung von drand48()

  printf("Fair: ");
    for(size_t i = 0; i < 100; ++i){ //100x fair würfeln
      printf("%d ", fairer_wuerfel());
  }
  printf("\n\n");

  printf("Gezinkt: ");
  for(size_t i = 0; i < 100; ++i){ //100x gezinkt würfeln
    printf("%d ", gezinkter_wuerfel());
  }
  printf("\n\n");

}
