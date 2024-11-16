//
// balance.cpp: use Dollars to compute a balance
//

#include "dollar.h"
#include <iostream>
using namespace std;

#include "dollar.h" // just to see what happens if include twice!

constexpr int EXIT = -10000;

int main() {
  cout << "Enter balance (a float, where $1 is " << CENTS_PER_DOLLAR
       << " cents): ";
  double tmp;
  cin >> tmp;
  Dollars bal(tmp);
  cout << "Enter amount (eof or " << EXIT << " to quit): ";
  cin >> tmp;
  while (cin && (tmp < EXIT - 1 || tmp > EXIT + 1)) {
    bal += Dollars(tmp);
    cout << "Balance: ";
    bal.print(cout);
    cout << endl;
    cout << "Enter amount to add: ";
    cin >> tmp;
  }
  cout << endl;
  cout << "Final balance: ";
  bal.print(cout);
  cout << endl;
  return 0;
}
