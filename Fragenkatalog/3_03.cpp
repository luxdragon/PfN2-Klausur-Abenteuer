/*

In den Screencasts von 2021 überspringt er namespaces natürlich

cpp_slides.pdf Folie 17

Man kann ein Programm in verschiedene namespaces aufteilen.

In verschiedenen namespaces können identische identifiers genutzt werden.

Damit werden Namenskonflikte verhindert

Man greift auf verschiedene namespaces über den scope Operator :: zu.

Das ist also das was man macht, wenn man sowas schreibt wie std::string

Ein Beispiel:
*/
#include <iostream>
using namespace std;

// first name space
namespace first_space {
   void func() {
      cout << "Inside first_space" << endl;
   }
}

// second name space
namespace second_space {
   void func() {
      cout << "Inside second_space" << endl;
   }
}

int main () {
   // Calls function from first name space.
   first_space::func();

   // Calls function from second name space.
   second_space::func();

   return 0;
}

/*
zweite nützliche Anwendung) es ermöglicht uns den Code zu vereinfachen. Wenn wir using namespace std; schreiben
dann können wir std:: vor Variablen lassen, was den Code lesbarer macht.

std:: cout können wir dann einfach als cout schreiben :)

*/
