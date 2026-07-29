#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>
#include "WordDatabase.h"
using namespace std;

class Hangman {
private:
    string secretWord;
    string guessWord;
    vector <char> wrongGuesses;
    int maxAttempts;

public:
    Hangman(const string &word);

    void display() const;
    bool guessLetter(char s);
    bool isWon() const;
    bool isLost() const;

    void reset(const string& word);

    void play(WordDatabase &db);
};

#endif