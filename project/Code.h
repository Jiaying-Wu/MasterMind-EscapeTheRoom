/*****************************************************************************
Project: Master Mind - Escape the Room
Author: Jiaying Wu
Purpose: Code header file, declare the variables and function relate to the
 generate and compare the code.
 * the code column
 * the code row
 * Each type of element
******************************************************************************/

#ifndef CODE_H
#define CODE_H

// header
#include <string>
#include <vector>

// namespace
using namespace std;

class Code {
private:
    // Static Const Variables
    static const int minPoint = 0;
    static const int maxPointWood = 98;
    static const int maxPointRock = 175;
    static const int maxPointIron = 272;

    // variable
    int *codeColumn;
    int *codeRow;
    int *totalRound;
    string *secretCode;
    string *guessCode;
    bool *isGuessCodeCorrect;

    // private function

public:
    // Constructors
    Code();


    // Destructor
    ~Code();

    // Accessor Functions
    int getCodeColumn();
    int getCodeRow();
    string getSecretCode();
    bool getIsGuessCodeCorrect();

    // Mutator Functions

};
#endif
