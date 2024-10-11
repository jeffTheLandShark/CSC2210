//
// Created by goetschm on 9/10/2024.
//
#include <iostream>
using namespace std;

int main() {
  int array[10];
  float entry;
  for (int i = 0; i < 10 && cin; i++) {
    cin >> array[i];
    if (array[i] > array[i - 1]) {
      cout << "increasing" << endl;
    } else {
      cout << "not increasing" << endl;
    }

  }

}

//Read 10 lab scores (floats) - make the 10 a constant
//Exercise: check lab scores always increasing
//
//    Using the IDE, write code to read lab scores (as floats) until eof
//        Print "increasing" or "not increasing" as appropriate
//        Remember pattern for eof-controlled loop in C++ (following ave.cpp):
//
//                read
//                while not eof
//                   process
//                   read
//
//        Plan for writing loops:
//            Write terminating condition - repeat until x
//            Write while loop header: while !x
//                Use De Morgan's laws:
//                       !(a && b) == !a || !b
//                       !(a || b) == !a && !b
//            Write loop body; make minimal progress each time through
//            Goal: while test will eventually become false
//            Do any setup before the loop, such as initialize variables
//            Do any cleanup after the loop such as closing files
//        Apply to reading data: stop at eof (!cin) or array is full
//        Apply to finding first entry where xi ≤ xi+1 (or run out of items to examin)