/*****************************************************************************
Project: Master Mind - Escape the Room
Author: Jiaying Wu
Purpose: Application file, to hold the main() function and controls the overall
 flow of the game.
 * loop for Main page
 * loop for each round of one game
 * loop for each game of multi game
 * compare guess code and secret code, display output table
 * feedback when one game finish
******************************************************************************/

// header
#include "MasterMind.h"

// main function
int main(){
    // display Main page, break the loop if select [N] or [E]
    displayMainPage();
    // user select [N]
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
    }
    else {
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
    }
    else {
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

        // keep asking string input until enter [N], [H], [E] in Main page
        while (userInput != "n" || userInput != "N" || userInput != "h" || userInput != "H" || userInput != "e" || userInput != "E") {
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

        // break the while loop when [N], [E] selected.
        else {
            *isMainPageOver = true;
        }
    }
}

// loop for each game of multi game
void multiGameLoop(){
    setFirstGame();
    *isMultiGameOver = false;
    // loop for multi games
    while(!*isMultiGameOver){
        // start one game
        oneGameLoop();
        // check is the multi game loop end
        *isMultiGameOver = checkMultiGameOver();
    }
}

// set the first game environment
void setFirstGame() {
    // construct Player class
    player = Player(
            askForString("\n Please enter your name: "),
            // selectGate, 1 to 3
            askForInteger("\n Please select the gate (1 - 3): "),
            // selectElementType, 1 to 4
            askForInteger("\n Please select the element type (1 - 4): ")
    );

    // Construct Code Class
    code = Code(
            // codeColumn = 3 + selectGate
            player.getSelectGate() + 3,
            // codeRow = 8 + 2 * selectGate
            player.getSelectGate() * 2 + 8,
            // numberPossibleElement = 4 + 2 * selectGate
            player.getSelectGate() * 2 + 4
    );
}

// function to check multi game is over
bool checkMultiGameOver() {
    // ask player want to start next game
    string playerInput;
    playerInput = askForString(" \n Do you want to start next game? (y/n): ");

    // break the loop until player enter [Y] or [N]
    while(playerInput != "y" || playerInput != "Y" || playerInput != "n" || playerInput != "N") {
        string playerInput = "";
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

// loop for each round of one game
void oneGameLoop() {
    *isOneGameOver = false;
    // seed random
    srand(unsigned(time(NULL)));

    // generate the possible element set
    *possibleElementSet = generatePossibleElementSet(player.getSelectElementType(), code.getNumberPossibleElement());

    // generate the secret code
    *secretCode = generateSecretCode(*possibleElementSet, code.getCodeColumn());

    // initiate total guess code vector
    totalGuessCode->clear();

    // determine the current and total game rounds
    *totalGameRound = code.getCodeRow();
    *currentGameRound = 0;

    // loop for multi rounds of one game
    while(!isOneGameOver) {
        // clear the screen and display title
        system("cls");
        displayTitle();

        // display the previous result
        displayTable();

        // ask for guess code
        *guessCode = askForGuessCode(*possibleElementSet);
        *totalGuessCode = storeTotalGuessCode(*secretCode);

        // check is game over
        *currentGameRound ++;
        *isOneGameOver = checkOneGameOver(*currentGameRound, *totalGameRound, *secretCode, *guessCode);
        feedBack();
    }
}

// generate the possible element set base on the selected gate and element type
vector<string> generatePossibleElementSet(int type, int keepElement) {
    vector<string> myVector;

    // Number
    if (type == 1){
        myVector = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    }

    // Letter
    else if (type == 2){
        myVector = {"a", "b", "c", "d", "f", "g", "i", "j", "k", "l"};
    }
    // Symbol
    else if (type == 3){
        myVector = {"`", "~", "!", "@", "+", "$", "%", "^", "&", "?"};

    }

    // Word
    else if (type == 4){
        myVector = {"apple", "pear", "melon", "mango", "banana", "berry", "lemon", "grape", "orange", "kiwi"};
    }

    // return the vector of possible vector
    myVector.erase(myVector.begin()+keepElement, myVector.end());
    return myVector;
}

// generate the secrete code base on the element set and code column
vector<string> generateSecretCode(vector<string> elementSet, int codeColumn){
    vector<string> myVector;
    for (int i = 0; i < codeColumn; ++i) {
        int randomIndex = rand() % elementSet.size();;
        myVector.push_back(elementSet[randomIndex]);
    }
    return myVector;
}

// print the possible element set and ask player for guess code
vector<string> askForGuessCode(vector<string> possibleElement){
    // print the possible element
    cout << "\n The code elements: ";
    for (int i = 0; i < possibleElement.size(); ++i) {
        cout << possibleElement[i] << " ";
    }
    cout << endl;

    // get input and store as vector
    string input;
    vector<string> myVector;
    cout << "\n\n Enter the game option or code separated by space: ";
    while (cin >> input) {
        myVector.push_back(input);
    }

    return myVector;
}

// store one round guess code to the total rounds of guess code
vector<string> storeTotalGuessCode(vector<string> storeCode){
    vector<string> myVector;
    for (int i = 0; i < storeCode.size(); ++i) {
        myVector.push_back(storeCode[i]);
    }
    return myVector;
}


void displayTable(){

}

void feedBack(){

}



// function to check one game is over
bool checkOneGameOver(int currentRound, int totalRound, vector<string> secret, vector<string> guess) {
    // finish all game rounds
    if (currentRound == totalRound) {
        return true;
    }

    // the guess code match the secret code
    else if (secret == guess){
        return true;
    }

    // player enter [E] when guessing the code, end the game
    else if (guess.at(0) == "e" || guess.at(0) == "E") {
        return true;
    }

    // continue the game
    else {
        return false;
    }
}


