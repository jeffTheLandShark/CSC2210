/*
 * SPA 2, Fall 2024, Leigh Goetsch
 */

#include <iostream>
#include <cassert>
using namespace std;

constexpr int MAX_WORDS = 3000; // max words allowed in word list

void run_checks();
bool can_match(string letters, string word, string pattern);

int get_words(string words[]);
int get_guesses(string guesses[], string patterns[]);
int get_matches(string matches[], int num_guesses, string guesses[], int num_words, string words[], string patterns[]);

void print_output(int num_matches, string matches[], int num_guesses, string guesses[]);

// main method
int main() {
  run_checks();

  string words[MAX_WORDS];
  int num_words = get_words(words);
  string guesses[MAX_WORDS];
  string patterns[MAX_WORDS];
  int num_guesses = get_guesses(guesses, patterns);

  string matches[MAX_WORDS];
  int num_matches = get_matches(matches, num_guesses, guesses, num_words, words, patterns);

  print_output(num_matches, matches, num_guesses, guesses);

  return 0;
}

// takes all the word inputs up to END
int get_words(string words[]) {
  for (int i = 0; i < MAX_WORDS; i++) {
    string word;
    cin >> word;
    if (word == "END") {
      return i;
    }
    words[i] = word;
  }
  return MAX_WORDS;
}

// takes in guess / pattern pairs and saves to arrays
int get_guesses(string guesses[], string patterns[]) {
  string guess;
  int i = 0;
  while (cin >> guesses[i] >> patterns[i]) {
    i++;
  }
  return i;
}

// creates a list of matching words
int get_matches(string matches[], int num_guesses, string guesses[], int num_words, string words[], string patterns[]) {
  int num_matches = 0;
  for (int i = 0; i < num_words; i++) {
    bool match = true;
    for (int j = 0; j < num_guesses and match == true; j++) {
      if (!can_match(words[i], guesses[j], patterns[j])) {
        match = false;
      }
    }
    if (match == true) {
      matches[num_matches++] = words[i];
    }
  }
return num_matches;
}

// checks if can_match works
void run_checks() {
  assert( can_match("abcde", "axbxf", ".-\?--"));
  assert(!can_match("abcde", "axbxd", ".-\?--"));
  assert( can_match("abcde", "easty", "\?\?---"));
  assert(!can_match("abcde", "abcdf", "....."));
  assert( can_match("abcde", "uvwxy", "-----"));
}

// if the word is valid according to the guess / pattern pair
bool can_match(string letters, string word, string pattern) {
  for (int i = 0; i < pattern.size(); i++) {
    switch (pattern[i]) {
      case '-': if (letters.find(word[i]) != string::npos) return false;
      break;
      case '.': if (word[i] != letters[i]) return false;
      break;
      case '?': if (word[i] == letters[i] || letters.find(word[i]) == string::npos) return false;
      default: ;
    }
  }
  return true;
}

// print final output
void print_output(int num_matches, string matches[], int num_guesses, string guesses[]) {
  cout << "Possible guesses after ";
  for (int j = 0; j < num_guesses -1; j++) {
    cout << guesses[j] << ", ";
  }
  cout << guesses[num_guesses - 1] << ": " << num_matches << endl;

  for (int i = 0; i < num_matches; i++) {
    cout << matches[i] << endl;
  }
}
