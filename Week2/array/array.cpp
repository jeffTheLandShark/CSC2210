//
// Created by goetschm on 9/9/2024.
//

#include <iostream>
using namespace std;

void readArray(int[], int);
void printArray(int[], int);

int main() {
  cout << "Please enter an array size: ";
  int size;
  cin >> size;
  if (size > 0) {
    int array[size];
    readArray(array, size);
    printArray(array, size);
  }
  return 0;
}

void readArray(int array[], int size) {
  int input;
  for (int i = 0; i < size; i++) {
    cout << "please enter element " << i << endl;
    cin >> input;
    array[i] = input;
  }
}

void printArray(int array[], int size) {
  cout << "[";
  for (int i = 0; i < size - 1; i++) {
    cout << array[i] << ", ";
  }
  cout << array[size - 1] << "]" << endl;
}

