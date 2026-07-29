#include <iostream>
#include "Game.h"
using namespace std;

Game::Game() {
    reset();
}

void Game::reset() {
    currentPlayer = 'X';
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void Game::displayBoard() const {
    cout << endl;
    for(int i = 0; i < 3; i++) {
        cout << " ";
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];
            if(j < 2)   cout << " | ";
        }

        cout << endl;
       if(i < 2)    cout << "---+---+---\n";
    }
    cout << endl;
}

bool Game::makeMove(int row, int col) {
    if(row < 0 || row > 2 || col < 0 || col > 2)    return false;
    if(board[row][col] != ' ')  return false;

    board[row][col] = currentPlayer;
    return true;
}

bool Game::checkWin(char p) const {
    for(int pat = 0; pat < 8; pat++) {
        bool win = true;

        for(int i = 0; i < 3; i++) {
            int r = winPatterns[pat][i][0];
            int c = winPatterns[pat][i][1];

            if(board[r][c] != p) {
                win = false;
                break;
            }
        }
        if(win) return true;
    }
    return false;
}

bool Game::isDraw() const {
    for(int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if(board[i][j] == ' ')  return false;

    return true;
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void Game::play() {
    int row, col;
    char choice;

    while(true) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter row and column (0-2): " ;
        cin >> row >> col;

        if(!makeMove(row,col)) {
            cout << "Invalid move. Try again!\n";
            continue;
        }

        if(checkWin(currentPlayer)) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
        } else if(isDraw()) {
            displayBoard();
            cout << "Game drawed.\n";
        } else {
            switchPlayer();
            continue;
        }

        cout << "Play Again? (y-n)\n";
        cin >> choice;

        if(choice == 'y' || choice == 'Y')  reset();
        else    break;
    }
}