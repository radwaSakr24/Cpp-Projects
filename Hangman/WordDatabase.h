#ifndef WORDDATABASE_H
#define WORDDATABASE_H

#include <string>
#include <vector>


class WordDatabase {
private:
    std::vector <std::string> words;

public:
    WordDatabase();
    std::string getRandomWord() const;
};

#endif