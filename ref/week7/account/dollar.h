//
// dollar.h: money handled the better way
//

#ifndef _dollar_h
#define _dollar_h

#include <iostream>

// declare CENTS_PER_DOLLAR
// extern means it can be accessed from multiple compilation units
// constexpr will not work for this - constexpr only works with definitions
extern const int CENTS_PER_DOLLAR;

//
// capture information about (American) dollars and cents
//
class Dollars {
public:
  Dollars();
  Dollars(int d, int p);
  Dollars(double value);

  Dollars &operator+=(Dollars other);
  Dollars &operator-=(Dollars other);

  int to_pennies() const;
  int dollars() const;
  int cents() const;

  // note: must past ostream by reference since writing to it modifies it
  void print(std::ostream &);

protected:
  int pennies;
};

// prototypes for adding, subtracting dollar amounts
Dollars operator+(Dollars a, Dollars b);
Dollars operator-(Dollars a, Dollars b);

#endif
