/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#include "board.hpp"


vector<int> nodeNeighbors(int node) {
    switch (node) {
        case 0: return {3, 4};
        case 1: return {4, 5};
        case 2: return {5, 6};

        case 3: return {0, 7};
        case 4: return {0, 1, 8};
        case 5: return {1, 2, 9};
        case 6: return {2, 10};

        case 7: return {3, 11, 12};
        case 8: return {4, 12, 13};
        case 9: return {5, 13, 14};
        case 10: return {6, 14, 15};

        case 11: return {7, 16};
        case 12: return {7, 8, 17};
        
        case 13: return {8, 9, 18};
        case 14: return {9, 10, 19};
        case 15: return {10, 20};

        case 16: return {11, 21, 22};
        case 17: return {12, 22, 23};
        case 18: return {13, 23, 24};
        case 19: return {14, 24, 25};
        case 20: return {15, 25, 26};

        case 21: return {16, 27};
        case 22: return {16, 17, 28};
        case 23: return {17, 18, 29};
        case 24: return {18, 19, 30};
        case 25: return {19, 20, 31};
        case 26: return {20, 32};
        
        case 27: return {20, 33};
        case 28: return {22, 33, 34};
        case 29: return {23, 34, 35};
        case 30: return {24, 35, 36};
        case 31: return {25, 36, 37};
        case 32: return {26, 37};

        case 33: return {27, 28, 38};
        case 34: return {28, 29, 39};
        case 35: return {29, 30, 40};
        case 36: return {30, 31, 41};
        case 37: return {31, 32, 42};

        case 38: return {33, 43};
        case 39: return {34, 43, 44};
        case 40: return {35, 44, 45};
        case 41: return {36, 45, 46};
        case 42: return {37, 46};

        case 43: return {38, 39, 47};
        case 44: return {39, 40, 48};
        case 45: return {40, 41, 49};
        case 46: return {41, 42, 50};

        case 47: return {43, 51};
        case 48: return {44, 51, 52};
        case 49: return {45, 52, 53};
        case 50: return {46, 53};
        
        case 51: return {47, 48};
        case 52: return {48, 49};
        case 53: return {49, 50};

        default:
        throw ("Error: there is no such node as " + to_string(node));
    }
    return {};
}

vector<Land*> Board::getLandsByNodeCode(size_t nodeCode) {
    vector<Land*> lands;
    // Switch statement to set lands based on nodeCode
    switch (nodeCode) {
        case 0:
        case 3:
            lands.push_back(landMatrix[0][0]);
            break;
        case 1:
            lands.push_back(landMatrix[0][1]);
            break;
        case 2:
        case 6:
            lands.push_back(landMatrix[0][2]);
            break;
        case 4:
            lands.push_back(landMatrix[0][0]);
            lands.push_back(landMatrix[0][1]);
            break;
        case 5:
            lands.push_back(landMatrix[0][1]);
            lands.push_back(landMatrix[0][2]);
            break;
        case 7:
            lands.push_back(landMatrix[0][0]);
            lands.push_back(landMatrix[1][0]);
            break;
        case 8:
            lands.push_back(landMatrix[0][0]);
            lands.push_back(landMatrix[0][1]);
            lands.push_back(landMatrix[1][1]);
            break;
        case 9:
            lands.push_back(landMatrix[0][1]);
            lands.push_back(landMatrix[0][2]);
            lands.push_back(landMatrix[1][2]);
            break;
        case 10:
            lands.push_back(landMatrix[0][2]);
            lands.push_back(landMatrix[1][3]);
            break;
        case 11:
            lands.push_back(landMatrix[1][0]);
            break;
        case 12:
            lands.push_back(landMatrix[0][0]);
            lands.push_back(landMatrix[1][0]);
            lands.push_back(landMatrix[1][1]);
            break;
        case 13:
            lands.push_back(landMatrix[0][1]);
            lands.push_back(landMatrix[1][1]);
            lands.push_back(landMatrix[1][2]);
            break;
        case 14:
            lands.push_back(landMatrix[0][2]);
            lands.push_back(landMatrix[1][2]);
            lands.push_back(landMatrix[1][3]);
            break;
        case 15:
            lands.push_back(landMatrix[1][3]);
            break;
        case 16:
            lands.push_back(landMatrix[1][0]);
            lands.push_back(landMatrix[2][0]);
            break;
        case 17:
            lands.push_back(landMatrix[1][0]);
            lands.push_back(landMatrix[1][1]);
            lands.push_back(landMatrix[2][1]);
            break;
        case 18:
            lands.push_back(landMatrix[1][1]);
            lands.push_back(landMatrix[2][1]);
            lands.push_back(landMatrix[2][2]);
            break;
        case 19:
            lands.push_back(landMatrix[1][2]);
            lands.push_back(landMatrix[1][3]);
            lands.push_back(landMatrix[2][3]);
            break;
        case 20:
            lands.push_back(landMatrix[1][3]);
            lands.push_back(landMatrix[2][4]);
            break;
        case 21:
        case 27:
            lands.push_back(landMatrix[2][0]);
            break;

        
        case 26:
        case 32:
            lands.push_back(landMatrix[2][4]);
            break;



        default:
            // If nodeCode doesn't match any case, leave lands as nullptr
            break;
    }
    return lands;

}
void Board::isRoadLegal(int node1, int node2)
{ // node1 < node2
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