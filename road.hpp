/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#pragma once

#include "land.hpp"

class Road {
    private:
        
        int node_code1; // Always the apper one
        int node_code2; // The lower one

    public:
        Road() {}
        Road(int node1, int node2) : node_code1(node1), node_code2(node2) {}

        int getNode1() {return node_code1;}
        int getNode2() {return node_code2;}

};