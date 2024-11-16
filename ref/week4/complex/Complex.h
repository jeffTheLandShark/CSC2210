//
// Created by sohoni on 9/30/2024.
//

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
  double real;
  double imag;

public:
  Complex();                         // 0 + 0i
  Complex(double real);              // real + 0i
  Complex(double real, double imag); // real + imag*i

  double getReal() const; // so what is this const here?
  double getImag() const;

  Complex add(Complex other) const;
  Complex subtract(Complex other) const;

  // think of this as like the toString method in Java
  void
  print(std::ostream &os) const; // takes a reference to an object of type
                                 // std::ostream (so we can send cout to it)

  void operator++(
      int) { // notice that the argument is of type int and is actually ignored
    real++;
    imag++;
  }

  void operator--(int) {
    real--;
    imag--;
  }
  Complex operator+(Complex const &obj) const;
  /*    Complex operator - (Complex const & obj) const {
          return Complex(real - obj.real, imag - obj.imag);
      }
  */
};

#endif // COMPLEX_H
