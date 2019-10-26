/*****************************************************************************
Project: Master Mind - Escape the Room
Author: Jiaying Wu
Purpose: Player header file, declare the variables and function relate to the
 player.
 * player name
 * the type of gate selected
 * the type of element selected
******************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

// header
#include <string>
#include <vector>

// namespace
using namespace std;

// Player class
class Player {
private:
    // Variables
    string *playerName;
    int *selectGate;
    int *selectElementType;
    string *rank;

public:
    // Constructors
    Player();

    Player(string newPlayerName,
           int newSelectGate,
           int newSelectElementType,
           string newRank
    );

    // Destructor
    ~Player();

    // Accessor Functions
    string getPlayerName();
    int getSelectGate();
    int getSelectElementType();
    string getRank();

    // Mutator Functions
    void resetSelectGate(int newSelectGate);
    void resetSelectElementType(int newSelectElementType);
    void resetRank(int winGame, int lossGame);
};
#endif
