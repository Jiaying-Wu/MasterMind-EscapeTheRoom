/*****************************************************************************
Project: Master Mind - Escape the Room
Author: Jiaying Wu
Purpose: masterMind header file, declare the variable and function for the
 overall flow of the game.
 * loop for Main page
 * loop for each round of one game
 * loop for each game of multi game
 * compare guess code and secret code, display output table
 * feedback when one game finish
******************************************************************************/

#ifndef MASTERMIND_H
#define MASTERMIND_H

// header
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <random>
#include <iterator>
#include <algorithm>
#include "Player.h"
#include "Code.h"

// declare variable

Player player;

Code code;

bool *isMainPageOver;

bool *isOneGameOver;

int *totalGameRound;

int *currentGameRound;

vector<string> *possibleElementSet;

vector<string> *secretCode;

vector<string> *guessCode;

vector<string> *totalGuessCode;

bool *isMultiGameOver;


// declare function
void displayTitle();

string askForString(string question);

void readFile(string textFileName);

void writeFile(string writeFileName, string writeData);

void displayMainPage();

void oneGameLoop();

void setFirstGame();

vector<string> generatePossibleElementSet(int type, int keepElement);

vector<string> generateSecretCode(vector<string> elementSet, int codeColumn);

vector<string> askForGuessCode(vector<string> possibleElement);

vector<string> storeTotalGuessCode(vector<string> storeCode);

void displayTable();

bool checkOneGameOver(int currentRound, int totalRound, vector<string> secret, vector<string> guess);

void feedBack();

void multiGameLoop();

bool checkMultiGameOver();

#endif