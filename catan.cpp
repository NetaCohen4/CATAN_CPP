/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#include <iostream>
#include <random>
#include "catan.hpp"
using namespace std;

void Catan::chooseStartingPlayer() {
    cout << "Starting Player: " << player1.getName() << endl;
    p_turn = &player1;
}

void Catan::setBoard(Board* myBoard) {
    this->board = myBoard;
}

bool Catan::isThereWinner() {
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
    cout << player.getName() << " thows " << dice << endl;
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
        
    }
    else {
        vector<Land*> lands = board->findLandsByNum(dice);
        //player1.addResources()
        player1.addResourcesByNum(dice);
    }

}

void Catan::buyRoad(Player &p, vector<string> places, vector<int> placesNum) {
    // checking whether he has enough resources
    p.useRoadResources();
    p.placeRoad(places, placesNum, *board); // p1 continues to build a road.
}

void Catan::buySettlement(Player &p, vector<string> places, vector<int> placesNum) {
    // checking whether he has enough resources
    p.useSettlementResources();
    p.placeSettelemnt(places, placesNum, *board); // p1 continues to build a road.
}

void Catan::buyCity(Player &p, vector<string> places, vector<int> placesNum) {
    // checking whether he has enough resources
    //p.useCityResources();
    //p.placeSettelemnt(places, placesNum, *board); // p1 continues to build a road.
    //p.buildCity()
}