/* Class: TicTacToe
* Author: Alexa Brown
* Description: A program that implements the game Tic-Tac-Toe
*/

#include <iostream>
#include "TicTacToe.h"
#include <time.h>
#include <cstdlib>

using namespace std;

int main() {
int row=0;
int column=0;
int numPlayers;
char playAgain = 'y';


while(playAgain != 'q') {
    TicTacToe variable;//to use to reach the class TicTacToe
variable.initializeBoard(); //to reset the board if the player wants to play again
cout << " Welcome to TicTacToe! How many players would you like to play with? (1 or 2)" << endl;
    cin >> numPlayers;


if (numPlayers != 1 && numPlayers != 2) { //if they don't enter 1 or 2
    cout << "Please try again and enter either 1 or 2 players." << endl;
    return 0;
}

    //if number of players is 2 (two users)
else if (numPlayers == 2) {
    cout << "Here is the playing board: " << endl;
    variable.printBoard();
    if (variable.isBoardFull()) {
        cout << "There was a tie!" << endl;
        break;
    }

    while (!variable.checkForWin()) {//to cycle between players
        cout << "Player 1: you are 'x'" << endl;
        cout << "Enter row and column (1, 2, or 3)" << endl;
        cin >> row ;
        row--;
        cin >> column ;
        column--;
        if (!variable.placeMark(row, column)) { //if the numbers have already been chosen or if it is not an option
            cout << "Please pick a row and column number that are within the bounds. Pick 1, 2, or 3." << endl;
            cin >> row;
            cin >> column;
            row--;
            column--;
        }
        variable.placeMark(row, column);
        variable.printBoard();
        variable.changePlayer();
        if (variable.checkForWin() || variable.isBoardFull()) {
            break;
        }

        cout << "Player 2: you are 'o'" << endl;
        cout << "Enter row and column (1, 2, or 3)" << endl;
        cin >> row;
        cin >> column;
        row--;
        column--;
        if (!variable.placeMark(row, column)) {
            cout<< "Please pick a row and column number that are within the bounds or that has not yet been chosen. Pick 1, 2, or 3."<< endl;
            cin >> row;
            cin >> column;
            row--;
            column--;
        }

        variable.placeMark(row, column);
        variable.printBoard();
        variable.changePlayer();
}
    if (variable.checkForWin()) {
        variable.changePlayer(); //since we switch players at the end of the while loop, we must switch back for the winner
        cout << "Player " << variable.getCurrentPlayerNumber() << " wins!" << endl;
        cout << "Do you want to play again? Input 'y' to play again or 'q' to quit." << endl;
        cin >> playAgain;
        variable.changePlayer();
    }
    if (variable.isBoardFull() && !variable.checkForWin()){
        cout << "There is a tie!" << endl;
        cout << "Do you want to play again? Input 'y' to play again or 'q' to quit." << endl;
        variable.changePlayer();
        cin >> playAgain;
    }
}//end of if players = 2


    //one user is a player and the computer is a player
else if (numPlayers == 1) {
    TicTacToe variable;//to use to reach the class TicTacToe
    cout << endl;
    cout << "User, you are player 1 and the computer is player 2." << endl;
    cout << endl;
    cout << "Here is the playing board: " << endl;
    variable.printBoard();

    while (!variable.checkForWin()) {//to cycle between players
        cout << "Player 1's turn: you are 'x'" << endl;
        cout << "Enter row and column (1, 2, or 3)" << endl;
        cin >> row;
        cin >> column;
        row--;
        column--;
        while(!variable.placeMark(row, column)){
            cout<< "Please pick a row and column number that are within the bounds or that has not yet been chosen. Pick 1, 2, or 3."<< endl;
            cin >> row;
            cin >> column;
            row--;
            column--;
        }
        variable.placeMark(row, column);
        variable.printBoard();
        variable.changePlayer();
        if (variable.checkForWin()) {
            break;
        }


        srand (time(nullptr));

        //need to figure out how to get the computer to know if there is already something in that spot
        cout << "Player 2's turn: you are 'o'" << endl;
        row = rand()% 2 ;
        column = rand()% 2  ;
        cout << row << " " << column << endl;
        while(!variable.placeMark(row, column) && !variable.isBoardFull()){
            row = rand()% 3 + 1 ;
            column = rand()% 3 + 1 ;
        }
        variable.placeMark(row, column);
        cout << row << " " << column;

        variable.printBoard();
        variable.changePlayer();
    }
    if (variable.checkForWin()) {
        variable.changePlayer(); //since we switch players at the end of the while loop, we must switch back for the winner
        cout << "Player " << variable.getCurrentPlayerNumber() << " wins!" << endl;
        cout << "Do you want to play again? Input 'y' to play again or 'q' to quit." << endl;
        variable.changePlayer();
        cin >> playAgain;
    }
    if (variable.isBoardFull() && !variable.checkForWin()){
        cout << "There is a tie!" << endl;
        cout << "Do you want to play again? Input 'y' to play again or 'q' to quit." << endl;
        cin >> playAgain;
    }

    } //end of if players = 1
} //while loop allows the game to go on as long as the user wants it to go on, finishes when they input 'q' when prompted

cout << "Thank you for playing!" << endl;



return 0; //end of main function
}