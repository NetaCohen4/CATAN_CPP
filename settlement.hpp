#pragma once

#include "land.hpp"

class Settlement {
    private:
        Land* land1;
        Land* land2;
        Land* land3;

        // In case of a settlement by a single land, location says where exactly:
        // 1: left option, 2: right option (clockwise)
        unsigned int location;

    public:

};