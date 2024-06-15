/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "player.hpp"
using namespace std;



void Player::placeSettelemnt(vector<string> places, vector<int> placesNum , Board board) {

}

void Player::placeRoad(vector<string> places, vector<int> placesNum , Board board) {

}

int Player::rollDice() {
    // Create a random device to seed the random number generator
    std::random_device rd;
    // Initialize the random number generator with the seed
    std::mt19937 gen(rd());
    // Define a distribution that produces numbers between 1 and 6 (inclusive)
    std::uniform_int_distribution<> dis(1, 6);

    // Generate a random number between 1 and 6
    int dice = dis(gen);
    dice += dis(gen);
    return dice;
}

void Player::endTurn() {
    
}

void Player::trade(Player p2, string resource1, string resource2, int amount1, int amount2) {

}

void Player::buyDevelopmentCard() {

}

void Player::printPoints() {
    cout << name << ": " << points << "points" << endl;
}




