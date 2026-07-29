#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "Hangman.h"
#include "WordDatabase.h"

using namespace std;

void Hangman::reset(const string &word) {
    secretWord = word;
    maxAttempts = 6;
    guessWord = string(secretWord.length(), '_');
    wrongGuesses.clear();
}
Hangman::Hangman (const string &word) {
    reset(word);
}

void Hangman::display() const {
    for(int i = 0; i < secretWord.length(); i++) {
        cout << guessWord[i] << " " ;
    }
    cout << "\nWrong guesses: ";
    for( int i = 0; i < wrongGuesses.size(); i++)
        cout << wrongGuesses.at(i) << " " ;

    cout << "\nAttempts left: " << maxAttempts << endl << endl;
}

bool Hangman::guessLetter(char s) {
    s = tolower(s);
    bool found = false;

    for(char c : guessWord)
        if (c == s) return false;
    
    for (char c : wrongGuesses)
        if (c == s) return false;

    for(int i = 0; i < guessWord.length(); i++) {
        if(s == secretWord[i]) {
            guessWord[i] = s;
            found = true;
        }
    }

    if(!found) {
        wrongGuesses.push_back(s);
        maxAttempts--;
    }

    return true;
}

bool Hangman::isWon() const {
    return guessWord == secretWord;
}

bool Hangman::isLost() const {
    return maxAttempts < 1;
}

void Hangman::play(WordDatabase &db) {
    char guess;
    char choice;

    do {
        reset(db.getRandomWord());

        while(!isWon() && !isLost()) {
            display();
            cout << "Enter a Letter: ";
            cin >> guess;
            guess = tolower(guess);

            if(!guessLetter(guess)) {
                cout << "Letter Already Used!\n\n";
                continue;
            }
        }

        display();

        if(isWon()) cout << "Game Won!\n\n";
        else        cout << "Game Lost!\n\nSecret Word was " << secretWord << endl << endl;

        cout << "Do you want to try again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

}

