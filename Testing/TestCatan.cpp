/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#include "doctest.h"
#include "../board.hpp"
#include "../player.hpp"
#include "../catan.hpp"
#include <string>

using namespace std;

TEST_CASE("Test new Catan") {
    Player p1("aaa");
    Player p2("bbb");
    Player p3("ccc");
    Catan catan(p1, p2, p3);
    //CHECK_THROWS(Catan c(p1, p1, p1));
}

TEST_CASE("Test Catan Functionality") {
    // Create players
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");

    // Initialize the Catan game
    Catan game(p1, p2, p3);

    // Test chooseStartingPlayer
    game.chooseStartingPlayer();
    CHECK_THROWS_WITH(game.isItHisTurn(p3), "Charlie tried to make action out of turn");

    // Create and set the board
    Board board;
    game.setBoard(&board);

    p1.buyDevelopmentCard();
    game.playDevelopmentCard(p1, "Knight");
    game.playDevelopmentCard(p1, "Victory Point");
    game.playDevelopmentCard(p1, "Monopoly");
    game.playDevelopmentCard(p1, "Road Building");
    game.playDevelopmentCard(p1, "Year of Plenty");
}

TEST_CASE("Test Catan Game Functionality") {
    // Create players
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");

    // Initialize the Catan game
    Catan game(p1, p2, p3);

    // Test chooseStartingPlayer
    game.chooseStartingPlayer();
    CHECK_THROWS_WITH(game.isItHisTurn(p3), "Charlie tried to make action out of turn");

    // Create and set the board
    Board board;
    game.setBoard(&board);
    
    // Test isThereWinner and printWinner (No winner initially)
    CHECK(!game.isThereWinner());
    game.printWinner();

    // Simulate game to reach 10 points and test for winner
    p1.addPoints(11);
    p1.printPoints();
    CHECK(game.isThereWinner());
    game.printWinner();
}


TEST_CASE("Test Exception Handling for Turn") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");

    Catan game(p1, p2, p3);
    game.chooseStartingPlayer();

    CHECK_THROWS_WITH_AS(game.buySettlement(p2, 1), "Bob tried to make action out of turn", std::string);
    CHECK_THROWS_WITH_AS(game.buyCity(p2, 1), "Bob tried to make action out of turn", std::string);
    CHECK_THROWS_WITH_AS(game.buyRoad(p2, 1, 2), "Bob tried to make action out of turn", std::string);
    CHECK_THROWS_WITH_AS(game.buyDevelopmentCard(p2), "Bob tried to make action out of turn", std::string);
}

TEST_CASE("Test Building Settlements, Cities, and Roads") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");

    Catan game(p1, p2, p3);
    game.chooseStartingPlayer();
    Board board;
    game.setBoard(&board);

    vector<string> resources = {"Forest", "Hills", "Mountains", "Agricultural Land", "Pasture Land", "Mountains", "Mountains", "Mountains", "Agricultural Land", "Agricultural Land", "Forest", "Hills"};
    p1.addResources(resources);
    p1.printResources();
    // Test buying settlement
    CHECK_NOTHROW(game.buySettlement(p1, 1));
    CHECK_THROWS_WITH_AS(game.buySettlement(p1, 1), "Error: Attempt of building a Settlement in an unavailable place", std::string);

    // Test buying city
    CHECK_NOTHROW(game.buyCity(p1, 1));

    // Test buying road
    CHECK_NOTHROW(game.buyRoad(p1, 1, 4));
    CHECK_THROWS_WITH_AS(game.buyRoad(p1, 1, 4), "Error: Attempt of building a road in an unavailable place", std::string);
}

TEST_CASE("Test Resource Distribution") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");

    Catan game(p1, p2, p3);
    game.chooseStartingPlayer();
    Board board;
    board.createBestBoard();
    game.setBoard(&board);

    game.placeFirstSettlement(p1, 12);
    game.placeFirstRoad(p1, 12, 17);

    game.placeFirstSettlement(p2, 9);
    game.placeFirstRoad(p2, 9, 13);

    // Test distributeResources
    game.distributeResources(6);

    p1.printResources();
    p2.printResources();

}
