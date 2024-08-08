#include <iostream>
using namespace std;

// declare and initialize ROWS and COLUMNS
const int ROWS = 3;
const int COLS = 3;

int main()
{
    // function prototypes
    void printboard(char[][COLS]);
    void maketurn(char[][COLS], bool);
    bool didend(char[][COLS], bool);
   
    // declare 3x3 array and bool variable
    char board[ROWS][COLS];
    bool isplayerone = true;

    // create array with * as placeholders
    // nested for loop to go through each column of each row
    for (int i = 0; i < ROWS; ++i) {
        for (int s = 0; s < COLS; ++s) {
            board[i][s] = '*';
        }
    }

    // print board before playing
    printboard(board);

    while(true) {
        maketurn(board, isplayerone);
        printboard(board);
        // break only when the game ends
        if (didend(board, isplayerone) == true) {
            break;
        }
        // alternate between players as game continues
        if (isplayerone == true) {
            isplayerone = false;
        }
        else {
            isplayerone = true;
        }
    }
   
    return 0;
}

// printboard function that prints 3x3 array onto screen between moves
void printboard(char gameboard[][COLS])
{
    for (int i = 0; i < ROWS; ++i) {
        for (int s = 0; s < COLS; ++s) {
            cout << gameboard[i][s];
        }
        cout << endl;
    }

    return;
}

// maketurn function that allows for players to make a move as long as it is in parameters of the board (3x3) and is currently occupied by an *
void maketurn(char gameboard[][COLS], bool playeroneturn) 
{
    int playerrow, playercol;
    while (true) {
        if (playeroneturn == true) {
            cout << "Enter a row and column to place an X"  << endl;
        }
        else {
            cout << "Enter a row and column to place an O" << endl;
        }

        cout << "Row: " << endl;
        cin >> playerrow;
        cout << "Column: " << endl;
        cin >> playercol;

        //conditions so no illegal moves can be made
        if ((playerrow >= 1) && (playerrow <= ROWS) && (playercol >= 1) && (playercol <= COLS) && (gameboard[playerrow-1][playercol-1] == '*')) {
            break;
        }
        else {
            cout << "That location is not available. Select another location." << endl;
        }

    }
    
    // subtract one from playerrow and playercol since arrays start from 0 not 1 
    if (playeroneturn == true) {
        gameboard[playerrow-1][playercol-1] = 'X';
    }
    else {
        gameboard[playerrow-1][playercol-1] = 'O';
    }

    return;
}

// didend function that ends game after win or tie
bool didend(char gameboard[][COLS], bool playeroneturn) 
{
    char symbol;
    bool win;
    if (playeroneturn == true) {
        symbol = 'X'; 
    }
    else {
        symbol = 'O';
    }

    // for loop representing a horizontal win
    for (int i = 0; i < ROWS; ++i) {
        bool win = true;
        for (int s = 0; s < COLS; ++s) {
            if (gameboard[i][s] != symbol) {
                win = false;
            }
        }
        if (win == true) {
            if (playeroneturn == true) {
                cout << "Player one won";
            }
            else {
                cout << "Player two won";
            }
            
            return true;
        }
    }

    // for loop representing a vertical win
    for (int i = 0; i < COLS; ++i) {
        bool win = true;
        for (int s = 0; s < ROWS; ++s) {
            if (gameboard[s][i] != symbol) {
                win = false;
            }
        }
        if (win == true) {
            if (playeroneturn == true) {
                cout << "Player one won";
            }
            else {
                cout << "Player two won";
            }
            
            return true;
        }
    }

    // for loop representing a diagonal win from [0][0] to [2][2]
    bool diagonalwin = true;
    for (int i = 0; i < ROWS; ++i) {
        if (gameboard[i][i] != symbol) {
            diagonalwin = false;
        }
    }
    if (diagonalwin == true) {
        if (playeroneturn == true) {
            cout << "Player one won";
        }
        else {
            cout << "Player two won";
        }
            
        return true;
    }

    // for loop representing opposite diagonal win from [2][0] to [0][2]
    diagonalwin = true;
    for (int i = ROWS-1; i >= 0; --i) {
        if (gameboard[i][COLS-i-1] != symbol) {
            diagonalwin = false;
        }
    }
    if (diagonalwin == true) {
        if (playeroneturn == true) {
            cout << "Player one won";
        }
        else {
            cout << "Player two won";
        }
            
        return true;
    }

    // tie game as a result of no more * on the board
    bool tie = true;
    for (int i = 0; i < ROWS; ++i) {
        for (int s = 0; s < COLS; ++s) {
            if (gameboard[i][s] == '*') {
                tie = false;
            }
        }
    } 
    if (tie == true) {
        cout << "Players tied" << endl;

        return true;
    }

    return false;
}