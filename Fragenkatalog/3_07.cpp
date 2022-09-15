/*
cpp_slides.pdf Folie 54-55


Template ermöglicht calls von der gleichen Funktion mit verschiedenen
Datentypen.

Funktion wird mit Platzhalter für Datentyp implementiert

Der compiler erzeugt zur Compilezeit dann beim Funktionsaufruf den wirklichen
Code der Funktion mit dem entsprechenden Datentyp indem er den Platzhalter mit
dem gewollten Datentyp ersetzt.

Templates ersparen redudanten Code
Programm kann durch compiler stark optimiert werden
Templates ermöglichen Abstraktion ohne Laufzeit zu erhöhen


Es gibt nicht nur template Funktionen, sondern auch z.b. template classes.

Ein Beispiel:
*/
#include <iostream>
template <typename T>

T accuracy(void) {
  T zahl = 1.0;
  T epsilon = 0.5;
  while ((zahl+epsilon)!= zahl) {
    epsilon /= 2;
  }
  return epsilon;
}

int main(void) {
  float f = accuracy<float>();
  std::cout << f;
  return 0;
}
