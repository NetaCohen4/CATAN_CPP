/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#include "doctest.h"
#include "../board.hpp"
#include "../land.hpp"
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

TEST_CASE("Test getLandsByNodeCode") {
    
    Board gameBoard;
    gameBoard.createBestBoard();
    vector<Land*> lands = gameBoard.getLandsByNodeCode(14);
    Land land1(Forest, 9);
    Land land2(PastureLand, 4);
    Land land3(Hills, 10);
    CHECK(*lands[0] == land1);
    CHECK(*lands[1] == land2);
    CHECK(*lands[2] == land3);
}

TEST_CASE("Board initialization and basic operations") {
    Board board;
    
    SUBCASE("Board is initialized with nullptrs") {
        for (size_t i = 0; i < 5; ++i) {
            for (size_t j = 0; j < 5; ++j) {
                CHECK(board.findLand("", 0) == nullptr); // All lands should be nullptr initially
            }
        }
    }
    
    SUBCASE("Create best board layout") {
        board.createBestBoard();
        CHECK(board.findLand("Mountains", 10) != nullptr);
        CHECK(board.findLand("Pasture Land", 2) != nullptr);
        CHECK(board.findLand("Forest", 9) != nullptr);
        CHECK(board.findLand("Agricultural Land", 12) != nullptr);
        CHECK(board.findLand("Hills", 6) != nullptr);
    }
}

TEST_CASE("Land retrieval and operations") {
    Board board;
    board.createBestBoard();
    
    SUBCASE("Find specific land by type and number") {
        Land* land = board.findLand("Forest", 9);
        CHECK(land != nullptr);
        CHECK(land->getLandType() == "Forest");
        CHECK(land->getNum() == 9);
    }
    
    SUBCASE("Find lands by number") {
        std::vector<Land*> lands = board.findLandsByNum(9);
        CHECK(lands.size() == 2); // Two lands with number 9
        CHECK(lands[0]->getNum() == 9);
        CHECK(lands[1]->getNum() == 9);
    }
    
    SUBCASE("Get lands by node code") {
        std::vector<Land*> lands = board.getLandsByNodeCode(8);
        CHECK(lands.size() == 3);
        CHECK(lands[0] != nullptr);
        CHECK(lands[1] != nullptr);
        CHECK(lands[2] != nullptr);
    }
}
TEST_CASE("Road legality checks") {
    Board board;
    
    SUBCASE("Legal roads") {
        CHECK_NOTHROW(board.isRoadLegal(0, 3));
        CHECK_NOTHROW(board.isRoadLegal(12, 17));
        CHECK_NOTHROW(board.isRoadLegal(23, 29));
    }
    
    SUBCASE("Illegal roads") {
        CHECK_THROWS_AS(board.isRoadLegal(0, 5), string);
        CHECK_THROWS_AS(board.isRoadLegal(7, 10), string);
        CHECK_THROWS_AS(board.isRoadLegal(21, 24), string);
    }
}
TEST_CASE("Node neighbors") {
    Board board;
    
    SUBCASE("Check neighbors for specific nodes") {
        std::vector<int> neighbors = nodeNeighbors(0);
        CHECK(neighbors == std::vector<int>({3, 4}));
        
        neighbors = nodeNeighbors(12);
        CHECK(neighbors == std::vector<int>({7, 8, 17}));
        
        neighbors = nodeNeighbors(26);
        CHECK(neighbors == std::vector<int>({20, 32}));
    }
}