/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#include "doctest.h"
#include "../board.hpp"

using namespace std;

/*
TEST_CASE("Test second constructor") {
    Land hills(Hills, 6);
    std::vector<std::vector<Land*>> newLandMatrix = 
                {   {&hills, &hills, &hills, nullptr, nullptr},
                    {&hills, &hills, &hills, &hills, nullptr},
                    {&hills, &hills, &hills, &hills, &hills},
                    {nullptr, &hills, &hills, &hills, &hills},
                    {nullptr, nullptr, &hills, &hills, &hills}
                };
    Board newBoard(newLandMatrix);
    newBoard.printBoard();
}
*/


TEST_CASE("Test game board") {
    
    Board gameBoard;
    gameBoard.createBestBoard();
    gameBoard.printBoard();
}