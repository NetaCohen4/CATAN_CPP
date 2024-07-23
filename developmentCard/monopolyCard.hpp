/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#pragma once

#include "developmentCard.hpp"
#include "../player.hpp"
#include "../catan.hpp"

class MonopolyCard : public DevelopmentCard {
public:
    MonopolyCard() {
        kind = "Monopoly";
    }

    void play(Player &player, Catan &game) override {
        std::cout << "Playing Monopoly card!" << endl << "What resource would you like to get?\n"; 
        string resource;
        std::cin >> resource;
        game.monopoly(player, resource);
    }

    std::string getName() const override {
        return kind;
    }
};
