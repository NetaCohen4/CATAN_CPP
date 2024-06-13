
#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include "land.hpp"


class Board {

private:
    // Define a 5x5 vector of lands
    std::vector<std::vector<Land*>> landMatrix;

public:

    // Initialize the 5x5 vector with some values
    void createBestBoard() {

        Land desert(Desert, 0);
        landMatrix = { {&desert, &desert, &desert, nullptr, nullptr},
                        {&desert, &desert, &desert, &desert, nullptr},
                        {&desert, &desert, &desert, &desert, &desert},
                        {nullptr, &desert, &desert, &desert, &desert}, 
                        {nullptr, nullptr, &desert, &desert, &desert} };
    }
    
    void printBoard () {
        // Print the 5x5 vector
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (landMatrix[i][j]) {
                    cout << landMatrix[i][j]->getLandType() << ", " << landMatrix[i][j]->getNum() << " ";
                }
            }
            std::cout << std::endl;
        }
    }


};



#endif // BOARD_HPP