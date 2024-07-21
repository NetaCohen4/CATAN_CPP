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

        Land* findLand(string landName, size_t landNum) { 
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

        
        void isRoadLegal(int node1, int node2) { // node1 < node2
            bool flag = false;
            switch (node1) {
                case 0: if (node2 == 3 || node2 == 4) flag = true; break;
                case 1: if (node2 == 4 || node2 == 5) flag = true; break;
                case 2: if (node2 == 5 || node2 == 6) flag = true; break;

                case 3: if (node2 == 7) flag = true; break;
                case 4: if (node2 == 8) flag = true; break;
                case 5: if (node2 == 9) flag = true; break;
                case 6: if (node2 == 10) flag = true; break;

                case 7: if (node2 == 11 || node2 == 12) flag = true; break;
                case 8: if (node2 == 12 || node2 == 13) flag = true; break;
                case 9: if (node2 == 13 || node2 == 14) flag = true; break;
                case 10: if (node2 == 14 || node2 == 15) flag = true; break;

                case 11: if (node2 == 16) flag = true; break;
                case 12: if (node2 == 17) flag = true; break;
                case 13: if (node2 == 18) flag = true; break;
                case 14: if (node2 == 19) flag = true; break;
                case 15: if (node2 == 20) flag = true; break;

                case 16: if (node2 == 21 || node2 == 22) flag = true; break;
                case 17: if (node2 == 22 || node2 == 23) flag = true; break;
                case 18: if (node2 == 23 || node2 == 24) flag = true; break;
                case 19: if (node2 == 24 || node2 == 25) flag = true; break;
                case 20: if (node2 == 25 || node2 == 26) flag = true; break;

                case 21: if (node2 == 27) flag = true; break;
                case 22: if (node2 == 28) flag = true; break;
                case 23: if (node2 == 29) flag = true; break;
                case 24: if (node2 == 30) flag = true; break;
                case 25: if (node2 == 31) flag = true; break;
                case 26: if (node2 == 32) flag = true; break;

                case 27: if (node2 == 33) flag = true; break;
                case 28: if (node2 == 33 || node2 == 34) flag = true; break;
                case 29: if (node2 == 34 || node2 == 35) flag = true; break;
                case 30: if (node2 == 35 || node2 == 36) flag = true; break;
                case 31: if (node2 == 36 || node2 == 37) flag = true; break;
                case 32: if (node2 == 37) flag = true; break;

                case 33: if (node2 == 38) flag = true; break;
                case 34: if (node2 == 39) flag = true; break;
                case 35: if (node2 == 40) flag = true; break;
                case 36: if (node2 == 41) flag = true; break;
                case 37: if (node2 == 42) flag = true; break;

                case 38: if (node2 == 43) flag = true; break;
                case 39: if (node2 == 43 || node2 == 44) flag = true; break;
                case 40: if (node2 == 44 || node2 == 45) flag = true; break;
                case 41: if (node2 == 45 || node2 == 46) flag = true; break;
                case 42: if (node2 == 46) flag = true; break;

                case 43: if (node2 == 47) flag = true; break;
                case 44: if (node2 == 48) flag = true; break;
                case 45: if (node2 == 49) flag = true; break;
                case 46: if (node2 == 50) flag = true; break;

                case 47: if (node2 == 51) flag = true; break;
                case 48: if (node2 == 51 || node2 == 52) flag = true; break;
                case 49: if (node2 == 52 || node2 == 53) flag = true; break;
                case 50: if (node2 == 53) flag = true; break;
            }
            if (!flag) {
                throw ((string)"Error: An attempt to build a road between two non-neighboring nodes.");
            }
        }
        
        vector<Land*> getLandsByNodeCode(size_t nodeCode);
        

};


vector<int> nodeNeighbors(int node);

