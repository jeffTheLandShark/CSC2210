// try to comment out the include on complex.h
#include "Complex.h"
#include <iostream>

using namespace std;

Complex addOne(const Complex &number);
Complex operator-(const Complex &lhs, const Complex &rhs);
int main() {
  // create a Complex object on the stack (local variable)
  Complex zero;
  Complex *ptr = &zero;
  cout << "ptr is a pointer to zero" << endl;
  cout << "the value of ptr is the address of zero: ";
  cout << ptr << endl;

  int size = sizeof(Complex);
  cout << "size of complex number is " << size << " bytes" << endl;
  cout << "Complex number zero is ";
  zero.print(cout);
  cout << endl;

  // create a Complex object on the heap (dynamic memory allocation)
  Complex *a = new Complex(1);
  // try removing the * in the line below- it will return the size of the
  // pointer itself
  int sizeOfComplex = sizeof(*a);
  cout << "Complex number a is ";
  a->print(cout);
  cout << " and its size is " << sizeOfComplex << endl;

  Complex b{3, 5.5};
  cout << "Complex number b is ";
  b.print(cout);
  cout << endl;

  // a is a pointer, so we use the arrow operator to call a member method add
  // add takes a Complex object as a parameter and returns another Complex
  // object and we can call print on the returned object
  cout << "a + b = ";
  a->add(b).print(cout);
  cout << endl;

  // addOne will return a Complex object and takes a Complex object as a
  // parameter. We deference a here. what if we send a instead of *a? Can we
  // send b?
  cout << "a addOne is ";
  addOne(*a).print(cout);
  cout << endl;
  cout << "a is ";
  a->print(cout);
  cout << endl;
  cout << "b is ";
  b.print(cout);
  cout << endl;

  b++;
  cout << "b++ is ";
  b.print(cout);
  cout << endl;

  Complex c = *a + b;
  cout << "c is ";
  c.print(cout);
  cout << endl;

  Complex d = *a - b;
  cout << "d is ";
  d.print(cout);
  cout << endl;

  // free up the memory allocated for Complex object a
  delete a;
  return 0;
}

// adds 1 to the real part of the complex number
// the parameter const Complex& takes the Complex object by reference with the
// promise that we will not change it try removing the const after the add
// method in Complex.h and Complex.c and see what happens
Complex addOne(const Complex &number) {
  Complex one(1);
  return number.add(one);
}

// this is an example if overloading outside of the class, i.e. not as a member
// function
Complex operator-(const Complex &lhs, const Complex &rhs) {
  return Complex(lhs.getReal() - rhs.getReal(), lhs.getImag() - rhs.getImag());
}
