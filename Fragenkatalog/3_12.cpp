/*
In der VL wurde sich auf vector, map, set aus STL beschränkt.


vector:
#include<vector>
- Ist so ziemlich die allgemeinste Liste, die man sich vorstellen kann.
- Ist eine Klasse und hat die gängigen Komfortfunktionen.
- Kann alle möglichen Datentypen beinhalten und kümmert sich selbst dynamisch
  um Speicher.
- Kann random access
- kann vorwärts und rückwärts iteriert werden
Beispiel:
std::vector<std::string> shpl;
shpl.push_back("Johannes");
shpl.push_back("Stephanie");
shpl.push_back("John");
shpl.insert("Max"); //Anfang oder Ende?
// Was ist der Unterschied zwischen einem Vektor und Array.

//gibt es das Befehl push_back in allen drei?

map:
#include<map>
- Ist ähnlich dictionaries aus Python.
- Es werden Schlüssel/Wert-Paare gespeichert.
- Kein (guter) random access.
- kann vorwärts und rückwärts iteriert werden
Beispiel:
std::map<std::string, char> codon;
codon.insert(pair<std::string, char>("TCA", 'S'));
codon = {{"ABC", 'A'}, {"DEF", 'B'}};
codon["BCD"]='E';



set:
#include<set>
- ist das programmatische Äquivalent der mathematischen Menge
- enthält keine doppelten Werte
- kann vorwärts und rückwärts iteriert werden
std::set<char> a;
a.insert('G');
std::cout << a[0];


Kann man auf die Elemente von Set auch mit a[1] oder so zugreifen, oder muss man
iterieren, á la *(a+2) = a[2]?

gerne ergänzen :D
*/
