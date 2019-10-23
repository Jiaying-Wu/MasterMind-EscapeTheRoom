/*****************************************************************************
Project: Master Mind - Escape the Room
Author: Jiaying Wu
Purpose: Application file, to hold the main() function and controls the overall
 flow of the game.
******************************************************************************/

// header
#include "GeneralFunction.h"
#include "masterMindAchievement.h"
#include "Code.h"
#include "MasterMind.h"


// main function
int main(){
    // display Main page
    displayMainPage(currentOption);
    // user select [S] or [C]
    gameLoop();
    // user select [E], pause and wait for exit
    system("pause");
    return 0;
}

// loop to display the Main page, if player didn't enter [N], [C] or [E], it will return to main page.
void displayMainPage(string currentOption) {
    // display the main page
    while (isMainPageOver) {
        // clear the screen and display Main page.
        system("cls");
        readFile("masterMindMainPage.txt");

        // break the while loop until enter [N], [C], [H], [A], [E] in Main page
        currentOption = askForString("\n Enter your option: ");
        while (currentOption != "h" || currentOption != "H" ||
               currentOption != "a" || currentOption != "a" ||
               currentOption != "n" || currentOption != "N" ||
               currentOption != "c" || currentOption != "C" ||
               currentOption != "e" || currentOption != "E") {
            cout << "\n Please enter the option displayed on the screen only.\n\n";
            currentOption = askForString("\n Enter your option: ");
        }

        // user select [H] display Help page, then back to Help page.
        if (currentOption == "h" || currentOption == "H") {
            // clear the screen to display Help page.
            system("cls");
            readFile("masterMindHelpPage.txt");
            // pause the screen to allow player read the information
            system("pause");
        }

        // user select [A] view the Achievements page.
        else if (currentOption == "h" || currentOption == "H") {
            // clear the screen to display Achievements page.
            system("cls");
            readFile("masterMindAchievementPage.txt");
            // pause the screen to allow player read the information
            system("pause");
        }

        // break the while loop when [C], [N], [E] selected.
        else {
            isMainPageOver = true;
        }
    }
}

// start the game when select [S] or [C]
void gameLoop() {

    // user select [N] New game.
    if (currentOption == "n" || currentOption == "N"){
        // clear the screen to display Achievements page.
        system("cls");
        readFile("masterMindSetUpPage.txt");
        // ask player
        system("pause");
    }

    // user select [C] Continue the saved game.
    else if (currentOption == "c" || currentOption == "C") {
        gameLoop();
    }
}


bool checkGameOver(){

}
