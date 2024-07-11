/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#pragma once

#include <iostream>
#include <vector>
#include "land.hpp"


class Board {

    private:
    
        std::vector<std::vector<Land*>> landMatrix;

    public:

        Board() : landMatrix(5, std::vector<Land*>(5, nullptr)) {}

        Board(const Board& other) : landMatrix(5, std::vector<Land*>(5, nullptr)) {
            for (size_t i = 0; i < 5; ++i) {
                for (size_t j = 0; j < 5; ++j) {
                    if (other.landMatrix[i][j]) {
                        landMatrix[i][j] = new Land(*other.landMatrix[i][j]);
                    }
                }
            }
        }

        ~Board() {
            for (auto& row : landMatrix) {
                for (auto& land : row) {
                    if (land != nullptr) {  // Check if pointer is not nullptr before deleting
                        delete land;
                        land = nullptr;  // Set pointer to nullptr to avoid double free
                    }
                }
            }
        }
        
        void createBestBoard() {
            
            landMatrix[0][0] = new Land(Mountains, 10);
            landMatrix[0][1] = new Land(PastureLand, 2);
            landMatrix[0][2] = new Land(Forest, 9);

            landMatrix[1][0] = new Land(AgriculturalLand, 12);
            landMatrix[1][1] = new Land(Hills, 6);
            landMatrix[1][2] = new Land(PastureLand, 4);
            landMatrix[1][3] = new Land(Hills, 10);

            landMatrix[2][0] = new Land(AgriculturalLand, 9);
            landMatrix[2][1] = new Land(Forest, 11);
            landMatrix[2][2] = new Land(Desert, 0);
            landMatrix[2][3] = new Land(Forest, 3);
            landMatrix[2][4] = new Land(Mountains, 8);

            landMatrix[3][1] = new Land(Forest, 8);
            landMatrix[3][2] = new Land(Mountains, 3);
            landMatrix[3][3] = new Land(AgriculturalLand, 4);
            landMatrix[3][4] = new Land(PastureLand, 5);

            landMatrix[4][2] = new Land(Hills, 5);
            landMatrix[4][3] = new Land(AgriculturalLand, 6);
            landMatrix[4][4] = new Land(PastureLand, 11);
        }
        
        void printBoard () {
            cout << endl;
            for (size_t i = 0; i < 5; ++i) {
                if (i != 2) {
                    cout << "    ";
                    if ((i != 1) && (i != 3)) {
                        cout << "    ";
                    }
                }
                for (size_t j = 0; j < 5; ++j) {
                    if (landMatrix[i][j]) {
                        landMatrix[i][j]->printLand();
                        cout << " | ";
                    }
                }
                
                cout << endl << endl;
            }
        }

        Land* findLand(string landName, int landNum) { 
            for (size_t i = 0; i < 5; ++i) {
                for (size_t j = 0; j < 5; ++j) {
                    if (landMatrix[i][j]) {
                        if (((landMatrix[i][j])->getLandType() == landName) && ((landMatrix[i][j])->getNum() == landNum)) {
                            return landMatrix[i][j];
                        }
                    }
                }
            }
            return nullptr;
        }

        vector<Land*> findLandsByNum(size_t num) {
            vector<Land*> lands;
            for (size_t i = 0; i < 5; ++i) {
                for (size_t j = 0; j < 5; ++j) {
                    if (landMatrix[i][j]) {
                        if ((landMatrix[i][j])->getNum() == num) {
                            lands.push_back(landMatrix[i][j]);
                        }
                    }
                }
            }
            return lands;
        }
};
