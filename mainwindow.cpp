#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    corkboardScene(new CorkboardScene(this))
{
    ui->setupUi(this);
    ui->corkboard->setScene(corkboardScene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
