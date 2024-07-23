/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#pragma once

#include <string>

class Player;
class Catan;

class DevelopmentCard {
protected:
    std::string kind;

public:
    virtual ~DevelopmentCard() = default;
    virtual void play(Player &player, Catan &game) = 0;
    virtual std::string getName() const = 0;
};

