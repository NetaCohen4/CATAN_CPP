#pragma once

#include "developmentCard.hpp"
#include "../player.hpp"

class MonopolyCard : public DevelopmentCard {
public:
    MonopolyCard() {
        kind = "Monopoly";
    }

    void play(Player &player, Catan &game) override {
        // Implement the effect of playing a Monopoly card
        //player.collectMonopolyResource();
    }

    std::string getName() const override {
        return kind;
    }
};
