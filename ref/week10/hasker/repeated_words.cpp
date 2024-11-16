// C++ program using STL to display repeated words and count number of
//   unique words in input

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  set<string> words_seen;
  string next_word;
  cin >> next_word;
  while (cin) {
    if (words_seen.count(next_word) > 0)
      cout << "Repeated word: " << next_word << endl;
    else
      words_seen.insert(next_word);
    cin >> next_word;
  }
  cout << "Number of unique words: " << words_seen.size() << endl;
  return 0;
}
