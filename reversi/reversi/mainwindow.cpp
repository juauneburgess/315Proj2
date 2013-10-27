#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include <QMessageBox>
#include <QtGui>

GameBoard board;
AI ai;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //GameBoard board;
    //AI ai;
    ui->setupUi(this);




    ui->btn00->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn01->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn02->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn03->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn04->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn05->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn06->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn07->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn10->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn11->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn12->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn13->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn14->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn15->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn16->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn17->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn20->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn21->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn22->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn23->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn24->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn25->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn26->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn27->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn30->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn31->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn32->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    /*ui->btn33->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn34->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");*/
    ui->btn35->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn36->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn37->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn40->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn41->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn42->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    /*ui->btn43->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn44->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");*/
    ui->btn45->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn46->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn47->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn50->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn51->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn52->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn53->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn54->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn55->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn56->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn57->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn60->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn61->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn62->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn63->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn64->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn65->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn66->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn67->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn70->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn71->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn72->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn73->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn74->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn75->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn76->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn77->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MaiWindow:: clearBoard(){}

void MainWindow::on_btnNewGame_clicked()
{
    /*QMessageBox MsgBox;
    MsgBox.setText("Hello World!");
    MsgBox.exec();*/


    /*ui->btn22->setStyleSheet("QPushButton{background:url(:/Resources/pause_nor.png);border:0px;}"
        "QPushButton:hover{background:url(:/Resources/pause_over.png);border:0px}"
        "QPushButton:pressed{background:url(:/Resources/pause_over.png); position: relative;top: 1px; left: 1px;}");*/

    //QPainter painter(this);
    //ui->lblBoard->setText("<img src =':/images/board.jpg'>");
    //painter.drawEllipse(QPointF(400,400), 10, 10);

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            board.setColor(i,j,'_');
        }
    }

    board.setColor(3,3,'O');
    board.setColor(3,4,'@');
    board.setColor(4,3,'@');
    board.setColor(4,4,'O');

    ui->btn00->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn01->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn02->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn03->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn04->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn05->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn06->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn07->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn10->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn11->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn12->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn13->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn14->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn15->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn16->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn17->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn20->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn21->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn22->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn23->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn24->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn25->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn26->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn27->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn30->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn31->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn32->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    /*ui->btn33->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn34->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");*/
    ui->btn35->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn36->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn37->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn40->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn41->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn42->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    /*ui->btn43->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn44->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");*/
    ui->btn45->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn46->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn47->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn50->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn51->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn52->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn53->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn54->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn55->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn56->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn57->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn60->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn61->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn62->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn63->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn64->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn65->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn66->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn67->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn70->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn71->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn72->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn73->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn74->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn75->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn76->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn77->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton) {
        QPoint p = event->pos();
        qDebug() << QString::number(p.x()) << "," << QString::number(p.x());

        //QPoint p1 = mapFromGlobal(QCursor::pos());

        //QMessageBox MsgBox;
        //MsgBox.setText(p.x()+"  "+p.y());
        //MsgBox.exec();
    }
}



