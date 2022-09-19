/*
Für binary trees: c_slides.pdf Folie 351 und folgende

Für mehr Erklärungen und funktionierendes Programm zum Testen (mit Ausgabe)
siehe 3_14.txt!

Die Idee ist: 
Eine neue Member-Variable counts der Klasse erstellen, die die Knoten zählt.
Eine Methode size() implementieren, die eine private Methode size_rec aufruft.
size_rec kann man analog zu print_rec erstellen, weil beide das gleiche tun:
Den Baum durchgehen. Dabei muss man hochzählen.
Das ist auch der Grund, warum counts nicht in der Methode selber definiert
werden kann, da die Methode dadurch, dass sie sich selber aufruft, immer wieder
counts = 0 setzen würde.
*/



template<typename T>
class Bintree
{
  struct Node {
    Node *left, *right;
    size_t count;
    T data;
    Node(const T &_data)
    : left(nullptr), right(nullptr), count(1), data(_data)
    {}
  };

  void print_rec(size_t d,const Node *node) const {
    if (node != nullptr) {
      print_rec(d+1,node->right);
      for (size_t i = 0; i < 3*d; i++) std::cout << " ";
      std::cout << node->data << " " << node->count << std::endl;
      print_rec(d+1,node->left);
    }
  }
  Node *root;



//------------------------------------------------------------------------------------------------------------------
//##### gefragte rekursive private Methode #####

// um zu zählen implementiert man am besten einfach eine zusätzliche Member-Variable
  size_t count = 0;

/* man kann sich hier sehr gut an der print_rec Methode orientieren, weil diese
   genau das gleiche macht, nämlich alle Nodes abgehen */
   
  size_t size_rec(const Node *node){
    if(node != nullptr){ // wenn node nicht leer ist, ist schon mal mindestens ein Knoten vorhanden
      count++; //mit jeden Aufruf ist sichergestellt, dass noch ein Knoten vorhanden ist
      size_rec(node->right);
      size_rec(node->left);
    }
    return count;
  }
//------------------------------------------------------------------------------------------------------------------


  public:
  Node *root; //um es mir einfacher zu machen, habe ich root public gemacht

  Bintree(void) : root(nullptr) {}
  
  void print(void) const {
    print_rec(0,root);
  }


//------------------------------------------------------------------------
  //##### gefragte Methode die rekursive private Methode aufruft #####
  size_t size(void){
    size_t num_nodes = size_rec(root);
    return num_nodes;
  }
//------------------------------------------------------------------------
