//
// Created by goetschm on 11/5/2024.
//

#ifndef INTSTACK_H
#define INTSTACK_H


class IntStack {
public:
  IntStack() : height(0) {
  }

  void push(int x) {
    items[height] = x;
    ++height;
  }

  int pop() {
    height--;
    return items[height];
  }

  int top() const { return items[height - 1]; }
  int size() const { return height; }
  bool isEmpty() const { return height <= 0; }
  bool isFull() const { return height >= 50; }

protected:
  int height;
  int items[50];
};

template<typename ItemType>
class Stack {
protected:
  int height;
  ItemType items[50];

public:
  Stack() : height(0) {
  }

  void push(const ItemType &x) {
    items[height] = x;
    ++height;
  }

  ItemType pop() {
    height--;
    return items[height];
  }

  ItemType top() const { return items[height - 1]; }
  int size() const { return height; }
  bool isEmpty() const { return height <= 0; }
  bool isFull() const { return height >= 50; }
};


#endif //INTSTACK_H
