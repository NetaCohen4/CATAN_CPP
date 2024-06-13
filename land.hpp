#pragma once

#include <iostream>
#include <string>
using namespace std;

enum LandType {
    Forest,
    Hills,
    AgriculturalLand,
    Mountains,
    PastureLand,
    Desert
};

const string landTypeToString(LandType type) {
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


class Land {

    private:

        LandType type;
        unsigned int num;

    public:

        Land(){}
        Land(LandType myType, unsigned int myNum) {type = myType; num = myNum;}

        string getLandType() {return landTypeToString(type);}
        unsigned int getNum() {return num;}
};