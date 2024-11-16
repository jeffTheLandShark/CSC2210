//
// dollar.cpp: implementation of Dollars
//

#include "dollar.h"
#include <cmath>
#include <iostream>
using namespace std;

const int CENTS_PER_DOLLAR = 100;

Dollars::Dollars() : pennies(0) {}

Dollars::Dollars(int d, int p) : pennies(d * CENTS_PER_DOLLAR + p) {}

Dollars::Dollars(double value) {
  if (value >= 0.0)
    pennies = int(value * CENTS_PER_DOLLAR + 0.5);
  else
    pennies = int(value * CENTS_PER_DOLLAR - 0.5);
}

Dollars &Dollars::operator+=(Dollars other) {
  pennies += other.pennies;
  return *this;
}

Dollars &Dollars::operator-=(Dollars other) {
  pennies -= other.pennies;
  return *this;
}

int Dollars::to_pennies() const { return pennies; }

int Dollars::dollars() const { return pennies / CENTS_PER_DOLLAR; }

int Dollars::cents() const { return pennies % CENTS_PER_DOLLAR; }

void Dollars::print(ostream &out) {
  out << dollars() << ".";
  if (abs(cents()) < 10)
    out << '0';
  out << abs(cents());
}

Dollars operator+(Dollars a, Dollars b) {
  a += b;
  return a;
}

Dollars operator-(Dollars a, Dollars b) {
  a -= b;
  return a;
}
