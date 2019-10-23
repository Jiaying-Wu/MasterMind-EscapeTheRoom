/*****************************************************************************
Project: Master Mind - Escape the Room
Author: Jiaying Wu
Purpose: GeneralFunction header file, declare the function for general use.
 Eg, ask user input, read and write file.
******************************************************************************/

#ifndef GENERALFUNCTION_H
#define GENERALFUNCTION_H

// header
#include <iostream>
#include <fstream>
#include <string>

// namespace
using namespace std;

// declare function
void displayTitle();

string askForString(string question);

void readFile(string textFileName);

void writeFile(string writeFileName, string writeData);


// class
class GeneralFunction {

};


#endif
