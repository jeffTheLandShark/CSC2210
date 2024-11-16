// slist.cpp: simply-linked list with the big 5

#include <iostream>
using namespace std;

class SList {

  class SNode { // can nest classes; note this is private
  public:
    string item;
    SNode *next;
    SNode(string it, SNode *n = nullptr) // default value
        : item{it}, next{n} {}
  } *front, *tail; // note * applies only to next item

public:
  SList() { front = tail = nullptr; }

  bool empty() const { return front == nullptr; }

  void push_front(string x) {
    if (front)
      front = new SNode(x, front);
    else {
      front = tail = new SNode(x);
    }
  }

  void push_back(string x) {
    if (empty())
      push_front(x);
    else {
      tail->next = new SNode(x);
      tail = tail->next;
    }
  }

  string take_front() {
    if (empty())
      throw "error: no first element of empty list";
    string result = front->item;
    SNode *tmp = front->next;
    delete front;
    front = tmp;
    if (empty())
      tail = nullptr;
    return result;
  }

  void clear() {
    while (!empty())
      take_front();
  }

  // extend list by adding copies of source
  SList &operator+=(const SList &src) {
    if (src.front != nullptr) {
      SNode *tmp = src.front;
      SNode *stop = src.tail; // guard against a += a;
      while (tmp != stop) {
        push_back(tmp->item);
        tmp = tmp->next;
      }
      push_back(stop->item); // add last item (requires that list not be empty)
    }
    return *this;
  }

  // the big 5:

  ~SList() { clear(); }

  SList(const SList &src) {
    front = tail = nullptr;
    *this += src;
  }

  SList &operator=(const SList &src) {
    if (this != &src) {
      clear();
      *this += src;
    }
    return *this;
  }

  SList(SList &&src) {
    front = src.front;
    tail = src.tail;
    src.front = src.tail = nullptr;
  }

  SList &operator=(SList &&src) {
    if (this != &src) {
      front = src.front;
      tail = src.tail;
      src.front = src.tail = nullptr;
    }
    return *this;
  }
};

SList operator+(SList a, const SList &b) {
  a += b;
  return a;
}

void print(SList items) {
  while (!items.empty())
    cout << items.take_front() << endl;
}

int main() {
  SList x;
  x.push_back("jane");
  x.push_back("paul");
  SList y = x; // copy constructor
  print(y);    // copy constructor for value parameter
  cout << "Doubled and doubled again:" << endl;
  y = x + x; // move constructor called to transfer from tmp (x+x) to y
  y += y; // make sure can add self to end of self (naive implementation gives
          // infinite loop)
  print(y);
}
