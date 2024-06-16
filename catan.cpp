/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#include <iostream>
#include "catan.hpp"
using namespace std;

void Catan::chooseStartingPlayer() {
    cout << "Starting Player: " << player1.getName() << endl;
    turn.setTurn(&player1);
}

Board Catan::getBoard() {
    Board board;
    board.createBestBoard();
    return board;
}

void Catan::printWinner() {

}

