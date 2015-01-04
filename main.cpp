#include <QApplication>
#include <QFontDatabase>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFontDatabase::addApplicationFont(":/fonts/Segoe Print.ttf");

    MainWindow w;
    w.show();

    return a.exec();
}
