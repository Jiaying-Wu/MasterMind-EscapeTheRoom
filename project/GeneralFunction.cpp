/*****************************************************************************
Project: Master Mind - Escape the Room
Author: Jiaying Wu
Purpose: GeneralFunction class file, define the function for general use.
 Eg, ask user input, read and write file.
******************************************************************************/

#include "GeneralFunction.h"

// function to display the title
void displayTitle() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\tMasterMind :: Escape the Room\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

// function to ask string input
string askForString(string question) {
    // gets a line response (spaces included)
    string userInput = "";
    while (userInput == "") {
        cout << " " + question;
        getline(cin, userInput);
    }
    return userInput;
}

// function to ask integer input
int askForInteger(string question) {
    // get a line response
    int userInput = 0;
    cout << " " + question;
    cin >> userInput;
    return userInput;
}


// function to read the text file
void readFile(string readFileName) {
    // open file for reading
    ifstream fileToRead(readFileName);
    // print the file to screen
    if (fileToRead.is_open()) {
        string line = "";
        while (!fileToRead.eof()) {
            getline(fileToRead, line);
            cout << line << "\n";
        }
    } else {
        cout << "\n" << readFileName << " not found!\n";
    }
    // close the file
    fileToRead.close();
}

// function to write data into file
void writeFile(string writeFileName, string writeData) {
    // open the file to write
    ofstream fileToWrite(writeFileName, ios::app);
    if (fileToWrite.is_open()) {
        fileToWrite << writeData << endl;
    } else {
        cout << "\n" << writeFileName << " not found!\n";
    }
    // close the file
    fileToWrite.close();
}