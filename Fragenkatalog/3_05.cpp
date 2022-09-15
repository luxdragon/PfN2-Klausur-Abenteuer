/*

*/

class Protein{
  private:
    char *name;
    size_t length;
  public:
    void name_set(char *name);
    void length_set(size_t length);
    char *name_get();
    size_t length_get();
    Protein(); //default Konstruktor
    ~Protein(); //default Destruktor
};
