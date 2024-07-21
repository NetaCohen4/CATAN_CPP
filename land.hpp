/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#pragma once

#include <iostream>
#include <string>
#include "LandType.hpp"
using namespace std;



class Land {

    private:
        LandType type;
        int num;

    public:

        Land(){type = Desert; num = 0;}
        Land(LandType myType, unsigned int myNum) {type = myType; num = myNum;}

        bool operator==(const Land& other) const {
            return (this->type == other.type) && (this->num == other.num);
        }

        string getLandType() {return landTypeToString(type);}
        int getNum() {return num;}
        void printLand() {cout << landTypeToString(type) << " " << num;}
};
