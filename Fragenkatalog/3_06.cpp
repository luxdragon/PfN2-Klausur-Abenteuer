/*
Innerhab der Klasse sollen die beiden Methoden als inline Methoden
implementiert werden

inlining wird auf Folie 15 cpp_slides "erklärt"

In den Screencasts von 2021 überspringt er inlining natürlich


Ich hoffe das ist das was gefragt war, im Bezug auf inline
*/


#include <cstdio>
#include <math.h>
#include <string>
#include <iostream>


class Complex {
  private:
    int real, imag;
  public:
    Complex(int r,int i) {
    real = r;
    imag = i;
  }
  std::string to_string() const { // ist Funktion zur schönen Darstellung einer Instanz der Klasse Complex
    return std::string("(") + std::to_string(real) + std::string("+") + std::to_string(imag) + std::string("i)");
  }

  inline double absolute(void) const{
    double abs = sqrt(real* real + imag * imag);
    return abs;
  }

  inline Complex operator* (const Complex &other) const { // hier wird der operator * überladen; (vielleicht sollte man auch sagen der Operator *())
    int x = real * other.real - imag * other.imag;
    int y = imag * other.real + real * other.imag;
    Complex c = Complex(x,y); // durch die neu definierte Multiplikation wird also eine neue Instanz der Klasse complex erstellt und zurückgegeben
    return c; //kurtzgesagt
  }


};

int main(void){
  Complex a = Complex(2,4);
  std::cout << a.absolute() << std::endl;


  Complex b = Complex(3,1);

  std::cout << a.to_string() << "*" << b.to_string()   << "=" << (a * b).to_string() << std::endl;

}
