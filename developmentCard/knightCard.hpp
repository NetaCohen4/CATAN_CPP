#pragma once

#include "developmentCard.hpp"
#include "../player.hpp"

class KnightCard : public DevelopmentCard {
    public:
        KnightCard() {
            kind = "Knight";
        }

        void play(Player &player, Catan &game) override {
            // Implement the effect of playing a Knight card
            std::cout << "playing a knight card\n";
            player.addKnight();
        }

        std::string getName() const override {
            return kind;
        }
};
