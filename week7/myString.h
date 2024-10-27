//
// Created by goetschm on 10/22/2024.
//

#ifndef MYSTRING_H
#define MYSTRING_H

class myString {
private:
    char * characters;
    unsigned int length;
public:
      myString();
      myString(char ch); // single character
      myString(const char * string); // array of characters
      // why is the char * string above a const?

      myString(const myString& original); // copy constructor

      myString& operator=(const myString& original);

      unsigned int size() const {
        return length;
        }

        myString& operator+=(const myString& rhs);

        char& operator[](int index);
        char operator[](int index) const;

};



#endif //MYSTRING_H
