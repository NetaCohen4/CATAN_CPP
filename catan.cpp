

#include <iostream>
#include "catan.hpp"
using namespace std;

namespace ariel {
    void Catan::chooseStartingPlayer() {
        cout << "Starting Player: " << player1.getName() << endl;
        curr_player = &player1;
    }


}
