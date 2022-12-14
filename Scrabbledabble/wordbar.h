#ifndef WORDBAR_H
#define WORDBAR_H
#include "game.h"
#include "qpushbutton.h"

class wordBar : public QPushButton
{
public:
    wordBar();
    void createNewButton(Game game);
};

#endif // WORDBAR_H
