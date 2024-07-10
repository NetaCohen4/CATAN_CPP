/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#include "doctest.h"
#include "../turn.hpp"
#include "../player.hpp"
#include <iostream>
#include <string>

using namespace std;

TEST_CASE("Test Turn") {
    Player p1("aa");
    Player p2("bb");
    Player p3("cc");

    //contructor with variables
    Turn newTurn1(&p1, &p2, &p3);
    //Test automatic starting player
    CHECK(newTurn1.getTurn() == &p1);
    // Constructor without variables + setting
    Turn newTurn2;
    newTurn2.setPlayers(&p1, &p2, &p3);
    CHECK(newTurn2.getTurn() == &p1);

    ++newTurn1;
    CHECK(newTurn1.getTurn() == &p2);

    newTurn2.setTurn(&p3);
    CHECK(newTurn2.getTurn() == &p3);
}