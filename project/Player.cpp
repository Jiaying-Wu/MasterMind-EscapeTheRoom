/*****************************************************************************
Project: Master Mind - Escape the Room
Author: Jiaying Wu
Purpose: Player header file, declare the variables and function relate to the
 player.
 * player name
 * the type of gate selected
 * the type of element selected
******************************************************************************/

// header
#include "Player.h"

Player::Player(){}

Player::Player(string newPlayerName, int newSelectGate, int newSelectElementType, string newRank) {
    playerName = new string(newPlayerName);
    selectGate = new int(newSelectGate);
    selectElementType = new int(newSelectElementType);
    rank = new string(newRank);
}

// Destructor
Player::~Player() {
    // remove from the heap
    delete playerName;
    delete selectGate;
    delete selectElementType;
}

// ACCESSOR FUNCTIONS
string Player::getPlayerName() {
    return *playerName;
}

int Player::getSelectGate() {
    return *selectGate;
}

int Player::getSelectElementType() {
    return *selectElementType;
}

string Player::getRank() {
    return *rank;
}

// MUTATOR FUNCTIONS

void resetSelectGate(int newSelectGate) {
    if (newSelectGate >= 1 && newSelectGate <= 3) {
        *selectGate = newSelectGate;
    }
}

void resetSelectElementType(int newSelectElementType) {
    if (newSelectElementType >= 1 && newSelectElementType <= 4) {
        *selectElementType = newSelectElementType;
    }
}

void resetRank(int winGame, int lossGame) {
    if (winGame - lossGame >= 5 && winGame - lossGame <= 10) {
        *rank = "Expert";
    }
    else if (winGame - lossGame >= 10) {
        *rank = "Master";
    }
    else {
        *rank = "Beginner";
    }
}