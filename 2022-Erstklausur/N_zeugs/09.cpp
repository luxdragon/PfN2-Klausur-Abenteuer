#include<iostream>
#include<vector>
#include<string>

int main(void){
  const std::vector<std::string> ckeywords = {"auto", "double", "int", "unkreativ",
                                              "stefan", "PfN2", "loool", "while"};

  size_t n_words = ckeywords.size();
  std::cout << "Anzahl Schlüsselwörter: " << n_words << std::endl;

  size_t sum = 0;
  for(auto i = ckeywords.begin(); i < ckeywords.end(); ++i){
    sum += (*i).size();
  }
  std::cout << "Summer der Längen: " << sum << std::endl;
}
