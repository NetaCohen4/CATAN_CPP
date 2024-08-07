/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#include <iostream>
#include <random>
#include "catan.hpp"
#include "board.hpp"
using namespace std;

void Catan::chooseStartingPlayer() {
    cout << "Starting Player: " << player1.getName() << endl;
    p_turn = &player1;
}

void Catan::setBoard(Board* myBoard) {
    this->board = myBoard;
}

bool Catan::isThereWinner() {
    player1.printPoints();
    player2.printPoints();
    player3.printPoints();
    if (player1.getPoints() >= 10) return true;
    if (player2.getPoints() >= 10) return true;
    if (player3.getPoints() >= 10) return true;
    return false;
}

void Catan::printWinner() {
    if (this->isThereWinner()) {
        cout << "Winner: ";
        if (player1.getPoints() >= 10) {
            cout << player1.getName() << endl;
        }
        if (player2.getPoints() >= 10) {
            cout << player2.getName() << endl;
        }
        if (player3.getPoints() >= 10) {
            cout << player3.getName() << endl;
        }
    }
    else {
        cout << "There is no winner.\n";
    }
}

void Catan::rollDice(Player &player) {
    isItHisTurn(player);
    cout << p_turn->getName() << "'s turn:\n";

    // Create a random device to seed the random number generator
    std::random_device rd;
    // Initialize the random number generator with the seed
    std::mt19937 gen(rd());
    // Define a distribution that produces numbers between 1 and 6 (inclusive)
    std::uniform_int_distribution<> dis(1, 6);
    // Generate a random number between 1 and 6
    size_t dice = dis(gen);
    dice += dis(gen);
    
    cout << player.getName() << " throws " << dice << endl;
    distributeResources(dice);
}

void Catan::endTurn() {
    if (p_turn == &player1) {
        p_turn = &player2;
    } else {
        if (p_turn == &player2) {
            p_turn = &player3;
        }
        else {
            p_turn = &player1;
        }
    }
}

void Catan::distributeResources(size_t dice) {
    if (dice == 7) {
        player1.seven();
        player2.seven();
        player3.seven();
    }
    else {
        player1.addResourcesByNum(dice);
        player2.addResourcesByNum(dice);
        player3.addResourcesByNum(dice);
    }

}

void Catan::buyDevelopmentCard(Player &p) {
    isItHisTurn(p);
    p.useDevelopmentCardResources();
    p.buyDevelopmentCard();
}

void Catan::playDevelopmentCard(Player &p, const std::string &kind) {
    isItHisTurn(p);
    vector<DevelopmentCard*> developmentCards= p.getDevelopmentCards();
    for (DevelopmentCard* developmentCard : developmentCards) {
        if (developmentCard->getName() == kind) {
            developmentCard->play(p, *this);
            p.removeDevelopmentCard(kind);
            return;
        }
    }
    std::cout << "You do not have a " << kind << " card to play.\n";
}

void Catan::isItHisTurn(Player &player) const {
    if (p_turn->getName() != player.getName()) {
        throw (player.getName() + " tried to make action out of turn");
    }
}


void Catan::buyCity(Player &p, int node) {
    isItHisTurn(p);
    p.buildCity(node);
}

void Catan::buySettlement(Player &p, int node) {
    isItHisTurn(p);
    // Checking that the spot exists and available
    isNodeAvailable(node);
    // checking whether he has enough resources
    p.useSettlementResources();
    p.placeSettelemnt(node, *board); // p1 continues to build a road.
}

void Catan::isNodeAvailable(int node) {
    if (player1.hasSettlementOrCity(node) || player2.hasSettlementOrCity(node) || player3.hasSettlementOrCity(node)) {
        throw ((string)"Error: Attempt of building a Settlement in an unavailable place");
    }
    vector<int> neighbors = nodeNeighbors(node);
    // Checking that there aren't any settlements in the node's neighbors
    for (int neighbor : neighbors) {
        if (player1.hasSettlementOrCity(neighbor) || player2.hasSettlementOrCity(neighbor) || player3.hasSettlementOrCity(neighbor) ) {
            throw ((string)"Error: Can not build right next to another settlement.");
        }
    }
}

void Catan::buyRoad(Player &p, int node1, int node2) {
    isItHisTurn(p);
    board->isRoadLegal(node1, node2);
    isRoadAvailable(node1, node2);
    if (!p.hasSettlementOrCity(node1) && !p.hasSettlementOrCity(node2) && !p.hasRoad(node1) && !p.hasRoad(node2)) {
        throw ((string)"Error: A Road must be settled by a settlement or by another road.");
    }
    p.useRoadResources();
    p.placeRoad(node1, node2);
}

void Catan::isRoadAvailable(int node1, int node2) {
    if (player1.hasRoad(node1, node2) || player2.hasRoad(node1, node2) || player3.hasRoad(node1, node2)) {
        throw ((string)"Error: Attempt of building a road in an unavailable place");
    }
}

void Catan::placeFirstSettlement(Player &p, int node) {
    // Checking that the spot exists and available
    isNodeAvailable(node);
    p.placeSettelemnt(node, *board);
    addResources(p, node);
}

void Catan::placeFirstRoad(Player &p, int node1, int node2) {
    board->isRoadLegal(node1, node2);
    isRoadAvailable(node1, node2);
    if (!p.hasSettlementOrCity(node1) && !p.hasSettlementOrCity(node2) && !p.hasRoad(node1) && !p.hasRoad(node2)) {
        throw ((string)"Error: A Road must be settled by a settlement or by another road.");
    }
    p.placeRoad(node1, node2);
}

void Catan::addResources(Player &p, int node) {
    vector<Land*> lands = board->getLandsByNodeCode(node);
    for (Land* land : lands) {
        p.addResource(land);
    }
}

void Catan::trade(Player &p1, Player &p2, string resource1, string resource2, unsigned int amount1, unsigned int amount2) {
    isItHisTurn(p1);
    p1.trade(p2, resource1, resource2, amount1, amount2);
}

void Catan::monopoly(Player &p, string resource) {

    if (p.getName() != player1.getName()) {
        while (player1.hasResource(resource, 1)) {
            player1.changeAmountOfResource(resource, -1);
            p.changeAmountOfResource(resource, 1);
        }
    }

    if (p.getName() != player2.getName()) {
        while (player2.hasResource(resource, 1)) {
            player2.changeAmountOfResource(resource, -1);
            p.changeAmountOfResource(resource, 1);
        }
    }

    if (p.getName() != player3.getName()) {
        while (player3.hasResource(resource, 1)) {
            player3.changeAmountOfResource(resource, -1);
            p.changeAmountOfResource(resource, 1);
        }
    }
}