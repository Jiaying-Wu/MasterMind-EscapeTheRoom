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

int winGame;

int losGame;

// declare function
string askForString(string question);

void readFile(string textFileName);

void displayMainPage();

void setFirstGame();

void multiGameLoop();

bool checkMultiGameOver();

void oneGameLoop();

vector<string> generatePossibleElementSet(int type, int keepElement);

vector<string> generateSecretCode(vector<string> elementSet, int codeColumn);

vector<string> askForGuessCode(vector<string> possibleElement);

vector<string> storeTotalGuessCode(vector<string> storeCode);

void displayTitle();

void displayTable(vector<string> allGuessCode, int currentRound, int column);

string generateHint(vector<string> guess, vector<string> secret);

bool checkOneGameOver(int currentRound, int totalRound, vector<string> secret, vector<string> guess, int win, int lost);

void feedBack(string name, string rank,int win, int lost, int gamePoint, int maxPoint);
#endif