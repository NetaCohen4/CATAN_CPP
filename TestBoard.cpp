/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#include "doctest.h"
#include "board.hpp"

using namespace std;

TEST_CASE("Test desert Board") {
    Board newBoard;
    newBoard.createBestBoard();
    newBoard.printBoard();
}