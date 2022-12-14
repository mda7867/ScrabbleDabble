#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
#ifndef DICTIONARY_H
#define DICTIONARY_H

class Dictionary
{
  private:
    string sWord;
    vector<string> lines;
    int n;
    char word[100];
  public:
    int getN();
    void getDict();
    void randSelect();
    void stringSize();
    void stringtoChar();
    void scramble ();
    void print();
    char getLetter(int i);
    string getWord();
};
#endif
