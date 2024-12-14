/*
 * Name       : main.cpp
 * Author     : Leigh Goetsch
 * Exercise   : ex6
 */

#include <iostream>

int main() {
  float input;
  std::cout << "Enter a floating-point number: ";
  std::cin >> input;

  uint32_t *bits_pointer = reinterpret_cast<uint32_t *>(&input);
  uint32_t value = *bits_pointer;

  std::cout << "Input: " << input << ", hex 0x";
  ;
  std::cout << std::hex << value << std::endl;

  uint32_t matissa = value & 0x007FFFFF;
  bool overHalf = (matissa & 0x00400000) && (matissa & 0x003FFFFF);

  if (overHalf) {
    std::cout << "mantissa is greater than a half" << std::endl;
  } else {
    std::cout << "mantissa is a half or less" << std::endl;
  }
  return 0;
}
