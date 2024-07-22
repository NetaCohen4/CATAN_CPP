#pragma once

#include "developmentCard.hpp"
#include "../player.hpp"

class VictoryPointCard : public DevelopmentCard {
public:
    VictoryPointCard() {
        kind = "Victory Point";
    }

    void play(Player &player, Catan &game) override {
        // Implement the effect of playing a Victory Point card
        std::cout << "playing a victory point card\n";
        player.addPoints(1);
    }

    std::string getName() const override {
        return kind;
    }
};
