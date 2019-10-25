/*****************************************************************************
Project: Master Mind - Escape the Room
Author: Jiaying Wu
Purpose: Application file, to hold the main() function and controls the overall
 flow of the game.
 * loop for Main page
 * loop for one game
 * loop for player want to continue next game
 * compare guess code and secret code, display ouput table
 * feedback when one game finish
******************************************************************************/

// header
#include "MasterMind.h"


// main function
int main(){
    // display Main page, break the loop if select [N], [C] or [E]
    displayMainPage();
    // user select [N] or [C]
    multiGameLoop();
    // user select [E], pause and wait for exit
    system("pause");
    return 0;
}

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

// loop for Main page, continue Main page until [N], [C] or [E] enter.
void displayMainPage() {
    *isMainPageOver = false;
    // display the main page
    while (!*isMainPageOver) {
        // clear the screen and display Main page.
        system("cls");
        readFile("masterMindMainPage.txt");

        string userInput = "";
        userInput = askForString("\n Enter your option: ");

        // keep asking string input until enter [N], [C], [H], [E] in Main page
        while (userInput != "n" || userInput != "N" || userInput != "c" || userInput != "C" ||
               userInput != "h" || userInput != "H" || userInput != "e" || userInput != "E") {
            cout << "\n\n Please enter [N], [C], [H] or [E] only.\n";
            userInput = askForString("\n Enter your option: ");
        }

        // user select [H] display Help page, then back to Main page.
        if (userInput == "h" || userInput == "H") {
            *isMainPageOver = false;
            // clear the screen to display Help page.
            system("cls");
            readFile("masterMindHelpPage.txt");
            // pause the screen to allow player read the information
            system("pause");
        }

        // break the while loop when [C], [N], [E] selected.
        else {
            *isMainPageOver = true;
        }
    }
}

/************************************
// clear the screen to start the game
system("cls");

// user select [N] New game.
if (currentOption == "n" || currentOption == "N"){
// display Set Up page.
readFile("masterMindSetUpPage.txt");
// pause the screen to allow player read the information
system("pause");
}
// user select [C] Continue the saved game.
else if (currentOption == "c" || currentOption == "C") {

}
**********************/



// start the game when select [S] or [C]
void oneGameLoop() {
    // check is the multi game loop end
    *isOneGameOver = false;
    *isOneGameOver = checkMultiGameOver();
    while(!isOneGameOver) {

    }
}

// function to check one game is over
bool checkOneGameOver() {
    // finish all game rounds
    if (*currentGameRound = *totalGameRound) {
        return true;
    }
    // the guess code match the secret code
    else if (*isGuessCodeCorrect){
        return true;
    }
    // player enter [E] when guessing the code, end the game
    else if (*guessCode = "e" || *guessCode = "E") {
        return true;
    }
    // continue the game
    else {
        return false;
    }
}

// loop for player want to continue next game
void multiGameLoop(){
    // check is the multi game loop end
    *isMultiGameOver = false;
    *isMultiGameOver = checkMultiGameOver();
    // continue next game if player select
    while(!*isMultiGameOver){

    }
}

// function to check multi game is over
bool checkMultiGameOver() {
    // ask player want to start next game
    string playerInput = "";
    playerInput = askForString(" \n Do you want to start next game? (y/n): ");

    // break the loop until player enter [Y] or [N]
    while(playerInput != "y" || playerInput != "Y" || playerInput != "n" || playerInput != "N") {
        cout << "\n\n Please enter [Y] or [N] only.\n";
        playerInput = askForString(" \n Do you want to start next game? (y/n): ");
    }

    // return false if player want to continue next game
    if (playerInput == "y" || playerInput == "Y") {
        return false;
    }

    // return true if player don't want to continue next game
    else {
        return true;
    }
}

