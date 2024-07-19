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



void Player::placeSettelemnt(vector<string> places, vector<int> placesNum , Board &board) {
    Land* land1 = board.findLand(places[0], placesNum[0]);
    Land* land2 = board.findLand(places[1], placesNum[1]);
    Settlement newSettlement(land1, land2, nullptr);
    settlements.push_back(newSettlement);
    this->points++;
}


void Player::placeRoad(vector<string> places, vector<int> placesNum , Board &board) {
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

void Player::trade(Player &p2, string resource1, string resource2, int amount1, int amount2) {

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
    Land* p_land;
    for (size_t i = 0; i < settlements.size(); ++i) {
        p_land = settlements[i].getLandByNum(num);
        if (p_land) {
            addResource(p_land);
        }
    }
    for (size_t i = 0; i < cities.size(); ++i) {
        p_land = cities[i].getLandByNum(num);
        if (p_land) {
            addResource(p_land);
            addResource(p_land);
        }
    }
}

void Player::useRoadResources() {
    if (!wood || !bricks) {
        throw ("You don't have the resources to buy a Road.");
    }
    wood--;
    bricks--;
}

void Player::useSettlementResources() {
    if (!wood || !bricks || !wool || !wheat) {
        throw ("You don't have the resources to buy a Settlement.");
    }
    --wood;
    --bricks;
    --wool;
    --wheat;
}

void Player::useCityResources() {
    if (wheat < 2 || ore < 3) {
        throw ("You don't have the resources to buy a City.");
    }
    wheat -= 2;
    ore -= 3;
}

void Player::useDevelopmentCardResources() {
    if (!wheat || !wool || !ore) {
        throw ("You don't have the resources to buy a Development Card.");
    }
    --wheat;
    --wool;
    --ore;
}

void Player::addResource(Land* p_land) {
    string land_name = p_land->getLandType();
    if (land_name == "Forest") ++wood;
    if (land_name == "Hills") ++bricks;
    if (land_name == "Agricultural Land") ++wheat;
    if (land_name == "Mountains") ++ore;
    if (land_name == "Pasture Land") ++wool;
}


void Player::placeRoad(int node1, int node2) {
    if (!hasSettlementOrCity(node1) && !hasSettlementOrCity(node2) && !hasRoad(node1) && !hasRoad(node2)) {
        throw ("Error: A Road must be settled by a settlement or by another road.");
    }
    useRoadResources();
    Road newRoad(node1, node2);
    roads.push_back(newRoad);
}

void Player::placeSettelemnt(int node, Board &board) {
    Settlement newSettlement(node);
    vector<Land*> myLands = board.getLandsByNodeCode(node);
    newSettlement.setLands(myLands);
    settlements.push_back(newSettlement);
}

void Player::buildCity(int node) {
    for (Settlement& settlement : settlements) {
        if (settlement.getNode() == node) {
            useCityResources();
            settlement.makeCity();
            return;
        }
    }
    throw ("There must be a settlement in order to build a city.");
}

bool Player::hasRoad(int node1, int node2) {
    for (Road& road : roads) {
        if (road.getNode1() == node1 && road.getNode2() == node2) {
            return true;
        }
        if (road.getNode1() == node2 && road.getNode2() == node1) {
            return true;
        }
    }
    return false;
}

bool Player::hasRoad(int node) {
    for (Road& road : roads) {
        if (road.getNode1() == node || road.getNode2() == node) {
            return true;
        }
    }
    return false;
}

bool Player::hasSettlementOrCity(int node) {
    for (Settlement& settlement : settlements) {
        if (settlement.getNode() == node) {
            return true;
        }
    }
    return false;
}

void Player::addPoints(int num) {
    points += num;
}
/*
void Player::canPlaceRoad(int node1, int node2) {

    if (!hasSettlementOrCity(node1) && !hasSettlementOrCity(node2) && !hasRoad(node1) && !hasRoad(node2)) {
        throw ("Error: A Road must be settled by a settlement or by another road.");
    }
    
}

void Player::canPlaceSettlement(int node) {
    vector<int> neighbors = neighborsOfNode(node);
    for (int neighbor : neighbors) {
        for (Road& road : roads) {
            if (road.getNode1() == neighbor && road.getNode2() != node) {
                return;
            }
            if (road.getNode2() == neighbor && road.getNode1() != node) {
                return;
            }
        }
    }
    throw ("Error: A Settlement must be settled by a settlement or by another road.");
}


vector<int> Player::neighborsOfNode(int node) {
    vector<int> neighbors;
    for (Road& road : roads) {
        if (road.getNode1() == node) {
            neighbors.push_back(road.getNode2());
        }
        if (road.getNode2() == node) {
            neighbors.push_back(road.getNode1());
        }
    }
    return neighbors;
}
*/