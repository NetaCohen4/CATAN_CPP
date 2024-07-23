/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#pragma once

#include "developmentCard.hpp"
#include "../player.hpp"

class KnightCard : public DevelopmentCard {
    public:
        KnightCard() {
            kind = "Knight";
        }

        void play(Player &player, Catan &game) override {
            std::cout << "playing a knight card\n";
            player.addKnight();
        }

        std::string getName() const override {
            return kind;
        }
};
