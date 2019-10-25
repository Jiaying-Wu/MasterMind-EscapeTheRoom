/*****************************************************************************
Project: Master Mind - Escape the Room
Author: Jiaying Wu
Purpose: masterMind header file, declare the variable and function for the
 overall flow of the game.
 *
 *
******************************************************************************/

#ifndef MASTERMIND_H
#define MASTERMIND_H

// header
#include <iostream>
#include <fstream>
#include <ctime>
#include "Player.h"
#include "Code.h"

// declare variable

Player player;

Code code;

bool *isMainPageOver;

bool *isOneGameOver;

int *totalGameRound;

int *currentGameRound;

vector<string> *secretCode;

vector<string> *guessCode;

bool *isMultiGameOver;


// declare function
void displayTitle();

string askForString(string question);

void readFile(string textFileName);

void writeFile(string writeFileName, string writeData);

void displayMainPage();

void oneGameLoop();

void setGame();

vector<string> generateSecretCode();

vector<string> askForGuessCode();

bool checkOneGameOver();

void multiGameLoop();

bool checkMultiGameOver();

#endif