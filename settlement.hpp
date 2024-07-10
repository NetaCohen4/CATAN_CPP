/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

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
        Settlement() {}
        Settlement(Land* l1, Land* l2, Land* l3) {
            land1 = l1; land2 = l2; land3 = l3;
            cout << "new settlement was created\n";
        }

        bool operator==(const Settlement& other) const {
            return ((land1 == other.land1) && (land2 == other.land2) && (land3 == other.land3));
        }
        
};