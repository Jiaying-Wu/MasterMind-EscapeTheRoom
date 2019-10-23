/*****************************************************************************
Project: Master Mind - Escape the Room
Author: Jiaying Wu
Purpose: Player class file, define the variables and functions related to
 the player.
******************************************************************************/

// header
#include "masterMindAchievement.h"

Player::Player() {}

Player::Player(string newName, CharType newType) {
    // usual creation constructor
    charName = new string(newName);
    charType = new CharType(newType);
    setInitialStats();
    itemCount = new int(0);
    inventory[MAX_ITEMS];
}

// Destructor
Character::~Character() {
    // remove from the heap
    delete charName;
    delete charType;
    delete charHealth;
    delete charStrength;
    delete charDexterity;
    delete charIntelligence;
    delete itemCount;
}

// ACCESSOR FUNCTIONS
string Character::getCharName() { return *charName; }

CharType Character::getTypeNum() { return *charType; }

int Character::getHealth() { return *charHealth; }

int Character::getStrength() { return *charStrength; }

int Character::getDexterity() { return *charDexterity; }

int Character::getIntelligence() { return *charIntelligence; }

int Character::getItemCount() { return *itemCount; }
