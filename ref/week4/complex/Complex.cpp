//
// Created by sohoni on 9/30/2024.
//

#include "complex.h"
// note the difference between quotes vs angled brackets in the #include
#include <iostream>

// the :: specifies ownership. stuff following the :: is a member of the class
// on the left of ::
Complex::Complex() : real(0), imag(0) { // 0 + 0i
}

// second constructor shows calling another constructor
Complex::Complex(double real) : Complex(real, 0) { // real + 0i
}

// third constructor shows how we can assign using arrow operator
// try changing the arrow to a dot and see what happens
Complex::Complex(double real, double imag)
//    :real(real), imag(imag)
{ // real + imag*i
  this->real = real;
  this->imag = imag;
}

double Complex::getReal() const { return real; }

double Complex::getImag() const { return imag; }

// returns a new Complex object named result; takes a Complex object named other
Complex Complex::add(Complex other) const {
  Complex result(real + other.real, imag + other.imag);
  return result;
}

// similar to add. We are directly returning the object returned by the
// constructor without naming it as in add
Complex Complex::subtract(Complex other) const {
  return Complex(real - other.real, imag - other.imag);
}

// why not use cout right here? why the complicated passing of an ostream
// object? because we will be able to use the same print function and print to
// file or any other output stream that we choose without having to make changes
// inside the print function
void Complex::print(std::ostream &os) const {
  os << getReal() << " + " << getImag() << "i" << std::flush;
}

Complex Complex::operator+(Complex const &obj) const {
  Complex result;
  result.real = real + obj.real;
  result.imag = this->imag + obj.imag; // shows that we can use this or directly
                                       // use the name of the member variable
  return result;
}
