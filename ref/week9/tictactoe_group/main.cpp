#include "board.h"
#include <iostream>

using namespace std;
int main() {
  Board *board = new Board();
  Player *player1 = new Player('X');
  Player *player2 = new Player('O');
  cout << "Players switch turns, type number to go in that spot";
  board->display();
  int index;
  while (board->getTurn() < 9 && !board->checkWin()) {
    if (board->getTurn() % 2 == 0) {
      cout << "Player 1's turn: ";
    } else {
      cout << "Player 2's turn: ";
    }
    cin >> index;
    if (board->getTurn() % 2 == 0) {
      board->playerTurn(*player1, index);
    } else {
      board->playerTurn(*player2, index);
    }
  }
  if (board->checkWin()) {
    if (board->getTurn() % 2 == 0) {
      cout << "Player 2 Wins!!!" << endl;
    } else {
      cout << "Player 1 Wins!!!" << endl;
    }
  } else {
    cout << "Draw. :(" << endl;
  }
  delete board;
  return 0;
}