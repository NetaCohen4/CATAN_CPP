#pragma once

#ifndef CATAN_HPP
#define CATAN_HPP

#include "player.hpp"
#include "turn.hpp"


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

    Turn turn;


    public:
    Catan(){}
    Catan(Player p1, Player p2, Player p3) {
        player1 = p1; player2 = p2; player3 = p3; 
        player1.setCatan(this); player2.setCatan(this); player3.setCatan(this);
        Turn turn(&p1, &p2, &p3);
    }
    ~Catan() {}
    void chooseStartingPlayer();
    bool isItMyTurn(Player &p) const {return turn == &p;}
    void endTurn(Player &p) {++turn;}
    Board getBoard();
    void printWinner();
    Player* getWinner();
};



#endif // CATAN_HPP