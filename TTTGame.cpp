/* Class: TicTacToe
 * Author: Alexa Brown
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
#include <time.h>

using namespace std;

int main() {
    TicTacToe variable; //to use to reach the class TicTacToe
    int row=0;
    int column=0;
    int numPlayers;
    char playAgain = 'y';
    //bool winnerYet;

    while(playAgain != 'q') {

        variable.initializeBoard(); //to reset the board if the player wants to play again
        cout << " Welcome to TicTacToe! How many players would you like to play with? (1 or 2)" << endl;
        cin >> numPlayers;


        if (numPlayers != 1 && numPlayers != 2) {
            cout << "Please try again and enter either 1 or 2 players." << endl;
            return 0;
        }

            //if number of players is 2 (two users)
        else if (numPlayers == 2) {
            cout << "Here is the playing board: " << endl;
            variable.printBoard();


            while (!variable.checkForWin()) {//to cycle between players
                cout << "Player 1: you are 'x'" << endl;
                cout << "Enter row and column (0, 1, 2)" << endl;
                cin >> row;
                cin >> column;
                variable.placeMark(row, column);
                variable.printBoard();
                variable.changePlayer();
                // variable.checkForWin();
                if (variable.checkForWin()) {
                    break;
                }

                cout << "Player 2: you are 'o'" << endl;
                cout << "Enter row and column (0, 1, 2)" << endl;
                cin >> row;
                cin >> column;
                variable.placeMark(row, column);
                variable.printBoard();
                variable.changePlayer();
                if (variable.isBoardFull())
                    break;
            }
            if (variable.checkForWin()) {
                break;
            }
            if (variable.checkForWin()) {
                variable.changePlayer(); //since we switch players at the end of the while loop, we must switch back for the winner
                cout << "You win Player " << variable.getCurrentPlayerNumber() << "!" << endl;
                cout << "Do you want to play again? Input 'y' to play again or 'q' to quit." << endl;
                cin >> playAgain;
            }
        }//end of if players = 2


            //one user is a player and the computer is a player
        else if (numPlayers == 1) {
            cout << "Here is the playing board: " << endl;
            variable.printBoard();

            while (!variable.checkForWin()) {//to cycle between players
                cout << "User's turn: you are 'x'" << endl;
                cout << "Enter row and column (0, 1, 2)" << endl;
                cin >> row;
                cin >> column;
                variable.placeMark(row, column);
                variable.printBoard();
                variable.changePlayer();
                // variable.checkForWin();
                if (variable.checkForWin()) {
                    break;
                }

                srand (time(NULL));

                cout << "Computer's turn: you are 'o'" << endl;
                row = rand()% 2 + 1;
                column = rand()% 2 + 1;
                variable.placeMark(row, column);
                variable.printBoard();
                variable.changePlayer();
                if (variable.isBoardFull())
                    break;
            }
            if (variable.checkForWin()) {
                break;
            }
            if (variable.checkForWin()) {
                variable.changePlayer(); //since we switch players at the end of the while loop, we must switch back for the winner
                cout << "You win Player " << variable.getCurrentPlayerNumber() << "!" << endl;
                cout << "Do you want to play again? Input 'y' to play again or 'q' to quit." << endl;
                cin >> playAgain;
            }
        } //end of if players = 1
    }






    // FINISH ME

    return 0;
}