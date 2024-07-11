/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#include "doctest.h"
#include "../board.hpp"
#include <string>

using namespace std;


TEST_CASE("Board Initialization") {
    Board board;
    board.createBestBoard();
    board.printBoard();  // Check visual output

    CHECK(board.findLand("Mountains", 10) != nullptr);
    CHECK(board.findLand("Desert", 0) != nullptr);
    CHECK(board.findLand("Nonexistent", 99) == nullptr);
}

TEST_CASE("Board Resource Distribution") {
    Board board;
    board.createBestBoard();

    std::vector<Land*> lands = board.findLandsByNum(10);
    CHECK(lands.size() == 2);

    Land* land = board.findLand("Mountains", 10);
    CHECK(land != nullptr);
    CHECK(land->getLandType() == "Mountains");
    CHECK(land->getNum() == 10);
}

TEST_CASE("Board Copy Constructor and Destructor") {
    Board board1;
    board1.createBestBoard();

    Board board2 = board1;  // Test copy constructor
    CHECK(board2.findLand("Mountains", 10) != nullptr);

    // Test destructor
    {
        Board tempBoard;
        tempBoard.createBestBoard();
    }
    // No explicit check, just ensuring no crash occurs on destruction
}


TEST_CASE("Test game board") {
    
    Board gameBoard;
    gameBoard.createBestBoard();
    gameBoard.printBoard();
}