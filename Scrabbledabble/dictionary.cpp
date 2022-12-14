#include "dictionary.h"
void Dictionary ::getDict()
{
  string line;
  ifstream file;
  file.open("C:/Users/mda78/Documents/Scrabbledabble/dictionary.txt");
  if (!file)
    {
      throw 1;
    }
  int total_lines=0;
  while(getline(file,line))
    {
       total_lines++;
       this->lines.push_back(line);
    }
}
void Dictionary ::randSelect()
{
  int i = 0;
  srand(time(NULL));
  i  = rand()% 194431;
  this->sWord = lines.at(i);
}
void Dictionary ::stringSize()
{
  this->n = sWord.length();
}
void Dictionary ::stringtoChar()
{
  strcpy(this->word, this->sWord.c_str());
}
void Dictionary :: scramble ()
{
    unsigned seed = 0;
    random_shuffle(this->word, this->word + this->n);
}
void Dictionary :: print()
{
  for (int i = 0; i < n; ++i)
    {
      cout << this->word[i];
    }
}
int Dictionary ::getN()
{
  return this->n;
}
char Dictionary::getLetter(int i)
{
  return this->word[i];
}
string Dictionary:: getWord()
{
  return this->sWord;
}
