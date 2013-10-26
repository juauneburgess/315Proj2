#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

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
    bool whitepressed();
    bool blackpressed();
    bool easypressed();
    bool mediumpressed();
    bool hardpressed();
    bool human_aipressed();
    bool ai_aipressed();
    bool ai1_easypressed();
    bool ai1_mediumpressed();
    bool ai1_hardpressed();
    bool ai2_easypressed();
    bool ai2_mediumpressed();
    bool ai2_hardpressed();

private:
    Ui::MainWindow *ui;
    QPushButton *white_play;
    QPushButton *black_play;
    QPushButton *easy;
    QPushButton *medium;
    QPushButton *hard;
    QPushButton *human_ai;
    QPushButton *ai_ai;
    QPushButton *ai1_easy;
    QPushButton *ai1_medium;
    QPushButton *ai1_hard;
    QPushButton *ai2_easy;
    QPushButton *ai2_medium;
    QPushButton *ai2_hard;
};

#endif // MAINWINDOW_H
