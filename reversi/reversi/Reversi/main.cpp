#include "mainwindow.h"
#include <QApplication>
#include "gameboard.h"
#include "ai.h"

//GameBoard board;
//AI ai;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
	w.connectTcp();



    return a.exec();
}
