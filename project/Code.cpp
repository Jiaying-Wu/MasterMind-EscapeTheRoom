/*****************************************************************************
Project: Master Mind - Escape the Room
Author: Jiaying Wu
Purpose: Code class file, define the variables and function relate to the
 secrete code.
 * column of code
 * row of code
 * number of possible element of the code
 The code determine by the selectGate of Player.
******************************************************************************/

// header
#include "Code.h"

Code::Code(){}

Code::Code(int newCodeColumn, int newCodeRow, int newNumberPossibleElement) {
    codeColumn = new int(newCodeColumn);
    codeRow = new int(newCodeRow);
    numberPossibleElement = new int(newNumberPossibleElement);
}

// Destructor
Code::~Code() {
    // remove from the heap
    delete codeColumn;
    delete codeRow;
    delete numberPossibleElement;
}

// ACCESSOR FUNCTIONS
int Code::getCodeColumn() {
    return *codeColumn;
}

int Code::getCodeRow() {
    return *codeRow;
}

int Code::getNumberPossibleElement() {
    return *numberPossibleElement;
}
