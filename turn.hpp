#pragma once

class Player;

class Turn {
    private:
        Player* player1;
        Player* player2;  // Fixed capitalization to be consistent
        Player* player3;

        Player* turn;

    public:
        Turn(){}
        Turn(Player* p1, Player* p2, Player* p3)
            : player1(p1), player2(p2), player3(p3), turn(p1) {}

        void setTurn(Player* firstPlayer) {turn = firstPlayer;}

        // Prefix increment operator to advance the turn to the next player
        Turn& operator++() {
            if (turn == player1) {
                turn = player2;
            } else if (turn == player2) {
                turn = player3;
            } else if (turn == player3) {
                turn = player1;
            }
            return *this;
        }

        // Equality operator to check if it's the given player's turn
        bool operator==(const Player* player) const {
            return turn == player;
        }
};
