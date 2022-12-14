#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "game.h"
#include <QString>
#include <QDialog>
#include<QVector>

namespace Ui {
class GameOver;
}

class GameOver : public QDialog
{
    Q_OBJECT

public:
    explicit GameOver(QWidget *parent = nullptr);
    ~GameOver();

private slots:
    void on_pushButton_clicked();
    void displayButtons();
    void on_pushButton_2_clicked();
    void clearWidgets(QLayout *layout);

private:
    Ui::GameOver *ui;
    QVector<QString> words;
};

#endif // GAMEOVER_H
