#include <iostream>
#include <string>
#include <vector>

const std::vector<std::string> ckeywords = {"auto", "double", "schmarrn", "int", "while"};

int main(void) {
  int len = 0;
  for(auto i = ckeywords.begin(); i != ckeywords.end(); i++) {
    len += (*i).size();
  }
  std::cout << len << std::endl;
}
