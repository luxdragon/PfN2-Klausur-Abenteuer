/*
! nicht vergessen, dass der compiler extra lpthread linken muss
Befehl fürs kompillieren:
c++ -o 4_02.o 4_02.cpp -lpthread

Ist das dann wirklich so, dass die Threads gleichzeitig aufgerufen werden?
=> ich würde jetzt nämlich denken dass nicht, aber so wurde es in der VL
gemacht


Die Ausgabe scheint erstmal falsch zu sein, aber bei mehrfachen ausführen
sieht man, dass die threads pro Aufruf jeden mal anders vom OS gehandhabt
werden.

Das was einfach zu printen ist, passiert sofort nach ihrem jeweiligen Aufruf.
Die eigentliche Rechnung in jedem Thread dauert unterschiedlich lange für die
verschiedenen Zahlen, deswegen ergibt sich auch jedes mal die gleiche
Reihenfolge von Ergebnissen, da der Rechenaufwand unterschiedlich genug ist,
sodass die threads für die jeweilige Aufgabe/Zahl immer in der gleichen
Reihenfolge fertig werden.

Diese Aufgabenstellung bzw. das Ergebnis ist ein schönes Beispiel dafür was
für Durcheinander entstehen kann, wenn man threads nicht gemäß der gewünschten
Aufgabe managed.

*/

#include<iostream>
#include<thread> // ist hier natürlich wichtig und richtig

size_t f(size_t n) { return n<=1 ? 1 : (f(n-1) + f(n-2)); }

void eval_show_f(size_t n) {
  std::cout << "f(" << n << ")=" << f(n) << std::endl;
}

//######## geftrage Funktion ############
void eval_show_f_multithreaded(const size_t *values,size_t k){
  std::thread *threads; //Array in dem erzeugte Threads gespeichert werden sollen
  threads = new std::thread [k]; // anlegen von Speicher für die thread Objekte

  for(size_t i = 0; i < k; ++i){ // in dieser Schleife werden die threads gestartet
    threads[i] = std::thread(eval_show_f, values[i]); //Frage: Das ist ja dann nicht wirklich gleichzeitig, sondern ganz schnelles hintereinander aufrufen. Also theorethisch laufen die threads dann gleichzeitig
  }

  for(size_t j = 0; j < k; ++j){ // threads werden beendet
    threads[j].join();
  }
}
// Tutor: hilf uns

//#### main #####
int main(void){
  size_t values[] = {39,42,41};
  size_t k = sizeof(values)/sizeof(values[0]);

  eval_show_f(values[0]); //warum rufst du die schon hier auf
  eval_show_f(values[1]);
  eval_show_f(values[2]);

  std::cout << std::endl;

  eval_show_f_multithreaded(values, k);
  return EXIT_SUCCESS;
}
