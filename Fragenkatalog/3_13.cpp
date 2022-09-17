/*

Antwort: Das passiert über Iteratoren


Hier ist als Beispiel Aufgabe 1_24 mit vectoren genommen.
Hier wird also mit einem Iterator über die Elemente des vectors iteriert.
*/


#include<iostream>
#include<vector>
#include<string>

int main(void){
  std::vector<std::string> ckeywords
  = {"ughgj", "double", "int", "struct", "break", "else", "long",
      "switch", "case", "enum", "register", "typedef", "char",
      "extern", "return", "union", "const", "float", "short",
      "unsigned", "continue", "for", "signed", "void", "default",
      "goto", "sizeof", "volatile", "do", "if", "static",
      "while"};

/* Das ist der gefragte C++ Programmcode */
   for(auto i = ckeywords.begin(); i != ckeywords.end(); ++i){ // hier wird ein Iterator erstellt
    std::cout << *i << std::endl;
  }
}
