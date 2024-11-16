// todo.cpp: todo list as a class
//   Compiles under C++11 and C++17

#include <iostream>
#include <string>
using namespace std;

class ToDo {
public:
  ToDo() : count{0} {}

  ToDo(string first_item) : count{1} { items[0] = first_item; }

  bool empty() { return count <= 0; }

  bool full() { return count >= MAXITEMS; }

  void add(string next_item) {
    if (full())
      throw "Adding item to full todo list.";
    items[count] = next_item;
    ++count;
  }

  string next_item() {
    if (empty())
      throw "Removing item from empty todo list.";
    string result = items[0];
    for (int i = 0; i < count - 1; ++i)
      items[i] = items[i + 1];
    --count;
    return result;
  }

  // returns the next item capitalized; this is to illustrate converting
  //   a string to upper case; use tolower to convert to lower case.
  string next_item_capitalized() {
    string item = next_item();
    // note use of size_t to initialize i; this avoids warnings when
    //   comparing i to item.length() (since item.length() is generally
    //   unsigned)
    for (size_t i = 0; i < item.length(); ++i)
      item[i] = toupper(item[i]);
    return item;
  }

  string operator[](int ix) {
    if (ix < 0 || ix >= count)
      throw "Accessing non-existance item";
    return items[ix];
  }

private:
  static constexpr int MAXITEMS = 100;
  string items[MAXITEMS];
  int count;
};

int main() {
  ToDo today("Eat breakfast."); // can't start a day without eating!
  today.add("Go to class.");
  today.add("Eat lunch.");
  today.add("Show up for office hours.");
  today.add("Go home.");
  cout << "Second added: " << today[1] << endl;
  cout << "Today's list:" << endl;
  while (!today.empty())
    cout << today.next_item() << endl;
  return 0;
}
