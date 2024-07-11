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
    
    Player newPlayer("player");
    //CHECK_THROWS(Catan newCatan(newPlayer, newPlayer, newPlayer));
/*
    vector<string> places = {"Mountains", "Pasture Land", "Agricultural Land"};
    vector<int> placesNum =  {10, 2, 12};
    newPlayer.placeSettelemnt(places, placesNum, board);
    
    newPlayer.addResourcesByNum(10);
    newPlayer.addResourcesByNum(2);
    newPlayer.addResourcesByNum(12);
    newPlayer.printResources();

    CHECK(newPlayer.getPoints() == 0);
*/    
}

TEST_CASE("Catan Initialization") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");

    Catan game(p1, p2, p3);

    //CHECK(game.getCurrentPlayer()->getName() == "Alice");
    //CHECK_THROWS_AS(Catan(p1, p1, p3), std::runtime_error);  // Should throw due to duplicate player names
}

TEST_CASE("Catan Turns and Dice Roll") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");
    Board board;
    Catan game(p1, p2, p3);
    game.setBoard(&board);

    CHECK_NOTHROW(game.rollDice(p1));
    game.endTurn();
    CHECK_NOTHROW(game.rollDice(p2));
    game.endTurn();
    CHECK_NOTHROW(game.rollDice(p3));
    game.endTurn();
    CHECK_THROWS_AS(game.rollDice(p2), std::runtime_error);  // Not Bob's turn
}

TEST_CASE("Catan Winning Conditions") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");
    Catan game(p1, p2, p3);

    CHECK_FALSE(game.isThereWinner());

    Board board;
    for (int i = 0; i < 10; ++i) {
        p1.placeSettelemnt({"Forest", "Hills"}, {3, 5}, board);
    }

    CHECK(game.isThereWinner());
}
