#include "dictionary.h"
#include <QString>
#ifndef GAME_H
#define GAME_H

class Game
{
  private:
    Dictionary dictionary;
    string Fword;
    int score = 0;
    vector<string> dictWords;
    vector<string> sWords;
  public:
    void input(QString Fword);
    void startGame();
    char getLetter(int i);
    int getN();
    string getWord();
    string getScrambled();
    void addToScore(int i);
    void setScore(int i);
    int getScore();
    bool checkCorrect();
    void setSWords(string word);
    string getSWords(int i)
    {
        string currWord=this->sWords.at(i);
        return currWord;
    }
    void scoreTofile(int score);
    void wordsToFile();

};
#endif
