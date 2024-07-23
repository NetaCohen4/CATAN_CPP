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
        int node_code = -1;
        bool city = false;

    public:
        Settlement() {}
        Settlement(int node) : node_code(node) {}
/*
        // Constructor with initialization list
        Settlement(Land* l1, Land* l2, Land* l3) : land1(l1), land2(l2), land3(l3){
            std::cout << "New settlement was created\n";
        }
*/
        bool operator==(const Settlement& other) const {
            // Compare node_code and city first
            if (node_code != other.node_code || city != other.city) {
                return false;
            }
            // Compare the size of the lands vectors
            if (lands.size() != other.lands.size()) {
                return false;
            }
            // Compare each element in the lands vectors
            for (size_t i = 0; i < lands.size(); ++i) {
                if (lands[i] != other.lands[i]) {
                    return false;
                }
            }
            return true;
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

        vector<Land*> getLandsByNum(int num) {
            vector<Land*> relevant_lands;
            for (Land* land : lands) {
                if (land->getNum() == num) {
                    relevant_lands.push_back(land);
                    if (city) {
                        relevant_lands.push_back(land);
                    }
                }
            }
            return relevant_lands;
        }
};