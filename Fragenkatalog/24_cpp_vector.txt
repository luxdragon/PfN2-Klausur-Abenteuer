/* 
Aufgabe 1_24 mit C++ vectoren aus STL zu lösen, ist eine mögliche Variation 
der Aufgabe. Diese kam so oder ähnlich in der ersten Klausur SoSe2022 dran.
*/

#include<iostream>
#include<vector>
#include<string>

int main(void){
  std::vector<std::string> ckeywords
  = {"auto", "double", "int", "struct", "break", "else", "long",
      "switch", "case", "enum", "register", "typedef", "char",
      "extern", "return", "union", "const", "float", "short",
      "unsigned", "continue", "for", "signed", "void", "default",
      "goto", "sizeof", "volatile", "do", "if", "static",
      "while"};
  
  size_t count = 0;
  size_t n_elems = ckeywords.size();
  
  for(auto i = ckeywords.begin(); i != ckeywords.end(); ++i){ // hier wird ein Iterator erstellt
    count += (*i).size(); // muss so sein, weil i als erstes derefenziert werden muss um Zugriff auf den eigentlichen string im vector zu haben
  }



  std::cout << "Anzahl der Einträge = " << n_elems << std::endl;
  std::cout << "Summe der Länger aller Einträge = " << count << std::endl;
}
