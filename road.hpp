#pragma once

#include "land.hpp"

class Road {
    private:
        Land* land1;
        Land* land2;
        
        //in case of a road by a single land - to know where exactly.
        // 1: left, 2: middle, 3: right (clockwise)
        unsigned int location;

    public:


};