#include "game.h"

void Game :: input(QString Fword)
{
  string word = Fword.toStdString();
  this->Fword = word;
}
void Game ::startGame()
{
  try
    {
      dictionary.getDict();
    }
  catch(int hi)
    {
      cout << hi << ": Error opening file";
      exit(0);
    }
  dictionary.randSelect();
  dictionary.stringSize();
  dictionary.stringtoChar();
  dictionary.scramble();
  dictionary.print();
}
char Game ::getLetter(int i)
{
  return dictionary.getLetter(i);
}
int Game ::getN()
{
  return dictionary.getN();
}
string Game ::getWord()
{
  return dictionary.getWord();
}
string Game ::getScrambled()
{
    string scrambledWord;
    for(int i; i < getN(); i++)
    {
        getLetter(i);

    }
    return scrambledWord;
}
void Game ::addToScore(int i)
{
    this->score += i;
}
void Game :: setScore(int i)
{
    this->score = i;
}
int Game :: getScore()
{
    return  score;
}
bool Game::checkCorrect() {
  vector<string> lines;
  string search;
  string line;
  ifstream file;
  file.open("C:/Users/mda78/Documents/Scrabbledabble/dictionary.txt");
  if (!file)
  {
    throw 1;
  }
  int total_lines = 0;
  while (getline(file, line))
  {
    total_lines++;
    lines.push_back(line);
  }
  size_t mid, left = 0;
  size_t right = lines.size();
  while (left < right) {
    mid = left + (right - left) / 2;
    if (Fword > lines[mid]) {
      left = mid + 1;
    } else if (Fword < lines[mid]) {
      right = mid;
    }
    else
    {
      return true;
    }
  }
  return false;
}
void Game::setSWords(string word)
{
    sWords.push_back(word);
}
void Game ::scoreTofile(int score)
{
    {
      ofstream scoreFile;
      scoreFile.open ("C:/Users/mda78/Documents/Scrabbledabble/score.txt",std::ofstream::out | std::ofstream::trunc);
      if (!scoreFile)
      {
        throw 1;
      }
      scoreFile << score;
      scoreFile.close();
    }
}
void Game ::wordsToFile()
{
    ofstream wordFile;
    wordFile.open ("C:/Users/mda78/Documents/Scrabbledabble/WordsList.txt",std::ofstream::out | std::ofstream::trunc);
    if (!wordFile)
    {
      throw 1;
    }
    for (int i = 0; i < sWords.size();i++)
    {
        wordFile << this->sWords.at(i) << endl;
    }
    wordFile.close();
}
