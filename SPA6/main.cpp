// main driver for testing shareable_string class

#include "cow_string.h"
#include <iostream>

using namespace std;

void check_expected(const cow_string &s, int position, char target) {
  if (s[position] != target)
    cout << "Unexpected character " << s[position] << " at position "
         << position << endl;
}

int main() {
  {
    cow_string a("first"), b("second"), c("third"), d("fourth");

    cout << "Initial a[0]: " << a[0] << endl;
    a[0] = 'F';
    d = c = b;
    c[1] = '3';
    c[3] = '0';
    check_expected(d, 0, 's');

    char buffer[100];
    a.get_inspection_data(buffer);
    cout << "Variable a: " << buffer << endl;
    b.get_inspection_data(buffer);
    cout << "Variable b: " << buffer << endl;
    c.get_inspection_data(buffer);
    cout << "Variable c: " << buffer << endl;
    d.get_inspection_data(buffer);
    cout << "Variable d: " << buffer << endl;
  }

  cout << "----------------------------------------" << endl;
  if (cow_string::unreleased_bytes() == 0)
    cout << "At end, all allocated data released." << endl;
  else
    cout << "ERROR: there are " << cow_string::unreleased_bytes()
         << " bytes that did not get released.";
  return 0;
}
