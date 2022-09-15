/*
Es scheint hier sinnvoll zu sein, der Variablen einen default Wert zu geben.

man ersetzt das int n im Funktionskopf durch ein int n=1

Das ist im Beispiel unten auch so zu sehen.

Ich weiß aber nicht, ob das die gemeinte Lösung ist, ob da noch was fehlt
oder ob etwas völlig anderes gemeint ist
*/

#include<string>
#include<vector>
#include<iostream>

void some_function(std::vector<std::string> arr, std::string a, double b, int n=1){ // durch n=1 wird ein default Wert für n angegeben
  std::cout << arr[0] << a << std::endl;
  std::cout << arr[1] << b << std::endl;
  std::cout << "Note die wir in der Klausur erreichen: " << n << std::endl;
}


int main(void){
  std::vector<std::string> arr = {"Unsere Verwirrung: ", "beste Zahl: "};
  std::string a = "hoch";
  double b = 42.0;
  some_function(arr, a, b); // Beachten: Kein Wert für n im Aufruf
}
