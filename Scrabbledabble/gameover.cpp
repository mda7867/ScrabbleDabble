#include "gameover.h"
#include "ui_gameover.h"
#include <QFile>
#include <QTextStream>
#include "mainwindow.h"
#include <QUrl>
#include<QDesktopServices>

GameOver::GameOver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);
    QFile file("C:/Users/mda78/Documents/Scrabbledabble/score.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        qCritical() <<"Could not OpenFile";
        qCritical()<< file.errorString();
    }
    file.seek(0);
    QTextStream stream(&file);
    QString score = stream.readAll();
    file.close();
    ui->FinalScore->setText(score);
    QFile wordFile("C:/Users/mda78/Documents/Scrabbledabble/WordsList.txt");
    if(!wordFile.open(QIODevice::ReadOnly))
    {
        qCritical() <<"Could not OpenFile";
        qCritical()<< file.errorString();
    }
    wordFile.seek(0);
    QTextStream stream_1(&wordFile);
    while (!stream_1.atEnd())
    {
        QString word;
        stream_1 >> word;
        if(stream_1.status() == QTextStream::Ok)
        {
             words.push_back(word);
        }
        else
         break;
    }
    wordFile.close();

}
GameOver::~GameOver()
{
    delete ui;
}

void GameOver::on_pushButton_clicked()
{
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}


void GameOver::on_pushButton_2_clicked()
{

    QHBoxLayout* layout = qobject_cast<QHBoxLayout*>(ui->horizontalLayout_3->layout());
    clearWidgets(layout);
    for(int i = 0; i < words.size();i++)
    {
        QString word = words.at(i);
        QPushButton* wordBut = new QPushButton;
        wordBut->setText(word);
        layout->insertWidget(0,wordBut);
        connect(wordBut,&QPushButton::clicked,this,&GameOver::displayButtons);
    }
}
void GameOver::displayButtons()
{
    QPushButton *wordBut = (QPushButton*)sender();
    QString word = wordBut->text();
    QDesktopServices::openUrl(QUrl("https://www.google.com/search?q=" + word + "+definition&sxsrf=ALiCzsbZrmBTE1iSYckgBRDVBgnsxXlScA%3A1670959689683&source=hp&ei=SdKYY5GwJ5PZ9APq25KgBQ&iflsig=AJiK0e8AAAAAY5jgWcjk-rW1bVX_zbJvg5W-yNgsvz5H&ved=0ahUKEwjR-PD1qff7AhWTLH0KHeqtBFQQ4dUDCAo&uact=5&oq=hi+definiiton&gs_lcp=Cgdnd3Mtd2l6EAMyDAgjELACECcQRhD5ATIHCAAQgAQQDTIHCAAQgAQQDTIHCAAQgAQQDTIHCAAQgAQQDTINCC4QgAQQxwEQrwEQDTIHCAAQgAQQDTIHCAAQgAQQDTIHCAAQgAQQDTIHCAAQgAQQDToHCCMQ6gIQJzoJCCMQJxBGEPkBOgQIIxAnOgUIABCRAjoRCC4QgAQQsQMQgwEQxwEQ0QM6CwgAEIAEELEDEIMBOgQILhBDOgsILhCDARCxAxCABDoICAAQsQMQgwE6DgguEIAEELEDEIMBENQCOgcIABCxAxBDOhAILhCABBCHAhDHARCvARAUOgQIABBDOgsILhCABBCxAxCDAToNCAAQgAQQsQMQgwEQCjoLCC4QgAQQxwEQrwE6CAguEIAEENQCOgUIABCABDoKCAAQgAQQhwIQFDoLCC4QrwEQxwEQgARQ5QlYwRdgvRhoAXAAeACAAbwBiAH4CpIBBDEuMTGYAQCgAQGwAQo&sclient=gws-wiz", QUrl::TolerantMode));
}
void GameOver:: clearWidgets(QLayout *layout)
{
    if (!layout)
        return;
    while(auto item = layout->takeAt(0))
    {
        delete item->widget();
        clearWidgets(item->layout());
    }
}

