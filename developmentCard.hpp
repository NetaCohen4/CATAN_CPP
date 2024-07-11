#pragma once

#include <string>

class Player; // Forward declaration of Player class

class DevelopmentCard {
public:
    virtual ~DevelopmentCard() = default;
    DevelopmentCard* getDevelopmentCard() {
        return nullptr;
    }
    virtual void play(Player &player) = 0;
    virtual std::string getName() const = 0;
};
