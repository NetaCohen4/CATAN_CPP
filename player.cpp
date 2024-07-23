/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include "player.hpp"
#include <stdexcept>
#include "developmentCard/knightCard.hpp"
#include "developmentCard/victoryPointCard.hpp"
#include "developmentCard/monopolyCard.hpp"
#include "developmentCard/roadBuildingCard.hpp"
#include "developmentCard/yearOfPlentyCard.hpp"
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
        if (ore + amount < 0) throw ((string)"Error: You have no ore to throw.");
        ore += amount;
        return;
    } else if (resource == "wheat") {
        if (wheat + amount < 0) throw ((string)"Error: You have no wheat to throw.");
        wheat += amount;
        return;
    } else if (resource == "wool") {
        if (wool + amount < 0) throw ((string)"Error: You have no wool to throw.");
        wool += amount;
        return;
    } else if (resource == "wood") {
        if (wood + amount < 0) throw ((string)"Error: You have no wood to throw.");
        wood += amount;
        return;
    } else if (resource == "bricks") {
        if (bricks + amount < 0) throw ((string)"Error: You have no bricks to throw.");
        bricks += amount;
        return;
    }
    throw ("Error: There is no such resource as " + resource);
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
    cout << name << " has: " << wool << " wool, " << wheat << " wheat, " << ore << " ore, "
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

void Player::addResource(string resource) {
    if (resource == "Forest") ++wood;
    if (resource == "Hills") ++bricks;
    if (resource == "Agricultural Land") ++wheat;
    if (resource == "Mountains") ++ore;
    if (resource == "Pasture Land") ++wool;
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

void Player::buyDevelopmentCard() {
    // Generate a random number to select a card type
    //int randomIndex = std::rand() % 5; 
    // Create a random device to seed the random number generator
    std::random_device rd;
    // Initialize the random number generator with the seed
    std::mt19937 gen(rd());
    // Define a distribution that produces numbers between 1 and 6 (inclusive)
    std::uniform_int_distribution<> dis(0, 4);
    // Generate a random number between 1 and 6
    size_t randomIndex = dis(gen);

    DevelopmentCard* newCard = nullptr;
    switch (randomIndex) {
        case 0:
            newCard = new KnightCard();
            break;
        case 1:
            newCard = new VictoryPointCard();
            break;
        case 2:
            newCard = new MonopolyCard();
            break;
        case 3:
            newCard = new YearOfPlentyCard();
            break;
        case 4:
            newCard = new RoadBuildingCard();
            break;

        // Add other cases for different card types
        default:
            newCard = new KnightCard(); // Default case (should not happen)
            break;
    }

    developmentCards.push_back(newCard);
}

const std::vector<DevelopmentCard*>& Player::getDevelopmentCards() const {
    return developmentCards;
}

void Player::removeDevelopmentCard(const std::string &kind) {

    for (auto it = developmentCards.begin(); it != developmentCards.end(); ++it) {
        if ((*it)->getName() == kind) {
            delete *it;
            developmentCards.erase(it);
            return;
        }
    }
}

void Player::addKnight() {
    knights++;
    if (knights == 3) {
        points += 2;
    }
}

void Player::seven() {
    int cardsNum = wool + wheat + ore + bricks + wood;
    if (cardsNum > 7) {
        cout << name << " you got more than 7 resource cards: ";
        printResources();
        cout << "Please choose " << cardsNum/2 <<" cards to throw.\n";
        string card;
        for (int i = 0; i < cardsNum/2; ++i) {
            cin >> card;
            try {
                changeAmountOfResource(card, -1);
            } 
            catch (const string e) {
                cout << e << endl;
                ++i;
            }
        }
    }
}