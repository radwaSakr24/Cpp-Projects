#ifndef GAME_H
#define GAME_H

class Game {
private:
    char board[3][3];
    char currentPlayer;

    const int winPatterns [8][3][2] = {
        {{0,0},{0,1},{0,2}}, {{1,0},{1,1},{1,2}}, {{2,0},{2,1},{2,2}},
        {{0,0},{1,0},{2,0}}, {{0,1},{1,1},{2,1}}, {{0,2},{1,2},{2,2}},
        {{0,0},{1,1},{2,2}}, {{0,2},{1,1},{2,0}}
    };

public:
    Game();
    void displayBoard() const;
    bool makeMove(int row, int col);
    bool checkWin(char p) const;
    bool isDraw() const;
    void switchPlayer();
    void play();
    void reset();
};

#endif