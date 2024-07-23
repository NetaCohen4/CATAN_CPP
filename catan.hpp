/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#pragma once

#include "player.hpp"


class Catan {
    private:
        Player &player1;
        Player &player2;
        Player &player3;
        Board* board;
        Player* p_turn;

    public:

        Catan(Player &p1, Player &p2, Player &p3) : player1(p1), player2(p2), player3(p3), board(nullptr), p_turn(&p1) {
            if (p1.getName() == p2.getName() || p1.getName() == p3.getName() || p2.getName() == p3.getName()) {
                throw std::invalid_argument("Catan Players' names must be different from one another");
            }
        }

        void chooseStartingPlayer();
        void setBoard(Board* myBoard);
        
        void printWinner();
        bool isThereWinner();

        void rollDice(Player &player);
        void endTurn();

        void distributeResources(size_t dice);

        void buyDevelopmentCard(Player &p);
        void playDevelopmentCard(Player &p, const std::string &kind); 

        void buyRoad(Player &p, int node1, int node2);
        void buySettlement(Player &p, int node);
        void buyCity(Player &p, int node);

        void isRoadAvailable(int node1, int node2);
        void isNodeAvailable(int node);

        void isItHisTurn(Player &player) const;

        void placeFirstSettlement(Player &p, int node);
        void placeFirstRoad(Player &p, int node1, int node2);

        void addResources(Player &p, int node);
        
        void trade(Player &p1, Player &p2, string resource1, string resource2, unsigned int amount1, unsigned int amount2);
        void monopoly(Player &p, string resource);
};
