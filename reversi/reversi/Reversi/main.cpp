#include "mainwindow.h"
#include <QApplication>
#include "gameboard.h"
#include "ai.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.connectTcp();
    w.get_choice();
    w.get_click();
    w.showMaximized();


    return a.exec();
}
