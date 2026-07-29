#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Hangman.h"
#include "WordDatabase.h"
using namespace std;

int main()
{
    srand(time(nullptr));

    WordDatabase db;
    Hangman game(db.getRandomWord());

    game.play(db);

    return 0;
}