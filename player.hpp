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
#include "developmentCard.hpp"
using namespace std;


class Catan;

class Player {

    private:
        string name;
        int points = 0;
        
        size_t wool = 0;
        size_t wheat = 0; 
        size_t ore = 0; 
        size_t bricks = 0;
        size_t wood = 0;

        vector<Road> roads;
        vector<Settlement> settlements;

        //std::vector<DevelopmentCard*> developmentCards;

    public:
        Player(){}
        Player(string myName) {name = myName;}

        ~Player(){}

        string getName() {return name;}
        int getPoints() {return points;}

        void printPoints();
        void printResources();

        void buyDevelopmentCard();

        void trade(Player &p2, string resource1, string resource2, unsigned int amount1, unsigned int amount2);
        bool hasResource(string resource, unsigned int amount);
        void changeAmountOfResource(string resource, int amount);

        void addResources(vector<string> &places);
        void addResourcesByNum(size_t num);
        void addResource(Land* p_land);

        void useRoadResources();
        void useSettlementResources();
        void useCityResources();
        void useDevelopmentCardResources();

        bool hasRoad(int node1, int node2);
        bool hasRoad(int node);
        bool hasSettlementOrCity(int node);

        void placeSettelemnt(int node, Board &board);
        void placeRoad(int node1, int node2);
        void buildCity(int node);

        void addPoints(int num);

        //void canPlaceRoad(int node1, int node2);

        //void canPlaceSettlement(int node);

        //vector<int> neighborsOfNode(int node);
        
};
