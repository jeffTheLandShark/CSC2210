// example of iterating over a list
//
// build with: g++ -std=c++11 list_iterator.cpp
// expected output:
//      one two three four
//      one two 3 four

#include <algorithm>
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
  list<string> words; // note this code would work with vector<iterator>, etc.
  words.push_back("one");
  words.push_back("two");
  words.push_back("three");
  words.push_back("four");

  cout << "Counting: ";
  for (auto w : words)
    cout << w << " ";
  cout << endl;

  // cannot index a list
  cout << "First, last words: " << words.front() << ", " << words.back()
       << endl;

  // find "three" and change it to "3":
  auto wordlist_iterator = words.begin();
  while (wordlist_iterator != words.end() && *wordlist_iterator != "three")
    ++wordlist_iterator;
  if (wordlist_iterator != words.end())
    *wordlist_iterator = "3";
  // alternative way, this time with 2, but using find from <algorithm>
  auto two_spot = find(words.begin(), words.end(), "two");
  *two_spot = "2";

  // print list, this time using explicit iteration:
  cout << "Words after replacing two by 2, three by 3: ";
  for (auto wit = words.begin(); wit != words.end(); ++wit)
    cout << *wit << " ";
  cout << endl;

  return 0;
}
