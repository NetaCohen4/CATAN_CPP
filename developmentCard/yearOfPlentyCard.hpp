#pragma once

#include "developmentCard.hpp"
#include "../player.hpp"

class YearOfPlentyCard : public DevelopmentCard {
public:
    YearOfPlentyCard() {
        kind = "Year of Plenty";
    }

    void play(Player &player, Catan &game) override {
        // Implement the effect of playing a Year of Plenty card
        //player.collectResources();
        string resource1, resource2;
        cout << "Year of plenty! what two resources would you like to get?\n";
        cin >> resource1 >> resource2;
        player.addResource(resource1);
        player.addResource(resource2);
    }

    std::string getName() const override {
        return kind;
    }
};
