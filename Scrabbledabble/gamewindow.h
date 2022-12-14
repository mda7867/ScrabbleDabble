#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QVector2D>
#include "game.h"
#include <QTimer>
#include <QDialog>
#include "gameover.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private slots:
    void on_GenerateWord_clicked();
    void btnClicked();
    void clearWidgets(QLayout *layout);
    void on_GoButton_clicked();
    void updatedCountdown();
private:
    Ui::GameWindow *ui;
    Game game;
    int score = 0;
    QVector<QString> wordsFound;
    int i = 60;
    GameOver *gameOver;
    int getScore()
    {
        return this->score;
    }
};

#endif // GAMEWINDOW_H
