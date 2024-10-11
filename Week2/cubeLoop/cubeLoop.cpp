//
// Created by goetschm on 9/9/2024.
//

#include <iostream>
using namespace std;
int cube(int);

int main() {
  cout << "Enter an integer: ";
  int number;
  cin >> number;
  while (cin) {
    cout << "The cube of " << number << " is " << cube(number) << endl;
    cout << "Enter an integer: ";
    cin >> number;
  }
  return 0;
}

int cube(int num) {
  return num * num * num;
}