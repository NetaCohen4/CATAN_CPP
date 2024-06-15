/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#pragma once

#include "land.hpp"

class City {
    private:
        Land* land1;
        Land* land2;
        Land* land3;

        // In case of a city by a single land, location says where exactly:
        // 1: left option, 2: right option (clockwise)
        unsigned int location;

    public:

};