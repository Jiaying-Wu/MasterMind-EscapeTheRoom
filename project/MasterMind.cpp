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
            askForInteger("\n Please select the element type (1 - 4): "),
            "Beginner"
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
        displayTable(*totalGuessCode, *currentGameRound, code.getCodeColumn());

        // ask for guess code
        *guessCode = askForGuessCode(*possibleElementSet);
        *totalGuessCode = storeTotalGuessCode(*secretCode);

        // check is game over, and provide feedback if finish all game rounds or guess the correct code
        *currentGameRound = *currentGameRound + 1;
        *isOneGameOver = checkOneGameOver(*currentGameRound, *totalGameRound, *secretCode, *guessCode, );
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
        myVector = {"Apple", "Boy", "Cat", "Dog", "Fish", "Grape", "Insect", "July", "Kiwi", "Lemon"};
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

// function to display the title of game page
void displayTitle() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\tMasterMind :: Escape the Room\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Welcome, " << player.getPlayerName() << "\n";
    cout << "\n [H] Help    [N] New game    [E] End game\n";
    cout << endl;
}

// display all guess code and hints
void displayTable(vector<string> allGuessCode, int currentRound, int column){
    // when game round is 0
    stringstream sBox;
    // 2 space for each
    string boxUpper = "\n .";
    string boxTop = "\n |";
    string boxMid = "\n |";
    string boxBot = "\n |";
    string boxLower = "\n '";
    // 6 space for each box
    for (int i = 0; i < column; ++i) {
        boxUpper += "~~~~~~";
        boxTop += " .---.";
        boxMid += " |   |";
        boxBot += " '---'";
        boxLower += "~~~~~~";
    }
    // 16 spaces for each
    boxUpper += "~~~~~~~~~~~~~~~.";
    boxTop += "               |";
    boxMid += "  Hidden Code  |";
    boxBot += "               |";
    boxLower += "~~~~~~~~~~~~~~~'";
    // Print the title of the table
    sBox << boxUpper << boxTop << boxMid << boxBot << boxLower;
    cout << sBox.str();

    // when game round larger than 0
    if(currentRound > 0){
        // loop for each layer
        for (int j = 0; j < currentRound+1; ++j) {
            stringstream sLayer;
            // 2 space for each
            string layerTop = "\n |";
            string layerMid = "\n |";
            string layerBot = "\n |";
            // 6 space for each box
            for (int i = 0; i < column; ++i) {
                boxTop += " .---.";
                boxMid = boxMid + " | " + allGuessCode[i+column*currentRound][0] + " |";
                boxBot += " '---'";
            }
            // 16 spaces for each
            layerTop += "               |";
            // 2 space + codeColumn + (16 - 2 - 1 - codeColumn) + 1space
            vector<string> myVector(allGuessCode.begin()+j*column, allGuessCode.begin()+(j+1)*column-1);
            layerMid += "  " + generateHint(*guessCode, myVector) + string(13-code.getCodeColumn(), ' ') + "|";
            layerBot += "               |";
            // Print one layer of the table
            sLayer << layerTop << layerMid << layerBot;
            cout << sLayer.str();
        }
        // lowest bound of the table
        cout << "'~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~'";
    }

    // finish printing
    cout << endl;
}

// generate the hint "#", "*", " " to insert in the layer
string generateHint(vector<string> guess, vector<string> secret) {
    string correctPosition;
    string correctElement;
    string spaceString;

    for (int i = 0; i < secret.size(); ++i) {
        // correct position, "#"
        if (guess[i] == guess[i]){
            correctPosition += "#";
        }
        // correct element, "*"
        else if (guess[i] != secret[i] && find(secret.begin(), secret.end(), guess[i]) != secret.end()) {
            correctElement += "*";
        }
        // both wrong, " "
        else {
            spaceString += " ";
        }
    }

    // combine # , * and space
    string combString;
    combString = correctPosition + correctElement + spaceString;

    return combString;
}


// function to check one game is over, and provide feedback if game completed
bool checkOneGameOver(int currentRound, int totalRound, vector<string> secret, vector<string> guess, int win, int lost) {
    // finish all game rounds or guess the correct code, provide feedback
    if (currentRound == totalRound || secret == guess) {
        if (secret == guess) {
            win++;
        }
        else {
            lost++;
        }
        // provide feed back
        feedBack(player.getPlayerName(), player.getRank(), win, lost,  ,code.getMaxPoint(player.getSelectGate()));
        // return true
        return true;
        // pause the screen to allow user read the feedback
        system("pause");
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

void feedBack(string name, string rank, int win, int lost, int gamePoint, int maxPoint) {
    cout << "\n\n      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "              Name: " << name << "\n";
    cout << "              Rank: " <<  rank << "\n";
    cout << "              Win Games: " << win << "\n";
    cout << "              Lost Games: " << lost << "\n";
    cout << "              Point in this game: " <<  gamePoint << " / " << maxPoint << "\n";
    cout << "      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
