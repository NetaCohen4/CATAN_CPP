

#include <iostream>
#include "catan.hpp"
using namespace std;

void Catan::chooseStartingPlayer() {
    cout << "Starting Player: " << player1.getName() << endl;
    turn.setTurn(&player1);
}