void MainWindow::on_btn00_clicked()
{
    if(board.getColor(0,0) == '_' && board.curColor == '@'){
        board.move(0,0);
        ui->btn00->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,0) == '_' && board.curColor == 'O'){
        board.move(0,0);
        ui->btn00->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn01_clicked()
{
    if(board.getColor(0,1) == '_' && board.curColor == '@'){
        board.move(0,1);
        ui->btn01->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,1) == '_' && board.curColor == 'O'){
        board.move(0,1);
        ui->btn01->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn02_clicked()
{
    if(board.getColor(0,2) == '_' && board.curColor == '@'){
        board.move(0,2);
        ui->btn02->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,2) == '_' && board.curColor == 'O'){
        board.move(0,2);
        ui->btn02->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}



void MainWindow::on_btn03_clicked()
{
    if(board.getColor(0,3) == '_' && board.curColor == '@'){
        board.move(0,3);
        ui->btn03->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,3) == '_' && board.curColor == 'O'){
        board.move(0,3);
        ui->btn03->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn04_clicked()
{
    if(board.getColor(0,4) == '_' && board.curColor == '@'){
        board.move(0,4);
        ui->btn04->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,4) == '_' && board.curColor == 'O'){
        board.move(0,4);
        ui->btn04->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn05_clicked()
{
    if(board.getColor(0,5) == '_' && board.curColor == '@'){
        board.move(0,5);
        ui->btn05->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,5) == '_' && board.curColor == 'O'){
        board.move(0,5);
        ui->btn05->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn06_clicked()
{
    if(board.getColor(0,6) == '_' && board.curColor == '@'){
        board.move(0,6);
        ui->btn06->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,6) == '_' && board.curColor == 'O'){
        board.move(0,6);
        ui->btn06->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn07_clicked()
{
    if(board.getColor(0,7) == '_' && board.curColor == '@'){
        board.move(0,7);
        ui->btn07->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,7) == '_' && board.curColor == 'O'){
        board.move(0,7);
        ui->btn07->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}







void MainWindow::on_btn10_clicked()
{
    if(board.getColor(1,0) == '_' && board.curColor == '@'){
        board.move(1,0);
        ui->btn10->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,0) == '_' && board.curColor == 'O'){
        board.move(1,0);
        ui->btn10->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn11_clicked()
{
    if(board.getColor(1,1) == '_' && board.curColor == '@'){
        board.move(1,1);
        ui->btn11->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,1) == '_' && board.curColor == 'O'){
        board.move(1,1);
        ui->btn11->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn12_clicked()
{
    if(board.getColor(1,2) == '_' && board.curColor == '@'){
        board.move(1,2);
        ui->btn12->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,2) == '_' && board.curColor == 'O'){
        board.move(1,2);
        ui->btn12->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn13_clicked()
{
    if(board.getColor(1,3) == '_' && board.curColor == '@'){
        board.move(1,3);
        ui->btn13->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,3) == '_' && board.curColor == 'O'){
        board.move(1,3);
        ui->btn13->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn14_clicked()
{
    if(board.getColor(1,4) == '_' && board.curColor == '@'){
        board.move(1,4);
        ui->btn14->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,4) == '_' && board.curColor == 'O'){
        board.move(1,4);
        ui->btn14->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn15_clicked()
{
    if(board.getColor(1,5) == '_' && board.curColor == '@'){
        board.move(1,5);
        ui->btn15->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,5) == '_' && board.curColor == 'O'){
        board.move(1,5);
        ui->btn15->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn16_clicked()
{
    if(board.getColor(1,6) == '_' && board.curColor == '@'){
        board.move(1,6);
        ui->btn16->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,6) == '_' && board.curColor == 'O'){
        board.move(1,6);
        ui->btn16->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn17_clicked()
{
    if(board.getColor(1,7) == '_' && board.curColor == '@'){
        board.move(1,7);
        ui->btn17->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,7) == '_' && board.curColor == 'O'){
        board.move(1,7);
        ui->btn17->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn20_clicked()
{
    if(board.getColor(2,0) == '_' && board.curColor == '@'){
        board.move(2,0);
        ui->btn20->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,0) == '_' && board.curColor == 'O'){
        board.move(2,0);
        ui->btn20->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn21_clicked()
{
    if(board.getColor(2,1) == '_' && board.curColor == '@'){
        board.move(2,1);
        ui->btn21->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,1) == '_' && board.curColor == 'O'){
        board.move(2,1);
        ui->btn21->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn22_clicked()
{

    if(board.getColor(2,2) == '_' && board.curColor == '@'){
        board.move(2,2);
        ui->btn22->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,2) == '_' && board.curColor == 'O'){
        board.move(2,2);
        ui->btn22->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }

}
void MainWindow::on_btn23_clicked()
{
    if(board.getColor(2,3) == '_' && board.curColor == '@'){
        board.move(2,3);
        ui->btn23->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,3) == '_' && board.curColor == 'O'){
        board.move(2,3);
        ui->btn23->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn24_clicked()
{
    if(board.getColor(2,4) == '_' && board.curColor == '@'){
        board.move(2,4);
        ui->btn24->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,4) == '_' && board.curColor == 'O'){
        board.move(2,4);
        ui->btn24->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn25_clicked()
{
    if(board.getColor(2,5) == '_' && board.curColor == '@'){
        board.move(2,5);
        ui->btn25->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,5) == '_' && board.curColor == 'O'){
        board.move(2,5);
        ui->btn25->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn26_clicked()
{
    if(board.getColor(2,6) == '_' && board.curColor == '@'){
        board.move(2,6);
        ui->btn26->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,6) == '_' && board.curColor == 'O'){
        board.move(2,6);
        ui->btn26->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn27_clicked()
{
    if(board.getColor(2,7) == '_' && board.curColor == '@'){
        board.move(2,7);
        ui->btn27->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,7) == '_' && board.curColor == 'O'){
        board.move(2,7);
        ui->btn27->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn30_clicked()
{
    if(board.getColor(3,0) == '_' && board.curColor == '@'){
        board.move(3,0);
        ui->btn30->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,0) == '_' && board.curColor == 'O'){
        board.move(3,0);
        ui->btn30->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn31_clicked()
{
    if(board.getColor(3,1) == '_' && board.curColor == '@'){
        board.move(3,1);
        ui->btn31->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,1) == '_' && board.curColor == 'O'){
        board.move(3,1);
        ui->btn31->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn32_clicked()
{
    if(board.getColor(3,2) == '_' && board.curColor == '@'){
        board.move(3,2);
        ui->btn32->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,2) == '_' && board.curColor == 'O'){
        board.move(3,2);
        ui->btn32->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn35_clicked()
{
    if(board.getColor(3,5) == '_' && board.curColor == '@'){
        board.move(3,5);
        ui->btn35->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,5) == '_' && board.curColor == 'O'){
        board.move(3,5);
        ui->btn35->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn36_clicked()
{
    if(board.getColor(3,6) == '_' && board.curColor == '@'){
        board.move(3,6);
        ui->btn36->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,6) == '_' && board.curColor == 'O'){
        board.move(3,6);
        ui->btn36->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn37_clicked()
{
    if(board.getColor(3,7) == '_' && board.curColor == '@'){
        board.move(3,7);
        ui->btn37->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,7) == '_' && board.curColor == 'O'){
        board.move(3,7);
        ui->btn37->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
}

void MainWindow::on_btn40_clicked()
{

}

void MainWindow::on_btn41_clicked()
{

}

void MainWindow::on_btn42_clicked()
{

}

void MainWindow::on_btn45_clicked()
{

}

void MainWindow::on_btn46_clicked()
{

}

void MainWindow::on_btn47_clicked()
{

}

void MainWindow::on_btn50_clicked()
{

}

void MainWindow::on_btn51_clicked()
{

}

void MainWindow::on_btn52_clicked()
{

}

void MainWindow::on_btn53_clicked()
{

}

void MainWindow::on_btn54_clicked()
{

}

void MainWindow::on_btn55_clicked()
{

}

void MainWindow::on_btn56_clicked()
{

}

void MainWindow::on_btn57_clicked()
{

}

void MainWindow::on_btn60_clicked()
{

}

void MainWindow::on_btn61_clicked()
{

}

void MainWindow::on_btn62_clicked()
{

}

void MainWindow::on_btn63_clicked()
{

}

void MainWindow::on_btn64_clicked()
{

}

void MainWindow::on_btn65_clicked()
{

}

void MainWindow::on_btn66_clicked()
{

}

void MainWindow::on_btn67_clicked()
{

}

void MainWindow::on_btn70_clicked()
{

}

void MainWindow::on_btn71_clicked()
{

}

void MainWindow::on_btn72_clicked()
{

}

void MainWindow::on_btn73_clicked()
{

}

void MainWindow::on_btn74_clicked()
{

}

void MainWindow::on_btn75_clicked()
{

}

void MainWindow::on_btn76_clicked()
{

}

void MainWindow::on_btn77_clicked()
{

}
