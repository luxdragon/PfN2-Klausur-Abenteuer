/*
Fragenkatalog 2022 Aufgabe 3.6
*/

#include<iostream>
#include<string>
#include<math.h>

class Complex{
  private:
    int real, imag;
  
  public:
    Complex(int r, int i){
      real = r;
      imag = i;
    }

    std::string to_string() const{
      return std::string("(")+ std::to_string(real) + std::string("+") + std::to_string(imag) + std::string("i)");
    }

    inline double absolute(void) const {
      return sqrt((real * real) + (imag * imag));
    }

    inline Complex operator*(const Complex &other) const{
      int r = this->real * other.real - this->imag * other.imag;
      int i = this->imag * other.real + this->real * other.imag;
      return Complex(r,i);
    }
};

