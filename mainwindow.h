#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "corkboard.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Corkboard* corkboard;
};

#endif // MAINWINDOW_H
