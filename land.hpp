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
        size_t num;

    public:

        Land(){type = Desert; num = 0;}
        Land(LandType myType, unsigned int myNum) {type = myType; num = myNum;}

        string getLandType() {return landTypeToString(type);}
        size_t getNum() {return num;}
        void printLand() {cout << landTypeToString(type) << " " << num;}
};
