#pragma once

#include "developmentCard.hpp"
#include "../player.hpp"

class RoadBuildingCard : public DevelopmentCard {
public:
    RoadBuildingCard() {
        kind = "Road Building";
    }

    void play(Player &player, Catan &game) override {
        // Implement the effect of playing a Road Building card
        //player.buildRoad();
        
    }

    std::string getName() const override {
        return kind;
    }
};
