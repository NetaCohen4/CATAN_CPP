/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#include "doctest.h"
#include "../land.hpp"
#include <iostream>
#include <string>

using namespace std;

TEST_CASE("Test new land") {
    Land newLand(Forest, 8);
    CHECK(newLand.getLandType() == "Forest");
    CHECK(newLand.getNum() == 8);
}

TEST_CASE("Test Land Pointer") {
    Land* landptr;
    Land newLand(Forest, 8);
    landptr = &newLand;
    CHECK(landptr->getLandType() == "Forest");
    CHECK(landptr->getNum() == 8);
}