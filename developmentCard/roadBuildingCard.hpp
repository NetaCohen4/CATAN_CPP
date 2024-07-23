/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

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
        std::cout << "Road Building development Card!" << endl << "You can place 2 roads, where do you want to place them?\n";
        //player.getSettlements()
        //for each settlement.getNode() and print which roads are available
        int node1, node2;
        
        for (int i = 0; i < 2; i++) {
            std::cin >> node1 >> node2;
            player.addResource("wood");
            player.addResource("bricks");
            try {
                game.buyRoad(player, node1, node2);
            }
            catch (const string e) {
                cout << e << endl << "Please choose other location to set the road" << endl;
                player.useRoadResources();
                ++i;
            }
        }
    }

    std::string getName() const override {
        return kind;
    }
};
