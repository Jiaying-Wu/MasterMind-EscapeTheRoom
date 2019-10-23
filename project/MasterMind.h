/*****************************************************************************
Project: Master Mind - Escape the Room
Author: Jiaying Wu
Purpose: masterMind header file, declare the variable and function for the
 overall flow of the game.
******************************************************************************/

#ifndef MASTERMIND_H
#define MASTERMIND_H

// header
#include <string>
#include <vector>
#include "GeneralFunction.h"

// namespace
using namespace std;

// declare variable
string currentOption = "m";
bool isMainPageOver = false;


bool isGameOver;

bool isNewGame;


// declare function
void displayMainPage(string currentOption);

void gameLoop();

bool checkGameOver();

#endif