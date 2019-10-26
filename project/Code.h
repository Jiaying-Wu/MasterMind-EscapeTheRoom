/*****************************************************************************
Project: Master Mind - Escape the Room
Author: Jiaying Wu
Purpose: Code header file, declare the variables and function relate to the
 generate and compare the code.
 * column of code
 * row of code
 * number of possible element of the code
 The code determine by the selectGate of Player.
******************************************************************************/

#ifndef CODE_H
#define CODE_H

// header
#include <string>
#include <vector>

// namespace
using namespace std;

// Code class
class Code {
private:
    // Static Const Variables
    static const int maxPointWood = 98;
    static const int maxPointRock = 175;
    static const int maxPointIron = 272;

    // variable
    int *codeColumn;
    int *codeRow;
    int *numberPossibleElement;

public:
    // Constructors
    Code();

    Code(int newCodeColumn,
         int newCodeRow,
         int newPossibleElement
    );

    // Destructor
    ~Code();

    // Accessor Functions
    int getCodeColumn();

    int getCodeRow();

    int getNumberPossibleElement();

    int getMaxPoint(int gate);

    // Mutator Functions
    void resetCodeColumn(int newCodeColumn);

    void resetCodeRow(int newCodeRow);
};

#endif
