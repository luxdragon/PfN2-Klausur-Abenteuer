/*
Der logische Fehler ist wieder das ; hinter dem else.
Das führt dazu, dass es für den compiler keinen nichts gibt, was im else Fall
passieren soll
"falsch" wird immer geprinted

Also im Fall wert == 1 ist die Ausgabe
wahr
falsch

Zur Korrektur muss man nur das ; löschen
*/

#include<iostream>

int main(void){
int wert = 1;
if (wert == 1)
  std::cout << "wahr" << std::endl;
else
  std::cout << "falsch" << std::endl;
}
