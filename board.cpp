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
        /*
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
        */
        
        
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