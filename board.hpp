
#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include <utility> // for std::pair

namespace ariel {


    enum LandType {
        Forest,
        Hills,
        AgriculturalLand,
        Mountains,
        PastureLand,
        Desert
    };

    const char* landTypeToString(LandType type) {
        switch(type) {
            case Forest: return "Forest";
            case Hills: return "Hills";
            case AgriculturalLand: return "Agricultural Land";
            case Desert: return "Desert";
            case Mountains: return "Mountains";
            case PastureLand: return "Pasture Land";
            default: return "Unknown";
        }
    }

    

    class Board {

    private:
        // Create a pair of LandType and int
        //std::pair<LandType, int> landPair= std::make_pair(Forest, 100);
        // Define a 5x5 vector of pairs of LandType and int
        using LandPair = std::pair<LandType, int>;
        std::vector<std::vector<LandPair>> landMatrix;

    public:

        // Initialize the 5x5 vector with some values
        void createBoard() {

            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    // For demonstration, we use the same LandType for all pairs and assign value (i * 5 + j)
                    //landMatrix[i][j] = std::make_pair(Forest, i * 5 + j);
                }
            }
        }
        
        void printBoard () {
            // Print the 5x5 vector
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    //std::cout << "(" << landTypeToString(landMatrix[i][j].first) << ", " << landMatrix[i][j].second << ") ";
                }
                std::cout << std::endl;
            }
        }


        


    };

}

#endif // BOARD_HPP