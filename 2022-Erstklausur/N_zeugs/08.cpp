/*
Wir hatten zwar nie maps und schon gar nicht mit 2 keys, aber whatever right?

pair Funktion zum erstellen eines keys benutzt

Nach meinem Geschmack viel zu viel spezieller Kram den man sich jetzt noch merken muss

Nach dieser Aufgabe min. 3 graue Haare mehr, wie soll man sich das mit unserem Wissen man kurz in der Klausur ausdenken?
*/

#include<iostream>
#include<map>
#include<cassert>

class SparseMatrix{
  private:
    std::map<std::pair<size_t,size_t>, int> non_zero_values; // map mit 2 keys

  public:
    SparseMatrix(void){  //Konstruktor
      non_zero_values; //sehr wichtig, dass die map hier initialisiert wird
    }
    void set(size_t r, size_t c, int value){ // alle set funktionieren
      std::pair<size_t, size_t> key;
      key.first = r;
      key.second = c;
      non_zero_values[key] = value;
    }

    int get(size_t r, size_t c) const{
      std::pair<size_t, size_t> key; // key wieder zusammenbauen
      key.first = r;
      key.second = c;
      auto found = non_zero_values.find(key); // .find() erstellt iterator und geht über die map bis zum Ende
      if(found == non_zero_values.end()){ //Was nicht in der SparseMatrix ist, wäre ja 0 in der "echten" Matrix. Deswegen das if
        return 0;
      }
      int res = found->second;
      return res;
    }
};

int main(void){
  SparseMatrix m{};

  const size_t rows = 5, columns = 5;
  for(size_t r = 0; r < rows; r++){
    m.set(r,r,static_cast<int>(r+1));
  }
  for(size_t r = 0; r < rows; r++){
    for(size_t c = 0; c < columns; c++){
      if(r == c){
        assert(m.get(r,c) == static_cast<int>(r+1));
      }
      else{
        assert(m.get(r,c) == 0);
      }
    }
  }
}
