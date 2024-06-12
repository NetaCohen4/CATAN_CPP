#ifndef CATAN_HPP
#define CATAN_HPP

#include "player.hpp"

namespace ariel {

    enum Card {
        wood,
        brick,
        wheat,
        ore,
        wool,
        developmentCard
    };

    class Catan {
        private:
        Player player1;
        Player player2;
        Player player3;

        Player* curr_player;

        public:
        Catan(){}
        Catan(Player p1, Player p2, Player p3) {player1 = p1; player2 = p2; player3 = p3;}
        void chooseStartingPlayer();
        Board getBoard();
        void printWinner();
        void putStartingPositions(Board);
        Player* getWinner();
        Player* getStartingPlayer();
    };

}

#endif // CATAN_HPP