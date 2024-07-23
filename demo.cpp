/*
    Neta Cohen
    325195774
    netaco432@gmail.com
*/

#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"
using namespace std;

int main()
{
    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");
    Catan catan(p1, p2, p3);
    // Starting of the game. Every player places two settlements and two roads.
    catan.chooseStartingPlayer();   // should print the name of the starting player, assume it is Amit.
    Board board;
    board.createBestBoard();
    catan.setBoard(&board); // get the board of the game.
    board.printBoard();

    catan.placeFirstSettlement(p1, 12);
    catan.placeFirstRoad(p1, 12, 17);

    catan.placeFirstSettlement(p2, 9);
    catan.placeFirstRoad(p2, 9, 13);

    try
    {
        catan.placeFirstSettlement(p3, 12); // p3 tries to place a settlement in the same location as p2.
    }
    catch (const string e)
    {
        cout << e << endl;
    }
    try 
    {
        catan.placeFirstSettlement(p3, 7);
    }
    catch (const string e)
    {
        cout << e << endl;
    }
    cout << endl;
    
    p1.printResources();
    p2.printResources();
    p3.printResources();

    cout << "\nGame starts!\n\n";
    // p1 has wood, bricks, and wheat, p2 has wood, ore, and wool, p3 has ore, wool, wheat.
    catan.rollDice(p1);
    try {
        catan.buyRoad(p1, 23, 29);
    }
    catch (const string e) {
        cout << e << endl;
    }
    catan.endTurn();                                // p1 ends his turn.

    catan.rollDice(p2); // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
    catan.endTurn();  // p2 ends his turn.

    catan.rollDice(p3); // Lets say it's print 3. Then, p3 gets wheat from the Agricultural Land and Ore from the Mountains, p1 gets wheat from the Agricultural Land.
    catan.endTurn();  // p3 ends his turn.

    try {
        catan.rollDice(p2); // p2 tries to roll the dice again, but it's not his turn.
    }
    catch (const string e) {
        cout << e << endl;
    }
    
    catan.rollDice(p1);
    try {
        p1.trade(p2, "wood", "brick", 1, 1);
    }
    catch (const string e) {
        cout << e << endl;
    }
    catan.endTurn();

    catan.rollDice(p2);
    try {
        catan.buyDevelopmentCard(p2); 
    }
    catch (const string e) {
        cout << e << endl;
    }
    catan.endTurn();            // p2 ends his turn.

    try {
        catan.buyDevelopmentCard(p3); 
    }
    catch (const string e) {
        cout << e << endl;
    }
    catan.playDevelopmentCard(p3, "Knight");
    catan.playDevelopmentCard(p3, "Victory Point");

    p1.printResources();
    p2.printResources();
    p3.printResources();

    catan.printWinner(); // Should print None because no player reached 10 points.
    
}