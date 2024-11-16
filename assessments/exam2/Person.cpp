//
// Created by goetschm on 11/4/2024.
//

#include "Person.h"

#include <iostream>
#include <ostream>

Person &Person::operator=(const Person &original) {
  if (this != &original) {
    this->name = new std::string(*original.name);
    this->age = original.age;
  }
  return *this;
}

void Person::setName(const std::string &inputName) {
  *name = inputName;
}



void Person::print() {
  std::cout << "Name: " << *this->name << std::endl;
  std::cout << "Age: " << this->age << std::endl;
}