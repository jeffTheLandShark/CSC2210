//
// Created by goetschm on 10/22/2024.
//

#include "myString.h"
#include <stdio.h>
myString::myString(): characters(new char[0]), length(0){}

myString::myString(char ch) : characters(new char[1]), length(1){
  characters[0] = ch;}

myString::myString(const char * inputString){
  length = strlen(inputString);
  characters = new char[length];
  for (int i = 0; i < length; i++) {
    characters[i] = inputString[i];
    }
}

myString::myString(const myString& original)
    : characters(new char[length]), length(original.length){
  characters = new char[length];
  for (int i = 0; i < length; i++) {
    characters[i] = original.characters[i];

   }
}

myString & myString::operator=(const myString& original){
  if (this != &original) {
    delete[] characters;
    characters = new char[original.length];
    for (int i = 0; i < length; i++) {
      characters[i] = original.characters[i];
    }
    return *this;
  }
}