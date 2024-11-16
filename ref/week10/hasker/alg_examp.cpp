//
// alg-examp.cpp: example code using <algorithm>
//

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void dump(int i) { cout << i << ' '; }
bool odd(int i) { return i % 2 == 1; }
bool greaternum(const int &a, const int &b) { return a > b; }

int main() {
  vector<int> v(10);                  // 10 integers
  generate(v.begin(), v.end(), rand); // fill with random numbers
  cout << "Original list: ";
  for_each(v.begin(), v.end(), dump); // print original
  cout << endl;
  replace_if(v.begin(), v.end(), odd, 0); // replace odds by 0
  sort(v.begin(), v.end(), greaternum);   // sort descending
  cout << "New list: ";
  for_each(v.begin(), v.end(), dump); // print new
  cout << endl;
  return 0;
}

// output (on laptop):
//  Original list: 41 18467 6334 26500 19169 15724 11478 29358 26962 24464
//  New list: 29358 26962 26500 24464 15724 11478 6334 0 0 0
