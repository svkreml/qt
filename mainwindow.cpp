#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    corkboard(new Corkboard(new CorkboardScene, this))
{
    setWindowTitle("Corkboard");
    setMinimumSize(640, 400);
    resize(960, 600);
    setCentralWidget(corkboard);
}

MainWindow::~MainWindow()
{
}
