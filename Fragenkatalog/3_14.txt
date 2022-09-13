/*
Für binary trees: c_slides.pdf Folie 351 und folgende

Wilde Aufgabe, wenn man sie kontrollieren möchte und dafür die Klasse zum
laufen bringen will. Das habe ich natürlich gemacht. Würde ich aber nicht
empfehlen :D

Die Idee ist: 
Eine neue Member-Variable counts der Klasse erstellen, die die Knoten zählt.
Eine Methode size() implementieren, die eine private Methode size_rec aufruft.
size_rec kann man analog zu print_rec erstellen, weil beide das gleiche tun:
Den Baum durchgehen. Dabei muss man hochzählen.
Das ist auch der Grund, warum counts nicht in der Methode selber definiert
werden kann, da die Methode dadurch, dass sie sich selber aufruft, immer wieder
counts = 0 setzen würde.




Warum einfach, wenn es auch schwer geht???
Es sei hier erwähnt, dass das Ziel der Aufgabe viel leichter zu erreichen wäre,
wenn man counts hochzählt. Nämlich genau dann wenn die Methode die einen Knoten
erstellt aufgerufen wird. Aber was weiß ich schon.
Oh well...

*/


/* ##### gegebene Klasse #####
   ##### mit zusätzlichen gefragten Methoden ##### */


#include<iostream>
#include<cstdlib>
#include<cassert>

template<typename T>
class Bintree
{
  struct Node {
    Node *left, *right;
    size_t count;
    T data;
    Node(const T &_data) // was macht das hier? => initialisiert sich selber? Habe ich ignoriert und dafür eine eigene Methode "new_node" geschrieben
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
  //Node *root;





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



  public:
  Node *root; //um es mir einfacher zu machen, habe ich root public gemacht

  Bintree(void) : root(nullptr) {} //Konstruktor; erstellt die root des bin trees (alse den ersten Node), die dann auf nichts (NULL) zeigt
  
  void print(void) const {
    print_rec(0,root);
  }

  //##### gefragte Methode die rekursive private Methode aufruft #####
  size_t size(void){
    size_t num_nodes = size_rec(root);
    return num_nodes;
  }






//##############################################################################
//##############################################################################

//##### von mir, um Klasse einigermaßen funktionsfähig zu machen; nicht Teil der Lösung!:
// ist jetzt leider erstmal nur so, dass es nur für ints, float usw. funktioniert, nicht für strings oder char *

/* ist eigentlich durch Funktion Node() in struct Node gegeben */
  Node *new_node(T _data){ //fügt generell einen neuen Node zum Tree hinzu
    Node *n =(Node *) malloc(sizeof(*n));
    assert(n != NULL);
    n->data = _data;
    n->count = 1;
    n->left = n->right = NULL;
    return n;
  }

  Node *add_to_tree(Node *n, T _data){ //fügt an die richtige Stelle einen Node dazu, indem new_node mit den richtigen Parametern aufgerufen wird
    if(n == NULL){
      n = new_node(_data); //Zugriff auf Konstruktor in der privaten struct Node
    }
    else{
      if(_data == n->data){
        n->count++;
      }
      else{
        if(_data < n->data){
          n->left = add_to_tree(n->left, _data);
        }
        else{
          n->right = add_to_tree(n->right, _data);
        }
      }
    }
    return n;
  }
  
  void tree_delete(Node *n){ //hier sollte root übergeben werden?
    if(n == NULL){
      return; // nothing to do
    }
    if(n->left != NULL){
      tree_delete(n->left);
    }
    if(n->right != NULL){
      tree_delete(n->right);
    }
    //free(n->data);
    free(n);
  }
};


//##### main, testen, Hilfsfunktionen #####

int main(void){
  Bintree<int> t_tree; //hier wird über das Template ein Objekt der Klasse Bintree für ints erstellt, also ein bin-tree für ints
  /* Es wurde jetzt also ein Tree mit einem Node erstellt: Dem Node root; hier kann man jezt Anfangen Zeug reinzuschreiben*/

  // root ist Aufgabenstellung private, ich habe es hier public gemacht um mir den Aufwand mit get und set Methoden zu sparen

// Das ist jetzt speziell um von stdin beliebig viele int's einlesen zu können, aber natürlich speziell um komfortabel den Tree aus der Aufgabe zu erstellen
// Abbruch erfolgt über das scanf("%d") dann wenn z.b. ein Buchstabe eingegeben wird
  int data;
  std::cout << "Büdde mal ein paar Zahlen nacheinander eingeben, der tree und stefan würden sich darüber sehr freuen " << std::endl;
  while(scanf("%d", &data)== 1){
    t_tree.root = t_tree.add_to_tree(t_tree.root, data);
  }

  t_tree.print();
  

  /* Ausgabe, wenn man 5,3,1,3,7,9 eingibt und Eingabe durch Eingabe eines Buchstabens abbricht:
      5
      2
      1
      3
      7
      9
      c
            9 1
        7 1
      5 1
            3 1
        2 1
            1 1

    die Einsen sind die counts. => Das Zeug das ich hier gemacht habe tut das was es soll
  */
  size_t n_num = t_tree.size();
  std::cout << "Anzahl der Knoten im tree: " << n_num << std::endl;
  

  t_tree.tree_delete(t_tree.root);
}


