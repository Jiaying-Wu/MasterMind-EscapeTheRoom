/*****************************************************************************
Project: Master Mind - Escape the Room
Author: Jiaying Wu
Purpose: materMindAchievement header file, to maintain Achievement page.
 * include required header file and namespace
 * declare static variable
 * declare variable and function for Achievement
******************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

// header
#include <string>
#include <array>

// namespace
using namespace std;

// class
class masterMindAchievement {
private:
    // Static Const Variables
    static const int minPoint = 0;
    static const int maxPointWood = 98;
    static const int maxPointRock = 175;
    static const int maxPointIron = 272;

    // variables
    string *playerName;
    int *playerRank;
    int *gateAttempt;
    int *gateOpen;
    int *totalPoint;
    int *highestPointWood;
    int *highestPointRock;
    int *highestPointIron;

public:
// constructor
    masterMindAchievement();
    masterMindAchievement(string playerName, int score);
// Destructor
    ~masterMindAchievement();
// accessor methods
    string getName();
    int getScore();
// mutator methods
    void resetScore(int newScore);
    void updateScore(int newScore);

};
#endif
