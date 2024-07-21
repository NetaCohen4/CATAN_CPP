/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/
#include "doctest.h"
#include "../player.hpp"
#include "../board.hpp"

TEST_CASE("Trade resources between players") {
    Player p1("Alice");
    Player p2("Bob");

    // Setup initial resources
    vector<string> resources = {"Forest", "Hills", "Mountains", "Agricultural Land", "Pasture Land"};
    p1.addResources(resources);
    p2.addResources(resources);

    p1.trade(p2, "wood", "bricks", 1, 1);

    // After trade, p1 should have one less wood and one more brick
    // p2 should have one more wood and one less brick
    // We need to implement getResources for test verification

    // Print resources for visual verification
    p1.printResources();
    p2.printResources();
}

TEST_CASE("Buy Development Card") {
    Player p1("Charlie");

    // Setup initial resources to buy a development card
    vector<string> resources = {"Forest", "Hills", "Mountains", "Agricultural Land", "Pasture Land"};
    p1.addResources(resources);
    p1.addResources(resources); // Ensure sufficient resources

    p1.buyDevelopmentCard();

    // Print resources for visual verification
    p1.printResources();
}

TEST_CASE("Print points") {
    Player p1("David");
    p1.printPoints();

    // Check if initial points are 0
    CHECK(p1.getPoints() == 0);
}

TEST_CASE("Add resources") {
    Player p1("Eve");
    vector<string> resources = {"Forest", "Hills", "Mountains", "Agricultural Land", "Pasture Land"};
    p1.addResources(resources);

    // Print resources for visual verification
    p1.printResources();

    // We need to implement getResources for test verification
}


TEST_CASE("Use resources for road") {
    Player p1("Grace");
    vector<string> resources = {"Forest", "Hills"};
    p1.addResources(resources);
    p1.addResources(resources); // Ensure sufficient resources

    p1.useRoadResources();

    // Print resources for visual verification
    p1.printResources();
}

TEST_CASE("Use resources for settlement") {
    Player p1("Hank");
    vector<string> resources = {"Forest", "Hills", "Pasture Land", "Agricultural Land"};
    p1.addResources(resources);
    p1.addResources(resources); // Ensure sufficient resources
    p1.printResources();

    p1.useSettlementResources();

    // Print resources for visual verification
    p1.printResources();
}

TEST_CASE("Use resources for city") {
    Player p1("Ivy");
    vector<string> resources = {"Mountains", "Mountains", "Mountains", "Agricultural Land", "Agricultural Land"};
    p1.addResources(resources);
    p1.addResources(resources); // Ensure sufficient resources

    p1.useCityResources();

    // Print resources for visual verification
    p1.printResources();
}

TEST_CASE("Use resources for development card") {
    Player p1("Jack");
    vector<string> resources = {"Forest", "Hills", "Mountains", "Agricultural Land", "Pasture Land"};
    p1.addResources(resources);
    p1.addResources(resources); // Ensure sufficient resources

    p1.useDevelopmentCardResources();

    // Print resources for visual verification
    p1.printResources();
}

TEST_CASE("Place road between nodes") {
    Player p1("Kurt");
    Board board;
    p1.placeSettelemnt(8, board);
    CHECK(p1.hasSettlementOrCity(8) == true);
    p1.placeRoad(8, 12);

    // Check road placement
    CHECK(p1.hasRoad(8, 12) == true);
}

TEST_CASE("Place settlement at a node") {
    Player p1("Leo");
    Board board;
    p1.placeSettelemnt(1, board);

    // Check settlement placement
    CHECK(p1.hasSettlementOrCity(1) == true);
}

TEST_CASE("Build city at a settlement node") {
    Player p1("Mona");
    Board board;
    p1.placeSettelemnt(1, board);
    vector<string> resources = {"Mountains", "Mountains", "Mountains", "Agricultural Land", "Agricultural Land"};
    p1.addResources(resources);
    p1.buildCity(1);

    // Check if the settlement has been converted to a city
    // We need to implement hasCity for test verification
}


TEST_CASE("Testing resource usage methods for throwing exceptions") {
    Board board;
    Player player("TestPlayer");

    // Trying to use resources for building without having them
    CHECK_THROWS_WITH(player.useRoadResources(), "You don't have the resources to buy a Road.");
    CHECK_THROWS_WITH(player.useSettlementResources(), "You don't have the resources to buy a Settlement.");
    CHECK_THROWS_WITH(player.useCityResources(), "You don't have the resources to buy a City.");
    CHECK_THROWS_WITH(player.useDevelopmentCardResources(), "You don't have the resources to buy a Development Card.");
}


TEST_CASE("Testing buildCity for throwing exceptions") {
    Board board;
    Player player("TestPlayer");

    // Trying to build a city without an existing settlement
    CHECK_THROWS_WITH(player.buildCity(1), "There must be a settlement in order to build a city.");
}
