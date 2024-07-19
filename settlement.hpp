/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#pragma once

#include "land.hpp"

class Settlement {
    private:
        vector<Land*> lands;
        int node_code;
        bool city = false;

        // To be deleted:
        Land* land1;
        Land* land2;
        Land* land3;


    public:
        // Default constructor
        Settlement() : land1(nullptr), land2(nullptr), land3(nullptr){}

        Settlement(int node) : node_code(node) {}

        // Constructor with initialization list
        Settlement(Land* l1, Land* l2, Land* l3) : land1(l1), land2(l2), land3(l3){
            std::cout << "New settlement was created\n";
        }

        bool operator==(const Settlement& other) const {
            return ((land1 == other.land1) && (land2 == other.land2) && (land3 == other.land3));
        }

        int getNode() {return node_code;}
        vector<Land*> getLands() {return lands;}
        void setLands(vector<Land*> &myLands) {lands = myLands;}
        bool isCity() {return city;}

        void makeCity() {
            if (city) {
                throw ("There is already a city there.");
            }
            city = true;
        }

        Land* getLandByNum(size_t num) {
            if (land1) {
                if (land1->getNum() == num) {
                    return land1;
                }
            }
            if (land2) {
                if (land1->getNum() == num) {
                    return land2;
                }
            }
            if (land1) {
                if (land3->getNum() == num) {
                    return land3;
                }
            }
            return nullptr;
        }
};