#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QWidget>
#include <QList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); 
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    hide();
    gameWindow =new GameWindow(this);
    gameWindow->show();
}






void MainWindow::on_pushButton_2_clicked()
{
    MainWindow::~MainWindow();
}

