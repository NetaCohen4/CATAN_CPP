/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../board.hpp"
#include "../player.hpp"
#include <string>

using namespace std;

TEST_CASE("Test new Player") {
    
    Player newPlayer("player");
    
    CHECK(newPlayer.getName() == "player");

    CHECK(newPlayer.getPoints() == 0);

    Board board;
    
    board.createBestBoard();


    vector<string> places = {"Mountains", "Pasture Land", "Agricultural Land"};
    vector<int> placesNum =  {10, 2, 12};
    newPlayer.placeSettelemnt(places, placesNum, board);
    
    newPlayer.addResourcesByNum(10);
    newPlayer.addResourcesByNum(2);
    newPlayer.addResourcesByNum(12);
    newPlayer.printResources();

    CHECK(newPlayer.getPoints() == 0);
  
    //CHECK(newPlayer.getPoints() == 1);
}

TEST_CASE("Player Initialization") {
    Player p1("Alice");
    CHECK(p1.getName() == "Alice");
    CHECK(p1.getPoints() == 0);

    Player p2;
    CHECK(p2.getName() == "");
    CHECK(p2.getPoints() == 0);
}

TEST_CASE("Player Points") {
    Player p1("Alice");
    p1.printPoints();  // Should print: Alice: 0 points
    CHECK(p1.getPoints() == 0);

    // Simulate earning points
    p1.placeSettelemnt({"Forest", "Hills"}, {3, 5}, Board());
    CHECK(p1.getPoints() == 1);
    p1.printPoints();  // Should print: Alice: 1 points
}

TEST_CASE("Player Resources") {
    Player p1("Alice");
    std::vector<std::string> places = {"Forest", "Hills", "Mountains"};
    p1.addResources(places);

    p1.printResources();  // Should print: Alice has: 0 wool, 0 weat, 1 ore, 1 bricks, 1 wood.
    CHECK(p1.getResources("wood") == 1);
    CHECK(p1.getResources("bricks") == 1);
    CHECK(p1.getResources("ore") == 1);
}

TEST_CASE("Player Place Settlement and Road") {
    Board board;
    board.createBestBoard();
    
    Player p1("Alice");

    p1.placeSettelemnt({"Forest", "Hills"}, {3, 5}, board);
    CHECK(p1.getPoints() == 1);

    p1.placeRoad({"Forest", "Hills"}, {3, 5}, board);
    CHECK(p1.getPoints() == 1);  // Placing a road doesn't add points
}


