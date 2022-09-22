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
shpl.push_back("John"); //Push_back schiebt ein Element ans ende des Containers
shpl.insert(1, "Max"); //Immer die Position an der ersten Stelle schreiben

//gibt es das Befehl push_back in allen drei? Ja

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

gerne ergänzen :D
*/
