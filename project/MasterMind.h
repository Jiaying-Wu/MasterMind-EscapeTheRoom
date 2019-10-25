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

vector<string> *possibleElementSet;

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

vector<string> generatePossibleElementSet(int type, int keepElement);

vector<string> generateSecretCode(vector<string> elementSet, int codeColumn);

vector<string> askForGuessCode();

void displayTable();

bool checkOneGameOver();

void multiGameLoop();

bool checkMultiGameOver();

#endif