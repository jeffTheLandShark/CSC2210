//
// Created by deald on 10/28/2024.
//
#ifndef BOARD_H
#define BOARD_H
#include <string>
class Cell;
class Player;
class Board {
public:
  Board();
  void display();
  bool checkWin();
  void playerTurn(Player player, int index);
  int getTurn();

private:
  Cell **cells;
  int turn;
};
class Cell {
public:
  Cell(int index);
  bool addSymbol(Player player);
  void display();
  char getSymbol();

private:
  char symbol;
  int index;
};
class Player {
public:
  Player(char symbol);
  char getSymbol();
  void display();

private:
  char symbol;
};
#endif // BOARD_H