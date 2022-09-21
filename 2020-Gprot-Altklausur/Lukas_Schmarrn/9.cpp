/* #include <iostream>
#include <vector>

std::vector<std::string> trauer;
trauer = {"blfg", "ich will eine gute Note", "aber Kurtz will sie mir nicht geben"};

for (i = trauer.begin(); i != trauer.end(); i++) {
  std::cout << *i;
} */

#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> trauer = {"blfg", "ich will eine gute Note", "aber Kurtz will sie mir nicht geben"};

for (auto i = trauer.begin(); i != trauer.end(); i++) {
  std::cout << *i << std::endl;
}
