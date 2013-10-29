#include "mainwindow.h"
#include <QApplication>
#include <QtDebug>
#include "gameboard.h"
#include "ai.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    vector<string> clicked;
    vector<string> chosen;
    w.showMaximized();
    w.connectTcp();
    string ret;
    string bret;

    qDebug() << "Size: " << w.choices.size();

    qDebug() << "size: " << clicked.size();
    /*for(int i = 0; i < w.choices.size(); i++)
    {
        QString r = w.choices[i].c_str();
        qDebug() << "choice: " << r;
    }
    for(int j = 0; j < w.clicks.size(); j++)
    {
        QString b = bret.c_str();
        qDebug() << "index: " << b;
    }*/
    return a.exec();
}
