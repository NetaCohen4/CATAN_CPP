/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#include "doctest.h"
#include "land.hpp"
#include <iostream>
#include <string>

using namespace std;

TEST_CASE("Test new land") {
    Land newLand(Forest, 8);
    CHECK(newLand.getLandType() == "Forest");
    CHECK(newLand.getNum() == 8);
}