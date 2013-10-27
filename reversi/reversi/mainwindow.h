#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_btnNewGame_clicked();
    void mousePressEvent(QMouseEvent *event);

    void on_btn22_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
