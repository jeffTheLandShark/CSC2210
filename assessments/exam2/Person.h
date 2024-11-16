//
// Created by goetschm on 11/4/2024.
//

#ifndef PERSON_H
#define PERSON_H
#include <string>


class Person {
private:
  std::string* name;
  int age;

public:
  Person(const std::string& inputName = "", int inputAge = 0) {
    name = new std::string(inputName);
    age = inputAge;
  }
  Person& operator=(const Person& original);
  void print();
  void setName(const std::string& inputName);
  // Other member functions...
};



#endif //PERSON_H
