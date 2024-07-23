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
#include "developmentCard/developmentCard.hpp"
using namespace std;


class Catan;

class Player {

    private:
        string name;
        int points = 0;
        
        unsigned int wool = 0;
        unsigned int wheat = 0; 
        unsigned int ore = 0; 
        unsigned int bricks = 0;
        unsigned int wood = 0;

        vector<Road> roads;
        vector<Settlement> settlements;

        vector<DevelopmentCard*> developmentCards;
        unsigned int knights = 0;

    public:
        Player(){}
        Player(string myName) {name = myName;}

        ~Player() {
            for (auto card : developmentCards) {
                delete card;
            }
        }

        string getName() {return name;}
        int getPoints() {return points;}

        void printPoints();
        void printResources();

        void trade(Player &p2, string resource1, string resource2, unsigned int amount1, unsigned int amount2);
        bool hasResource(string resource, unsigned int amount);
        void changeAmountOfResource(string resource, int amount);

        void addResources(vector<string> &places);
        void addResourcesByNum(size_t num);
        void addResource(Land* p_land);
        void addResource(string resource);

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

        const std::vector<DevelopmentCard*>& getDevelopmentCards() const; 
        void buyDevelopmentCard();
        void removeDevelopmentCard(const std::string &kind);
        //void playDevelopmentCard(const std::string &kind);
        void addKnight();

        void seven();
};
