/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#pragma once

#include <string>
#include <vector>
#include "board.hpp"
#include "road.hpp"
#include "settlement.hpp"
using namespace std;


class Catan;

class Player {

    private:
        string name;
        vector<string> cards;
        int points = 0;
        
        size_t wool = 0;
        size_t wheat = 0; 
        size_t ore = 0; 
        size_t bricks = 0;
        size_t wood = 0;

        vector<Road> roads;
        vector<Settlement> settlements;
        vector<Settlement> cities;


    public:
        Player(){}
        Player(string myName) {name = myName;}

        ~Player(){}

        //void setCatan(Catan* myCatan) {catan = myCatan;}
        string getName() {return name;}
        int getPoints() {return points;}

        void placeSettelemnt(vector<string> places, vector<int> placesNum , Board &board);
        void placeRoad(vector<string> places, vector<int> placesNum , Board &board);
        void buildCity(Settlement* settlement);

        void trade(Player p2, string resource1, string resource2, int amount1, int amount2);
        void buyDevelopmentCard();

        void printPoints();

        void addResources(vector<string> &places);
        void printResources();
        void addResourcesByNum(size_t num);

        void useRoadResources();
        void useSettlementResources();
        void addResource(Land* p_land);
};
