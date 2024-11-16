#include "myString.h"

#include <iostream>

#include <string>

using namespace std;
void printName(myString copy) {
  cout << "Copy: " << copy << endl;
  copy[0] = 'H';
  cout << "Copy: " << copy << endl;
}

int main(int argc, char **argv) {
  myString firstname = "Sohum";
  myString lastName = "Sohoni";
  myString middleInitial = 'A';

  cout << firstname << lastName << endl;

  printName(firstname);

  cout << "The first character of " << firstname << " is " << firstname[0]
       << endl;

  middleInitial[0] = 'a';

  cout << "New middle initial is " << middleInitial << endl;

  myString newName = "Max";
  myString newLastName = "Min";
  cout << newLastName << endl;

  newLastName += newName;
  cout << newName << endl;
  cout << newLastName << endl;

  myString partName = firstname + middleInitial;
  cout << partName << endl;
  myString fullName = firstname + " " + middleInitial + " " + lastName;
  cout << fullName << endl;
  return 0;
}
