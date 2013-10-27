#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gameboard.h"
#include "ai.h"

//extern GameBoard board;
//extern AI ai;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //void clearBoard();
    void on_btnNewGame_clicked();
    void mousePressEvent(QMouseEvent *event);

    void on_btn22_clicked();

    void on_btn00_clicked();

    void on_btn01_clicked();

    void on_btn02_clicked();

    void on_btn03_clicked();

    void on_btn04_clicked();

    void on_btn05_clicked();

    void on_btn06_clicked();

    void on_btn07_clicked();

    void on_btn30_clicked();

    void on_btn31_clicked();

    void on_btn32_clicked();

    void on_btn35_clicked();

    void on_btn36_clicked();

    void on_btn37_clicked();

    void on_btn10_clicked();

    void on_btn11_clicked();

    void on_btn12_clicked();

    void on_btn13_clicked();

    void on_btn14_clicked();

    void on_btn15_clicked();

    void on_btn16_clicked();

    void on_btn17_clicked();

    void on_btn20_clicked();

    void on_btn21_clicked();

    void on_btn23_clicked();

    void on_btn24_clicked();

    void on_btn25_clicked();

    void on_btn26_clicked();

    void on_btn27_clicked();

    void on_btn40_clicked();

    void on_btn41_clicked();

    void on_btn42_clicked();

    void on_btn45_clicked();

    void on_btn46_clicked();

    void on_btn47_clicked();

    void on_btn50_clicked();

    void on_btn51_clicked();

    void on_btn52_clicked();

    void on_btn53_clicked();

    void on_btn54_clicked();

    void on_btn55_clicked();

    void on_btn56_clicked();

    void on_btn57_clicked();

    void on_btn60_clicked();

    void on_btn61_clicked();

    void on_btn62_clicked();

    void on_btn63_clicked();

    void on_btn64_clicked();

    void on_btn65_clicked();

    void on_btn66_clicked();

    void on_btn67_clicked();

    void on_btn70_clicked();

    void on_btn71_clicked();

    void on_btn72_clicked();

    void on_btn73_clicked();

    void on_btn74_clicked();

    void on_btn75_clicked();

    void on_btn76_clicked();

    void on_btn77_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
