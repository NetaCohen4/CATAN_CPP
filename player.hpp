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
#include "city.hpp"
using namespace std;


class Catan;

class Player {

    private:
        string name;
        vector<string> cards;
        int points = 0;
        Catan* catan;

        vector<Road> roads;
        vector<Settlement> settlements;
        vector<City> cities;


    public:
        Player(){}
        Player(string myName) {name = myName;}

        void setCatan(Catan* myCatan) {catan = myCatan;}
        string getName() {return name;}

        void placeSettelemnt(vector<string> places, vector<int> placesNum , Board board);
        void placeRoad(vector<string> places, vector<int> placesNum , Board board);
        void buildCity(Settlement* settlement);
        int rollDice();
        void endTurn();
        void trade(Player p2, string resource1, string resource2, int amount1, int amount2);
        void buyDevelopmentCard();
        void printPoints();

};
