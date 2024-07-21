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



void Player::trade(Player &p2, string resource1, string resource2, unsigned int amount1, unsigned int amount2) {
    
    // Make sure they have enough of the resources
    if (!hasResource(resource1, amount1) || !p2.hasResource(resource2, amount2)) {
        throw ((string)"Error: Trade cannot be performed, players do not have the required resources.");
    }
    // Make the trade
    this->changeAmountOfResource(resource1, -amount1);
    this->changeAmountOfResource(resource2, amount2);
    p2.changeAmountOfResource(resource1, amount1);
    p2.changeAmountOfResource(resource2, -amount2);
    
}

bool Player::hasResource(string resource, unsigned int amount) {
    if (resource == "ore") {
        return (ore >= amount);
    } else if (resource == "wheat") {
        return (wheat >= amount);
    } else if (resource == "wool") {
        return (wool >= amount);
    } else if (resource == "wood") {
        return (wood >= amount);
    } else if (resource == "bricks") {
        return (bricks >= amount);
    }
    throw ("Error: There is no such resource as " + resource);
}

void Player::changeAmountOfResource(string resource, int amount) {
    if (resource == "ore") {
        ore += amount;
        return;
    } else if (resource == "wheat") {
        wheat += amount;
        return;
    } else if (resource == "wool") {
        wool += amount;
        return;
    } else if (resource == "wood") {
        wood += amount;
        return;
    } else if (resource == "bricks") {
        bricks += amount;
        return;
    }
    throw ("Error: There is no such resource as " + resource);
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
    vector<Land*> relevant_lands;
    vector<Land*> all_relevant_lands;
    for (Settlement& settlement : settlements) {
        relevant_lands = settlement.getLandsByNum(num);
        all_relevant_lands.insert(all_relevant_lands.end(), relevant_lands.begin(), relevant_lands.end());
    }
    for (Land* land : all_relevant_lands) {
        addResource(land);
    }
}

void Player::useRoadResources() {
    if (!wood || !bricks) {
        throw ((string)"You don't have the resources to buy a Road.");
    }
    wood--;
    bricks--;
}

void Player::useSettlementResources() {
    if (!wood || !bricks || !wool || !wheat) {
        throw ((string)"You don't have the resources to buy a Settlement.");
    }
    --wood;
    --bricks;
    --wool;
    --wheat;
}

void Player::useCityResources() {
    if (wheat < 2 || ore < 3) {
        throw ((string)"You don't have the resources to buy a City.");
    }
    wheat -= 2;
    ore -= 3;
}

void Player::useDevelopmentCardResources() {
    if (!wheat || !wool || !ore) {
        throw ((string)"You don't have the resources to buy a Development Card.");
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
    Road newRoad(node1, node2);
    roads.push_back(newRoad);
}

void Player::placeSettelemnt(int node, Board &board) {
    Settlement newSettlement(node);
    vector<Land*> myLands = board.getLandsByNodeCode(node);
    newSettlement.setLands(myLands);
    settlements.push_back(newSettlement);
    points++;
}

void Player::buildCity(int node) {
    for (Settlement& settlement : settlements) {
        if (settlement.getNode() == node) {
            useCityResources();
            settlement.makeCity();
            points++;
            return;
        }
    }
    throw ((string)"There must be a settlement in order to build a city.");
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
