//
// Created by deald on 10/28/2024.
//
#include "board.h"
#include <iostream>
using namespace std;
Board::Board() {
  turn = 0;
  cells = new Cell *[9];
  for (int i = 0; i < 9; i++) {
    cells[i] = new Cell(i + 1);
  }
}
void Board::display() {
  cout << endl;
  for (int i = 0; i < 9; i++) {
    cells[i]->display();
    if ((i + 1) % 3 == 0) {
      cout << endl;
    }
  }
}
bool Board::checkWin() {
  if (cells[0]->getSymbol() != ' ' &&
      cells[0]->getSymbol() == cells[1]->getSymbol() &&
      cells[0]->getSymbol() == cells[2]->getSymbol()) {
    return true;
  }
  if (cells[3]->getSymbol() != ' ' &&
      cells[3]->getSymbol() == cells[4]->getSymbol() &&
      cells[3]->getSymbol() == cells[5]->getSymbol()) {
    return true;
  }
  if (cells[6]->getSymbol() != ' ' &&
      cells[6]->getSymbol() == cells[7]->getSymbol() &&
      cells[6]->getSymbol() == cells[8]->getSymbol()) {
    return true;
  }
  if (cells[0]->getSymbol() != ' ' &&
      cells[0]->getSymbol() == cells[3]->getSymbol() &&
      cells[0]->getSymbol() == cells[6]->getSymbol()) {
    return true;
  }
  if (cells[1]->getSymbol() != ' ' &&
      cells[1]->getSymbol() == cells[4]->getSymbol() &&
      cells[1]->getSymbol() == cells[7]->getSymbol()) {
    return true;
  }
  if (cells[2]->getSymbol() != ' ' &&
      cells[2]->getSymbol() == cells[5]->getSymbol() &&
      cells[2]->getSymbol() == cells[8]->getSymbol()) {
    return true;
  }
  if (cells[0]->getSymbol() != ' ' &&
      cells[0]->getSymbol() == cells[4]->getSymbol() &&
      cells[0]->getSymbol() == cells[8]->getSymbol()) {
    return true;
  }
  if (cells[2]->getSymbol() != ' ' &&
      cells[2]->getSymbol() == cells[4]->getSymbol() &&
      cells[2]->getSymbol() == cells[6]->getSymbol()) {
    return true;
  }
  return false;
}
void Board::playerTurn(Player player, int index) {
  if (cells[index - 1]->addSymbol(player)) {
    turn++;
  }
  this->display();
}
int Board::getTurn() { return turn; }
Cell::Cell(int index) {
  this->index = index;
  symbol = ' ';
}
char Cell::getSymbol() { return symbol; }
bool Cell::addSymbol(Player player) {
  if (symbol == ' ') {
    this->symbol = player.getSymbol();
    return true;
  } else {
    return false;
  }
}
void Cell::display() {
  if (symbol == ' ') {
    cout << index;
  } else {
    cout << symbol;
  }
}
char Player::getSymbol() { return symbol; }
Player::Player(char symbol) { this->symbol = symbol; }
void Player::display() { cout << symbol; }