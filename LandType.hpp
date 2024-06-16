/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

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

static string landTypeToString(LandType type) {
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
