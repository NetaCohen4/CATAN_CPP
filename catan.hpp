/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#pragma once

#include "player.hpp"

/*
enum Card {
    wood,
    brick,
    wheat,
    ore,
    wool,
    developmentCard
};
*/

class Catan {
    private:
    Player &player1;
    Player &player2;
    Player &player3;
    Board* board;
    Player* p_turn;

    public:
    /*
    Catan(){}
    Catan(Player &p1, Player &p2, Player &p3) {
        if (p1.getName() == p2.getName() || p1.getName() == p3.getName() || p2.getName() == p3.getName() ) {
            throw ("Catan Players's names must be different from one another");
        }
        player1 = p1; player2 = p2; player3 = p3;
        p_turn = &p1;
    }
    ~Catan() {}
    */
    Catan(Player &p1, Player &p2, Player &p3)
        : player1(p1), player2(p2), player3(p3), board(nullptr), p_turn(&p1) {
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

    void buyRoad(Player &p, vector<string> places, vector<int> placesNum);
    void buySettlement(Player &p, vector<string> places, vector<int> placesNum);
    void buyCity(Player &p, vector<string> places, vector<int> placesNum);
    void buyDevelopmentCard(Player &p);

    void buyRoad(Player &p, int node1, int node2);
    void buySettlement(Player &p, int node);
    void buyCity(Player &p, int node);

    void isRoadAvailable(int node1, int node2);
    void isNodeAvailable(int node);

    void isItHisTurn(Player &player);
};
