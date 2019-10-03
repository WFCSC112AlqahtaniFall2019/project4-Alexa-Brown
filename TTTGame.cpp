/* Class: TicTacToe
 * Author: Alexa Brown
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
using namespace std;

int main() {
    TicTacToe variable; //to use to reach the class TicTacToe
    int row=0;
    int column=0;
    int numPlayers;
    char playAgain = 'y';
    //bool winnerYet;

    while(playAgain = 'y'){
    cout << " Welcome to TicTacToe! How many players would you like to play with? (1 or 2)"<< endl;
    cin >> numPlayers;

    if (numPlayers != 1 && numPlayers != 2){
        cout << "Please try again and enter either 1 or 2 players." <<endl;
        return 0;
    }

    //if number of players is 2 (one is not the computer)
    else if (numPlayers == 2) {
        cout << "Here is the playing board: " << endl;
        variable.printBoard();


       // while (!variable.isBoardFull()) {
            while (!variable.checkForWin()){//to cycle between players
                cout << "Player 1: you are 'x'" << endl;
                cout << "Enter row and column (0, 1, 2)" << endl;
                cin >> row;
                cin >> column;
                variable.placeMark(row, column);
                variable.printBoard();
                variable.changePlayer();
                variable.checkForWin();

                cout << "Player 2: you are 'o'" << endl;
                cout << "Enter row and column (0, 1, 2)" << endl;
                cin >> row;
                cin >> column;
                variable.placeMark(row, column);
                variable.printBoard();
                variable.changePlayer();
               // variable.isBoardFull();
                variable.checkForWin();
            }
            if (variable.checkForWin()) {
                variable.changePlayer(); //since we switch players at the end of the while loop, we must switch back for the winner
                cout << "You win Player " << variable.getCurrentPlayerNumber() << "!";
                cout << "Do you want to play again? Input y to play again or any other key to quit." << endl;
                cin >> playAgain;
            }

        }
    }


    // FINISH ME

    return 0;
}