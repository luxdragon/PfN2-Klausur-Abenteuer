#include <iostream>

class Protein {
  private:
    char name[];
    size_t length;
  public:
    void name_set(char *name);
    void length_set(size_t length);
    char *name_get(void);
    size_t length_get(void);
    //Konstruktor
    Protein(char *x, size_t y) {
      name = x; //sollte wahrscheinlich mit new dynamisch alloziert werden
      length = y;
    };
    ~Protein(void) {
      delete[] name; //nur für dynamisch alloziertes Schmarrn
      //das auch?
    };

}
