#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class myString {
private:
  char *characters;
  unsigned int length;

  /* Why did we design this with a char * and not an array?
   * We don't know how big the string is going to be, It's only at runtime that
   * we will know the size which is why at this time, we can just say that we
   * have a pointer to point to an array of chars
   */
public:
  myString();
  myString(char ch); // constructor that takes in a single character
  myString(
      const char *string); // constructor that takes in an array of characters
  /* Why is the char * string above a const?
   * because the constructor makes a new array and copies characters into that
   * new array without modifying the string that was passed in. by calling it a
   * const char pointer, we are making sure that the string passed in is not
   * modified
   */

  myString(const myString &original); // copy constructor

  /* overloading the assignment operator
   * This will cover the important topic of making a deep copy as opposed to
   * either a shalow copy or (even worse) just pointing a pointer somewhere else
   */

  myString &operator=(const myString &original);

  unsigned int size() const { return length; }
  // What does the const above indicate?
  // method does not modify the member variables

  myString &operator+=(const myString &rhs);

  /* Why do we have a const and a non-const version of overloading []?
   * Becuse we could have this used either on the left hand side or the right
   * hand side of an assignment In one case, when we have myStringObj[0] = 'a',
   * so shoudl not be const But in the other, where char c = myStringObj[2]
   * should be const
   */

  char &operator[](int index);
  const char &operator[](int index) const;

  ~myString(); // tilde ~ or tilda ~ is considered the complement, destructor is
               // opposite of constructor
};

/* Why are the definitions below outside of the class definition?
 * when we define an operator overload inside a class definition, the left hand
 * operand will be the object of that class. So we would get x << cout instead
 * of what we want. The way this is currently set up, we have the myString
 * references on the lhs, and the ostream and istream objects on the rhs. We are
 * also returning a reference to the corresponding object from this overload
 */

std::ostream &operator<<(std::ostream &out, const myString &rhs);
std::istream &operator>>(std::istream &in, myString &rhs);

// Why is the myString reference for >> not a const?
// Because we are inserting characters into this string, and the string will
// thus be modified

bool operator==(const myString &lhs, const myString &rhs);
bool operator!=(const myString &lhs, const myString &rhs);

myString operator+(myString lhs, const myString &rhs);
// what will happen if I make the lhs const above?
// why is this returning a myString object and not a myString reference?

#endif // MYSTRING_H
