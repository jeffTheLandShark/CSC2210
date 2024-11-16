#include <cmath>
#include <iostream>
#include <stdint.h>

#include "FloatVector.h"
#include "Person.h"

void inverse_square(float *y) {
  *y = 1.0 / (*y * *y);
  std::cout << *y << std::endl;
}

void set_first_two(FloatVector &values) {
  values.at(0) = 3.5;
  values.at(1) = values.at(0) + 5.0;
  std::cout << "Values: ";
  values.dump();
  std::cout << std::endl;
}


int main() {
  int x1 = sizeof(int16_t);
  std::cout << x1 << std::endl;

  Person person = Person();
  Person person2 = Person("John", 34);
  person = person2;
  person2.setName("different");
  person.print();

  float x = 1.0;
  float num = sin(x);
  inverse_square(&num);
  // 1.41228
  std::cout << num << std::endl;

  // FloatVector values;
  // set_first_two(values);

  WeightVector xs(10);
  set_first_two(xs);


  return 0;
}

