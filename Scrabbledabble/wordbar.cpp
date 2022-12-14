#include "wordbar.h"
void wordBar::createNewButton(Game game)
{
    for (int i = 0;i< game.getN(); i++)
    {
        QChar letter = game.getLetter(i);
        QPushButton *inputLetter= new QPushButton();
        inputLetter->setText(letter);
        connect(inputLetter, SIGNAL(clicked()), this, SLOT(btnClicked()));
    }
}
