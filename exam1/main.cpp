#include <iostream>




int read_numbers(double num[], int size);

int main() {
  std::cout << "Hello, World!" << std::endl;
  int size = 10;
  double num[size];
  int read = read_numbers(num, size);
  std::cout << read << std::endl;
  return 0;
}

// Write a function read_numbers which takes two arguments, an array of doubles and the maximum size, and fills the array with numbers read from standard input. Assume max size to be 100. The result of the function is to be the number of numbers read. Stop after reading all numbers (end-of-file) or after reading a negative number or when you have reach max size. For full credit, your function must have just one return statement and must use just while and if (that is, you cannot use keywords like break).

int read_numbers(double num[], int size) {
  bool read = true;
  double number;
  int index = 0;
  while (read && std::cin >> number) {
    num[index++] = number;
    if (index > size || number < 0) {
      read = false;
    }
  }
  return index;
}