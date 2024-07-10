/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "player.hpp"
#include <stdexcept>
using namespace std;



void Player::placeSettelemnt(vector<string> places, vector<int> placesNum , Board board) {
    Land* land1 = board.findLand(places[0], placesNum[0]);
    Land* land2 = board.findLand(places[1], placesNum[1]);
    Settlement newSettlement(land1, land2, nullptr);
    settlements.push_back(newSettlement);
    this->points++;
}

void Player::placeRoad(vector<string> places, vector<int> placesNum , Board board) {
    Land* land1 = board.findLand(places[0], placesNum[0]);
    Land* land2 = board.findLand(places[1], placesNum[1]);
    
    Road newRoad(land1, land2);
    roads.push_back(newRoad);
}

void Player::buildCity(Settlement* settlement) {
    this->cities.push_back(*settlement);
    settlements.erase(std::remove(settlements.begin(), settlements.end(), *settlement), settlements.end());
    this->points++;
}

void Player::trade(Player p2, string resource1, string resource2, int amount1, int amount2) {

}

void Player::buyDevelopmentCard() {

}

void Player::printPoints() {
    cout << name << ": " << points << " points" << endl;
}

void Player::addResources(vector<string> &places) {
    for (const auto& place : places) {
        if (place == "Mountains") {
            ore++;
        } else if (place == "Agricultural Land") {
            wheat++;
        } else if (place == "Pasture Land") {
            wool++;
        } else if (place == "Forest") {
            wood++;
        } else if (place == "Hills") {
            bricks++;
        }
    }
}

void Player::printResources() {
    cout << name << " has: " << wool << " wool, " << wheat << " weat, " << ore << " ore, "
     << bricks << " bricks, " << wood << " wood.\n";
}

void Player::addResourcesByNum(size_t num) {
    vector<Settlement> settlements;
    vector<Settlement> cities;

    for (size_t i = 0; i < settlements.size(); ++i) {
        //settlements[i]
    }
}
