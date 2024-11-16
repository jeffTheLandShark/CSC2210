#include "myString.h"
#include <cstring>
#include <iostream>

myString::myString() : characters(new char[0]), length(0) {}

// constructor that takes in a single character
myString::myString(char ch) : characters(new char[1]), length(1) {
  //  this->characters = new char[1];
  //  this->length = 1;
  characters[0] = ch;
}

// constructor that takes in an array of characters
myString::myString(const char *inputString) {
  length = strlen(inputString); // + 1;
  characters = new char[length];
  for (int i = 0; i < length; i++) {
    characters[i] = inputString[i];
  }
  // characters[length - 1] = '\0'; //adding the null terminating character so
  // that we don't get an unending string
}

// copy constructor. the one that the compiler provides makes a shallow copy.
// this one makes a deep copy
/* The copy constructor is called every time we pass an object by value
 * There are other places this might get called
 */

myString::myString(const myString &original)
    : characters(new char[original.length]), length(original.length) {
  for (int i = 0; i < length; i++) {
    characters[i] = original.characters[i];
  }
}

// assignment operator also needs to make a deep copy
myString &myString::operator=(const myString &original) {
  if (this != &original) {
    delete[] characters; // think of a = b; a already has a pointer to an array
                         // of chars
    characters = new char[original.length];
    length = original.length;
    for (int i = 0; i < length; i++) {
      characters[i] = original.characters[i];
    }
  }
  return *this; // remember, this is a pointer in C++, so we need to dereference
                // it
}

// What do we want the [] operator to do for myString? we want it to return the
// character at that index
char &myString::operator[](int index) { return characters[index]; }

// The const version of this is used on the rhs: char something =
// mystringObject[index];
const char &myString::operator[](int index) const { return characters[index]; }

bool operator==(const myString &lhs, const myString &rhs) {
  if (lhs.size() == rhs.size()) {
    for (int i = 0; i < lhs.size(); i++) {
      if (lhs[i] != rhs[i]) {
        return false;
      }
    }
    return true;
  }
  return false;
}

bool operator!=(const myString &lhs, const myString &rhs) {
  return !(lhs == rhs);
}

// Note that this function requires us to have overloaded the [] operator since
// we use it here

myString &myString::operator+=(const myString &rhs) {
  char *result = new char[length + rhs.length]; // create an array that is big
                                                // enough for the concatenation
  for (int i = 0; i < length; i++) {
    result[i] = characters[i]; // copy the characters of this
  }
  for (int i = 0; i < rhs.length; i++) {
    result[length + i] = rhs[i]; // copy the characters of the object passed in
                                 // after characters of this
  }
  length += rhs.length;
  characters = result; // unless we overload = to make a deep copy, this will be
                       // a shallow copy
  return *this;        // this is a pointer in C++, so we need to dereference it
}

/* The + overload is just one line, but it is important to note that we are
 * returning the value of the string, and not a reference. More importantly, the
 * parameter lhs that we take in is also not coming in as a reference
 */
myString operator+(myString lhs, const myString &rhs) { return lhs += rhs; }

// Note that this function requires us to have overloaded the [] operator since
// we use it here
std::ostream &operator<<(std::ostream &out, const myString &rhs) {
  for (int i = 0; i < rhs.size();
       i++) {      // cannot use rhs.length unless we declare this function as a
                   // friend function
    out << rhs[i]; // insert character by character into out
  }
  out << std::flush;
  return out;
}
// Why do we return a reference to an ostream object in the function above?
/* We take this reference as the lhs parameter and the refernce to our string
 * object as the rhs after that, we want to insert the characters from our
 * stream into whatever is already there in the ostream object. After we are
 * done, we want to return a reference to this object, because something else
 * could have this whole thing as its lhs Example: cout << myStringObject <<
 * endl; In this example, endl will be inserted into the stream after we have
 * inserted our object.
 */

// Note that this requires the += operator and the = to be overloaded for
// myString By definition, leading whitespaces should be dropped while reading
// in input
std::istream &operator>>(std::istream &in, myString &rhs) {
  char ch;
  myString input;
  while (isspace(in.peek())) { // get rid of leading whitespaces
    in.get();
  }
  while (
      !isspace(in.peek())) { // read in all characters up to the next whitespace
    input += in.get();
  }
  rhs = input; // use the reference to the myString object where we wanted
               // insert the characters we are reading in
  return in;   // again, we return a reference to in, so that reading inputs can
               // be chained
}

myString::~myString() {
  delete[] characters; // freeing up the memory for the array created in the
                       // constructor
  std::cout << "characters destroyed" << std::endl;
}
