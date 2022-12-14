#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "game.h"
GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)

{
    game.startGame();
    int score = 0;
    ui->setupUi(this);
    QTimer *time = new QTimer;
    connect(time,SIGNAL(timeout()),this,SLOT(updatedCountdown()));
    time->start(1000);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_GenerateWord_clicked()
{
    QHBoxLayout* layout = qobject_cast<QHBoxLayout*>(ui->horizontalLayout->layout());
    if (layout->count() != 0)
    {
        clearWidgets(layout);
        game.startGame();
    }
    for (int i = 0;i < game.getN(); i++)
    {
        QChar letter = game.getLetter(i);
        QPushButton* inputLetter = new QPushButton;
        inputLetter->setText(letter);
        layout->insertWidget(0,inputLetter);
        connect(inputLetter,&QPushButton::clicked,this,&GameWindow::btnClicked);
    }
    string word = game.getWord();
    game.setSWords(word);
}

void GameWindow :: btnClicked()
{
    QPushButton *inputLetter = (QPushButton*)sender();
    QString input = inputLetter->text();
    QString display = ui->DisplayWord->text();
    QString newVal = display + input;
    ui->DisplayWord->setText(newVal);
    delete inputLetter;
}


void GameWindow:: clearWidgets(QLayout *layout)
{
    if (!layout)
        return;
    while(auto item = layout->takeAt(0))
    {
        delete item->widget();
        clearWidgets(item->layout());
    }
    ui->DisplayWord->setText("");
}

void GameWindow::on_GoButton_clicked()
{
    QString input = ui->DisplayWord->text();
    game.input(input);
    bool found = false;
    for(int i = 0; i < wordsFound.size();i++)
    {
        if(input == wordsFound.at(i))
        {
            found = true;
        }
    }
    if (game.checkCorrect()&& found == false)
    {
        score+= 5;
        game.setScore(score);
        QString num = QString :: number(score);
        ui->score_int->setText(num);
        wordsFound.push_back(input);
        ui->Score->setText("Correct!");
    }
    else
    {
        if(found == true)
        {
            ui->Score->setText("You already got this word");
        }
        else
        {
            ui->Score->setText("Incorrect Word");
        }
    }

    QHBoxLayout* layout = qobject_cast<QHBoxLayout*>(ui->horizontalLayout->layout());
    clearWidgets(layout);
    for (int i = 0;i < game.getN(); i++)
    {
        QChar letter = game.getLetter(i);
        QPushButton* inputLetter = new QPushButton;
        inputLetter->setText(letter);
        layout->insertWidget(0,inputLetter);
        connect(inputLetter,&QPushButton::clicked,this,&GameWindow::btnClicked);
    }
}

void GameWindow::updatedCountdown()
{
    this->i -= 1;
    QString s = QString :: number(i);
    ui->Timer->setText(s);
   if (i == 0)
    {
        game.scoreTofile(score);
        game.wordsToFile();
        hide();
        gameOver = new GameOver(this);
        gameOver->show();
    }
}
