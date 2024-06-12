#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include "board.hpp"
using namespace std;

namespace ariel {

    class Player {
        private:
        string name;
        vector<string> cards;
        int points = 0;

        public:
        Player(){}
        Player(string name) {name = name;}

        string getName() {return name;}
        void placeSettelemnt(vector<string> places, vector<int> placesNum , Board board);
        void placeRoad(vector<string> places, vector<int> placesNum , Board board);
        int rollDice();
        void endTurn();
        void trade(Player p2, string resource1, string resource2, int amount1, int amount2);
        void buyDevelopmentCard();
        void printPoints();

    };

}

#endif // PLAYER_HPP