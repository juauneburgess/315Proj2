#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include <QMessageBox>
#include <QtGui>
#include <QTcpSocket>

GameBoard board;
AI ai;
QTcpSocket * _pSocket;

void MainWindow :: updateBoard(){
    // update current player color

    if(board.curColor == '@'){
        ui->lblCurrPlayer->setStyleSheet("background-color: transparent;"
                                         "background:url(:/images/black.png);position: center;padding:5px;"
                                         "background-repeat: none;"
                                         "border: none;");
    }else{
        ui->lblCurrPlayer->setStyleSheet("background-color: transparent;"
                                         "background:url(:/images/white.png);position: center;padding:5px;"
                                         "background-repeat: none;"
                                         "border: none;");
    }



    //update tiles color
    if(board.getColor(0,0) == '@'){
        ui->btn00->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,0) == 'O'){
        ui->btn00->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,0) == '_'){
        ui->btn00->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,0) == '*'){
        ui->btn00->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(0,1) == '@'){
        ui->btn01->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,1) == 'O'){
        ui->btn01->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,1) == '_'){
        ui->btn01->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,1) == '*'){
        ui->btn01->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(0,2) == '@'){
        ui->btn02->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,2) == 'O'){
        ui->btn02->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,2) == '_'){
        ui->btn02->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,2) == '*'){
        ui->btn02->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(0,3) == '@'){
        ui->btn03->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,3) == 'O'){
        ui->btn03->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,3) == '_'){
        ui->btn03->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,3) == '*'){
        ui->btn03->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(0,4) == '@'){
        ui->btn04->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,4) == 'O'){
        ui->btn04->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,4) == '_'){
        ui->btn04->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,4) == '*'){
        ui->btn04->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(0,5) == '@'){
        ui->btn05->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,5) == 'O'){
        ui->btn05->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,5) == '_'){
        ui->btn05->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,5) == '*'){
        ui->btn05->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(0,6) == '@'){
        ui->btn06->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,6) == 'O'){
        ui->btn06->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else
    if(board.getColor(0,6) == '_'){
        ui->btn06->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,6) == '*'){
        ui->btn06->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(0,7) == '@'){
        ui->btn07->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,7) == 'O'){
        ui->btn07->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else
    if(board.getColor(0,7) == '_'){
        ui->btn07->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,7) == '*'){
        ui->btn07->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================


    if(board.getColor(1,0) == '@'){
        ui->btn10->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,0) == 'O'){
        ui->btn10->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else
    if(board.getColor(1,0) == '_'){
        ui->btn10->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,0) == '*'){
        ui->btn10->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(1,1) == '@'){
        ui->btn11->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,1) == 'O'){
        ui->btn11->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    if(board.getColor(1,1) == '_'){
        ui->btn11->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,1) == '*'){
        ui->btn11->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(1,2) == '@'){
        ui->btn12->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,2) == 'O'){
        ui->btn12->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,2) == '_'){
        ui->btn12->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,2) == '*'){
        ui->btn12->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(1,3) == '@'){
        ui->btn13->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,3) == 'O'){
        ui->btn13->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    if(board.getColor(1,3) == '_'){
        ui->btn13->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,3) == '*'){
        ui->btn13->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(1,4) == '@'){
        ui->btn14->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,4) == 'O'){
        ui->btn14->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    if(board.getColor(1,4) == '_'){
        ui->btn14->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,4) == '*'){
        ui->btn14->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(1,5) == '@'){
        ui->btn15->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,5) == 'O'){
        ui->btn15->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    if(board.getColor(1,5) == '_'){
        ui->btn15->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,5) == '*'){
        ui->btn15->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(1,6) == '@'){
        ui->btn16->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,6) == 'O'){
        ui->btn16->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    if(board.getColor(1,6) == '_'){
        ui->btn16->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,6) == '*'){
        ui->btn16->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(1,7) == '@'){
        ui->btn17->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,7) == 'O'){
        ui->btn17->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    if(board.getColor(1,7) == '_'){
        ui->btn17->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,7) == '*'){
        ui->btn17->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================

    if(board.getColor(2,0) == '@'){
        ui->btn20->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,0) == 'O'){
        ui->btn20->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,0) == '_'){
        ui->btn20->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,0) == '*'){
        ui->btn20->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(2,1) == '@'){
        ui->btn21->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,1) == 'O'){
        ui->btn21->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,1) == '_'){
        ui->btn21->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,1) == '*'){
        ui->btn21->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(2,2) == '@'){
        ui->btn22->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,2) == 'O'){
        ui->btn22->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,2) == '_'){
        ui->btn22->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,2) == '*'){
        ui->btn22->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(2,3) == '@'){
        ui->btn23->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,3) == 'O'){
        ui->btn23->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    if(board.getColor(2,3) == '_'){
        ui->btn23->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,3) == '*'){
        ui->btn23->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(2,4) == '@'){
        ui->btn24->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,4) == 'O'){
        ui->btn24->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    if(board.getColor(2,4) == '_'){
        ui->btn24->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,4) == '*'){
        ui->btn24->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(2,5) == '@'){
        ui->btn25->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,5) == 'O'){
        ui->btn25->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,5) == '_'){
        ui->btn25->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    } else if(board.getColor(2,5) == '*'){
        ui->btn25->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(2,6) == '@'){
        ui->btn26->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,6) == 'O'){
        ui->btn26->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,6) == '_'){
        ui->btn26->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,6) == '*'){
        ui->btn26->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(2,7) == '@'){
        ui->btn27->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,7) == 'O'){
        ui->btn27->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,7) == '_'){
        ui->btn27->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,7) == '*'){
        ui->btn27->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    //=======3th row==========================
    if(board.getColor(3,0) == '@'){
        ui->btn30->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,0) == 'O'){
        ui->btn30->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,0) == '_'){
        ui->btn30->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,0) == '*'){
        ui->btn30->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(3,1) == '@'){
        ui->btn31->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,1) == 'O'){
        ui->btn31->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,1) == '_'){
        ui->btn31->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,1) == '*'){
        ui->btn31->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(3,2) == '@'){
        ui->btn32->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,2) == 'O'){
        ui->btn32->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,2) == '_'){
        ui->btn32->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,2) == '*'){
        ui->btn32->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================

    if(board.getColor(3,3) == '@'){

        ui->btn33->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,3) == 'O'){
        ui->btn33->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,3) == '_'){
        ui->btn33->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,3) == '*'){
        ui->btn33->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //===================
    if(board.getColor(3,4) == '@'){        
        ui->btn34->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,4) == 'O'){
        ui->btn34->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,4) == '_'){
        ui->btn34->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,4) == '*'){
        ui->btn34->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //====================
    if(board.getColor(3,5) == '@'){
        ui->btn35->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,5) == 'O'){
        ui->btn35->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,5) == '_'){
        ui->btn35->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,5) == '*'){
        ui->btn35->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(3,6) == '@'){
        ui->btn36->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,6) == 'O'){
        ui->btn36->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,6) == '_'){
        ui->btn36->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,6) == '*'){
        ui->btn36->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(3,7) == '@'){
        ui->btn37->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,7) == 'O'){
        ui->btn37->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,7) == '_'){
        ui->btn37->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,7) == '*'){
        ui->btn37->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================

    //=========4th row ========
    if(board.getColor(4,0) == '@'){
        ui->btn40->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,0) == 'O'){
        ui->btn40->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,0) == '_'){
        ui->btn40->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,0) == '*'){
        ui->btn40->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(4,1) == '@'){
        ui->btn41->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,1) == 'O'){
        ui->btn41->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,1) == '_'){
        ui->btn41->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,1) == '*'){
        ui->btn41->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(4,2) == '@'){
        ui->btn42->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,2) == 'O'){
        ui->btn42->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,2) == '_'){
        ui->btn42->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,2) == '*'){
        ui->btn42->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================


    if(board.getColor(4,3) == '@'){
        ui->btn43->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,3) == 'O'){
        ui->btn43->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,3) == '_'){
        ui->btn43->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,3) == '*'){
        ui->btn43->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //==================
    if(board.getColor(4,4) == '@'){

        ui->btn44->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,4) == 'O'){
        ui->btn44->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,4) == '_'){
        ui->btn44->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,4) == '*'){
        ui->btn44->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //========================
    if(board.getColor(4,5) == '@'){
        ui->btn45->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,5) == 'O'){
        ui->btn45->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,5) == '_'){
        ui->btn45->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(4,5) == '@'){
        ui->btn45->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,5) == 'O'){
        ui->btn45->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,5) == '_'){
        ui->btn45->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,5) == '*'){
        ui->btn45->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(4,6) == '@'){
        ui->btn46->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,6) == 'O'){
        ui->btn46->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,6) == '_'){
        ui->btn46->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,6) == '*'){
        ui->btn46->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================

    if(board.getColor(4,7) == '@'){
        ui->btn47->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,7) == 'O'){
        ui->btn47->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,7) == '_'){
        ui->btn47->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,7) == '*'){
        ui->btn47->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }


    //===== 5th row ======

    if(board.getColor(5,0) == '@'){
        ui->btn50->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,0) == 'O'){
        ui->btn50->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,0) == '_'){
        ui->btn50->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,0) == '*'){
        ui->btn50->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(5,1) == '@'){
        ui->btn51->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,1) == 'O'){
        ui->btn51->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else
    if(board.getColor(5,1) == '_'){
        ui->btn51->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,1) == '*'){
        ui->btn51->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(5,2) == '@'){
        ui->btn52->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,2) == 'O'){
        ui->btn52->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    if(board.getColor(5,2) == '_'){
        ui->btn52->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,2) == '*'){
        ui->btn52->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(5,3) == '@'){
        ui->btn53->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,3) == 'O'){
        ui->btn53->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,3) == '_'){
        ui->btn53->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,3) == '*'){
        ui->btn53->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(5,4) == '@'){
        ui->btn54->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,4) == 'O'){
        ui->btn54->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,4) == '_'){
        ui->btn54->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,4) == '*'){
        ui->btn54->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(5,5) == '@'){
        ui->btn55->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,5) == 'O'){
        ui->btn55->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,5) == '_'){
        ui->btn55->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,5) == '*'){
        ui->btn55->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(5,6) == '@'){
        ui->btn56->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,6) == 'O'){
        ui->btn56->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,6) == '_'){
        ui->btn56->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,6) == '*'){
        ui->btn56->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    /*if(board.getColor(5,6) == '@'){
        ui->btn56->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,6) == 'O'){
        ui->btn56->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,6) == '_'){
        ui->btn56->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,6) == '*'){
        ui->btn56->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }*/
    //=================


    if(board.getColor(5,7) == '@'){
        ui->btn57->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,7) == 'O'){
        ui->btn57->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    if(board.getColor(5,7) == '_'){
        ui->btn57->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,7) == '*'){
        ui->btn57->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(6,0) == '@'){
        ui->btn60->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,0) == 'O'){
        ui->btn60->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,0) == '_'){
        ui->btn60->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,0) == '*'){
        ui->btn60->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(6,1) == '@'){
        ui->btn61->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,1) == 'O'){
        ui->btn61->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    if(board.getColor(6,1) == '_'){
        ui->btn61->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,1) == '*'){
        ui->btn61->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(6,2) == '@'){
        ui->btn62->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,2) == 'O'){
        ui->btn62->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,2) == '_'){
        ui->btn62->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,2) == '*'){
        ui->btn62->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(6,3) == '@'){
        ui->btn63->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,3) == 'O'){
        ui->btn63->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    if(board.getColor(6,3) == '_'){
        ui->btn63->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,3) == '*'){
        ui->btn63->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(6,4) == '@'){
        ui->btn64->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,4) == 'O'){
        ui->btn64->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    if(board.getColor(6,4) == '_'){
        ui->btn64->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,4) == '*'){
        ui->btn64->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(6,5) == '@'){
        ui->btn65->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,5) == 'O'){
        ui->btn65->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else
    if(board.getColor(6,5) == '_'){
        ui->btn65->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,5) == '*'){
        ui->btn65->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(6,6) == '@'){
        ui->btn66->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,6) == 'O'){
        ui->btn66->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else
    if(board.getColor(6,7) == '_'){
        ui->btn67->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,7) == '*'){
        ui->btn67->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================


    if(board.getColor(7,0) == '@'){
        ui->btn70->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,0) == 'O'){
        ui->btn70->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,0) == '_'){
        ui->btn70->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,0) == '*'){
        ui->btn70->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(7,1) == '@'){
        ui->btn71->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,1) == 'O'){
        ui->btn71->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    if(board.getColor(7,1) == '_'){
        ui->btn71->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,1) == '*'){
        ui->btn71->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(7,2) == '@'){
        ui->btn72->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,2) == 'O'){
        ui->btn72->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,2) == '_'){
        ui->btn72->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,2) == '*'){
        ui->btn72->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(7,3) == '@'){
        ui->btn73->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,3) == 'O'){
        ui->btn73->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,3) == '_'){
        ui->btn73->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,3) == '*'){
        ui->btn73->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(7,4) == '@'){
        ui->btn74->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,4) == 'O'){
        ui->btn74->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    if(board.getColor(7,4) == '_'){
        ui->btn74->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,4) == '*'){
        ui->btn74->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(7,5) == '@'){
        ui->btn75->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,5) == 'O'){
        ui->btn75->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else
    if(board.getColor(7,5) == '_'){
        ui->btn75->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,5) == '*'){
        ui->btn75->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(7,6) == '@'){
        ui->btn76->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,6) == 'O'){
        ui->btn76->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,6) == '_'){
        ui->btn76->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================
    if(board.getColor(7,7) == '@'){
        ui->btn00->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,7) == 'O'){
        ui->btn00->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,7) == '_'){
        ui->btn00->setStyleSheet("background-color: transparent;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,7) == '*'){
        ui->btn77->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/smallwhite.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    //=================

    if(board.game_over()){
        QMessageBox MsgBox;
        MsgBox.setText("End Game");
        if(board.countBlack() > board.countWhite()){
            MsgBox.setText("Black win!");
        }else if(board.countBlack() < board.countWhite()){
            MsgBox.setText("White win!");
        }else {
            MsgBox.setText("Draw!");
        }
        MsgBox.exec();

    }


}//====end of Update board=========

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //GameBoard board;
    //AI ai;
    ui->setupUi(this);


    //updateGameBoard();

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
    ui->btn33->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn34->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
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
    ui->btn43->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
    ui->btn44->setStyleSheet("background-color: transparent;"
                             "background-repeat: none;"
                             "border: none;");
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
    updateBoard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MaiWindow:: clearBoard(){}

void MainWindow::on_btnNewGame_clicked()
{
	//connectTcp();
    bool check = true;
    int count = 0;
    QByteArray test;
    qint64 max = 8;
    test = _pSocket->read(max);
    qDebug() << test;
    string test2(test.constData(), test.length());
    //if(test2 == "WELCOME")
    //    qDebug() << "SUCCESS";
	string human_ai = "human_ai";
    QByteArray temp_choice(human_ai.c_str());
    _pSocket->write(temp_choice);
    test = _pSocket->read(max);
    qDebug() << temp_choice;
	string color = "WHITE";
    QByteArray temp_color(color.c_str());
    _pSocket->write(temp_color);
    qDebug() << temp_color;
	string difficulty = "EASY";
    QByteArray temp_difficulty(difficulty.c_str());
    _pSocket->write(temp_difficulty);
    qDebug() << temp_difficulty;

    /*QMessageBox MsgBox;
    MsgBox.setText("Hello World!");
    MsgBox.exec();*/


    /*ui->btn22->setStyleSheet("QPushButton{background:url(:/Resources/pause_nor.png);border:0px;}"
        "QPushButton:hover{background:url(:/Resources/pause_over.png);border:0px}"
        "QPushButton:pressed{background:url(:/Resources/pause_over.png); position: relative;top: 1px; left: 1px;}");*/

    //QPainter painter(this);
    //ui->lblBoard->setText("<img src =':/images/board.jpg'>");
    //painter.drawEllipse(QPointF(400,400), 10, 10);
    board.curColor = 'O';
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            board.setColor(i,j,'_');
        }
    }

    board.setColor(3,3,'O');
    board.setColor(3,4,'@');    
    board.setColor(4,4,'O');
    board.setColor(4,3,'@');

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

    updateBoard();
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    //if (event->button() == Qt::LeftButton) {
        //QPoint p = event->pos();
       //qDebug() << QString::number(p.x()) << "," << QString::number(p.x());

        //QPoint p1 = mapFromGlobal(QCursor::pos());

        //QMessageBox MsgBox;
        //MsgBox.setText(p.x()+"  "+p.y());
        //MsgBox.exec();
    //}
}



void MainWindow::on_btn00_clicked()
{
    //if(board.valid_move())
    if(board.getColor(0,0) == '_' && board.curColor == '@'){
        board.move(0,0);
        ui->btn00->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(0,0) == '_' && board.curColor == 'O'){
        board.move(0,0);
        ui->btn00->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn01_clicked()
{
    if(board.getColor(0,1) == '_' && board.curColor == '@'){
        board.move(0,1);
        ui->btn01->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(0,1) == '_' && board.curColor == 'O'){
        board.move(0,1);
        ui->btn01->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn02_clicked()
{
    if(board.getColor(0,2) == '_' && board.curColor == '@'){
        board.move(0,2);
        ui->btn02->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(0,2) == '_' && board.curColor == 'O'){
        board.move(0,2);
        ui->btn02->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);

    }
    updateBoard();
}



void MainWindow::on_btn03_clicked()
{
    if(board.getColor(0,3) == '_' && board.curColor == '@'){
        board.move(0,3);
        ui->btn03->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(0,3) == '_' && board.curColor == 'O'){
        board.move(0,3);
        ui->btn03->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn04_clicked()
{
    if(board.getColor(0,4) == '_' && board.curColor == '@'){
        board.move(0,4);
        ui->btn04->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(0,4) == '_' && board.curColor == 'O'){
        board.move(0,4);
        ui->btn04->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn05_clicked()
{
    if(board.getColor(0,5) == '_' && board.curColor == '@'){
        board.move(0,5);
        ui->btn05->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(0,5) == '_' && board.curColor == 'O'){
        board.move(0,5);
        ui->btn05->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn06_clicked()
{
    if(board.getColor(0,6) == '_' && board.curColor == '@'){
        board.move(0,6);
        ui->btn06->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(0,6) == '_' && board.curColor == 'O'){
        board.move(0,6);
        ui->btn06->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn07_clicked()
{
    if(board.getColor(0,7) == '_' && board.curColor == '@'){
        board.move(0,7);
        ui->btn07->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(0,7) == '_' && board.curColor == 'O'){
        board.move(0,7);
        ui->btn07->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}







void MainWindow::on_btn10_clicked()
{
    if(board.getColor(1,0) == '_' && board.curColor == '@'){
        board.move(1,0);
        ui->btn10->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(1,0) == '_' && board.curColor == 'O'){
        board.move(1,0);
        ui->btn10->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn11_clicked()
{
    if(board.getColor(1,1) == '_' && board.curColor == '@'){
        board.move(1,1);
        ui->btn11->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(1,1) == '_' && board.curColor == 'O'){
        board.move(1,1);
        ui->btn11->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn12_clicked()
{
    if(board.getColor(1,2) == '_' && board.curColor == '@'){
        board.move(1,2);
        ui->btn12->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(1,2) == '_' && board.curColor == 'O'){
        board.move(1,2);
        ui->btn12->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn13_clicked()
{
    if(board.getColor(1,3) == '_' && board.curColor == '@'){
        board.move(1,3);
        ui->btn13->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(1,3) == '_' && board.curColor == 'O'){
        board.move(1,3);
        ui->btn13->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn14_clicked()
{
    if(board.getColor(1,4) == '_' && board.curColor == '@'){
        board.move(1,4);
        ui->btn14->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(1,4) == '_' && board.curColor == 'O'){
        board.move(1,4);
        ui->btn14->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn15_clicked()
{
    if(board.getColor(1,5) == '_' && board.curColor == '@'){
        board.move(1,5);
        ui->btn15->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(1,5) == '_' && board.curColor == 'O'){
        board.move(1,5);
        ui->btn15->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn16_clicked()
{
    if(board.getColor(1,6) == '_' && board.curColor == '@'){
        board.move(1,6);
        ui->btn16->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(1,6) == '_' && board.curColor == 'O'){
        board.move(1,6);
        ui->btn16->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn17_clicked()
{
    if(board.getColor(1,7) == '_' && board.curColor == '@'){
        board.move(1,7);
        ui->btn17->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(1,7) == '_' && board.curColor == 'O'){
        board.move(1,7);
        ui->btn17->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn20_clicked()
{
    if(board.getColor(2,0) == '_' && board.curColor == '@'){
        board.move(2,0);
        ui->btn20->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(2,0) == '_' && board.curColor == 'O'){
        board.move(2,0);
        ui->btn20->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn21_clicked()
{
    if(board.getColor(2,1) == '_' && board.curColor == '@'){
        board.move(2,1);
        ui->btn21->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(2,1) == '_' && board.curColor == 'O'){
        board.move(2,1);
        ui->btn21->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn22_clicked()
{

    if(board.getColor(2,2) == '_' && board.curColor == '@'){
        board.move(2,2);
        ui->btn22->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(2,2) == '_' && board.curColor == 'O'){
        board.move(2,2);
        ui->btn22->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();

}
void MainWindow::on_btn23_clicked()
{
    if(board.getColor(2,3) == '_' && board.curColor == '@'){
        board.move(2,3);
        ui->btn23->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(2,3) == '_' && board.curColor == 'O'){
        board.move(2,3);
        ui->btn23->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn24_clicked()
{
    if(board.getColor(2,4) == '_' && board.curColor == '@'){
        board.move(2,4);
        ui->btn24->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(2,4) == '_' && board.curColor == 'O'){
        board.move(2,4);
        ui->btn24->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn25_clicked()
{
    if(board.getColor(2,5) == '_' && board.curColor == '@'){
        board.move(2,5);
        ui->btn25->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(2,5) == '_' && board.curColor == 'O'){
        board.move(2,5);
        ui->btn25->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn26_clicked()
{
    if(board.getColor(2,6) == '_' && board.curColor == '@'){
        board.move(2,6);
        ui->btn26->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(2,6) == '_' && board.curColor == 'O'){
        board.move(2,6);
        ui->btn26->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn27_clicked()
{
    if(board.getColor(2,7) == '_' && board.curColor == '@'){
        board.move(2,7);
        ui->btn27->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(2,7) == '_' && board.curColor == 'O'){
        board.move(2,7);
        ui->btn27->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn30_clicked()
{
    if(board.getColor(3,0) == '_' && board.curColor == '@'){
        board.move(3,0);
        ui->btn30->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(3,0) == '_' && board.curColor == 'O'){
        board.move(3,0);
        ui->btn30->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn31_clicked()
{
    if(board.getColor(3,1) == '_' && board.curColor == '@'){
        board.move(3,1);
        ui->btn31->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(3,1) == '_' && board.curColor == 'O'){
        board.move(3,1);
        ui->btn31->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn32_clicked()
{
    if(board.getColor(3,2) == '_' && board.curColor == '@'){
        board.move(3,2);
        ui->btn32->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(3,2) == '_' && board.curColor == 'O'){
        board.move(3,2);
        ui->btn32->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn33_clicked()
{
    if(board.getColor(3,3) == '_' && board.curColor == '@'){
        board.move(3,3);
        ui->btn33->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(3,3) == '_' && board.curColor == 'O'){
        board.move(3,3);
        ui->btn33->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn34_clicked()
{
    if(board.getColor(3,4) == '_' && board.curColor == '@'){
        board.move(3,4);
        ui->btn34->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(3,4) == '_' && board.curColor == 'O'){
        board.move(3,4);
        ui->btn34->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn35_clicked()
{
    if(board.getColor(3,5) == '_' && board.curColor == '@'){
        board.move(3,5);
        ui->btn35->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(3,5) == '_' && board.curColor == 'O'){
        board.move(3,5);
        ui->btn35->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn36_clicked()
{
    if(board.getColor(3,6) == '_' && board.curColor == '@'){
        board.move(3,6);
        ui->btn36->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(3,6) == '_' && board.curColor == 'O'){
        board.move(3,6);
        ui->btn36->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn37_clicked()
{
    if(board.getColor(3,7) == '_' && board.curColor == '@'){
        board.move(3,7);
        ui->btn37->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(3,7) == '_' && board.curColor == 'O'){
        board.move(3,7);
        ui->btn37->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn40_clicked()
{
    if(board.getColor(4,0) == '_' && board.curColor == '@'){
        board.move(4,0);
        ui->btn40->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(4,0) == '_' && board.curColor == 'O'){
        board.move(4,0);
        ui->btn40->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn41_clicked()
{
    if(board.getColor(4,1) == '_' && board.curColor == '@'){
        board.move(4,1);
        ui->btn41->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(4,1) == '_' && board.curColor == 'O'){
        board.move(4,1);
        ui->btn41->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn42_clicked()
{
    if(board.getColor(4,2) == '_' && board.curColor == '@'){
        board.move(4,2);
        ui->btn42->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(4,2) == '_' && board.curColor == 'O'){
        board.move(4,2);
        ui->btn42->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}
/*
void MainWindow::on_btn43_clicked()
{
    if(board.getColor(4,3) == '_' && board.curColor == '@'){
        board.move(4,3);
        ui->btn43->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,3) == '_' && board.curColor == 'O'){
        board.move(4,3);
        ui->btn43->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    updateBoard();
}

void MainWindow::on_btn44_clicked()
{
    if(board.getColor(4,4) == '_' && board.curColor == '@'){
        board.move(4,4);
        ui->btn44->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,4) == '_' && board.curColor == 'O'){
        board.move(4,4);
        ui->btn44->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    updateBoard();
}*/

void MainWindow::on_btn45_clicked()
{
    if(board.getColor(4,5) == '_' && board.curColor == '@'){
        board.move(4,5);
        ui->btn45->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(4,5) == '_' && board.curColor == 'O'){
        board.move(4,5);
        ui->btn45->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn46_clicked()
{
    if(board.getColor(4,6) == '_' && board.curColor == '@'){
        board.move(4,6);
        ui->btn46->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(4,6) == '_' && board.curColor == 'O'){
        board.move(4,6);
        ui->btn46->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn47_clicked()
{
    if(board.getColor(4,7) == '_' && board.curColor == '@'){
        board.move(4,7);
        ui->btn47->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(4,7) == '_' && board.curColor == 'O'){
        board.move(4,7);
        ui->btn47->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn50_clicked()
{
    if(board.getColor(5,0) == '_' && board.curColor == '@'){
        board.move(5,0);
        ui->btn50->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(5,0) == '_' && board.curColor == 'O'){
        board.move(5,0);
        ui->btn50->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn51_clicked()
{
    if(board.getColor(5,1) == '_' && board.curColor == '@'){
        board.move(5,1);
        ui->btn51->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(5,1) == '_' && board.curColor == 'O'){
        board.move(5,1);
        ui->btn51->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn52_clicked()
{
    if(board.getColor(5,2) == '_' && board.curColor == '@'){
        board.move(5,2);
        ui->btn52->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(5,2) == '_' && board.curColor == 'O'){
        board.move(5,2);
        ui->btn52->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn53_clicked()
{
    if(board.getColor(5,3) == '_' && board.curColor == '@'){
        board.move(5,3);
        ui->btn53->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(5,3) == '_' && board.curColor == 'O'){
        board.move(5,3);
        ui->btn53->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn54_clicked()
{
    if(board.getColor(5,4) == '_' && board.curColor == '@'){
        board.move(5,4);
        ui->btn54->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(5,4) == '_' && board.curColor == 'O'){
        board.move(5,4);
        ui->btn54->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn55_clicked()
{
    if(board.getColor(5,5) == '_' && board.curColor == '@'){
        board.move(5,5);
        ui->btn55->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(5,5) == '_' && board.curColor == 'O'){
        board.move(5,5);
        ui->btn55->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn56_clicked()
{
    if(board.getColor(5,6) == '_' && board.curColor == '@'){
        board.move(5,6);
        ui->btn56->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(5,6) == '_' && board.curColor == 'O'){
        board.move(5,6);
        ui->btn56->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn57_clicked()
{
    if(board.getColor(5,7) == '_' && board.curColor == '@'){
        board.move(5,7);
        ui->btn57->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(5,7) == '_' && board.curColor == 'O'){
        board.move(5,7);
        ui->btn57->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn60_clicked()
{
    if(board.getColor(6,0) == '_' && board.curColor == '@'){
        board.move(6,0);
        ui->btn60->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(6,0) == '_' && board.curColor == 'O'){
        board.move(6,0);
        ui->btn60->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn61_clicked()
{
    if(board.getColor(6,1) == '_' && board.curColor == '@'){
        board.move(6,1);
        ui->btn61->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,1) == '_' && board.curColor == 'O'){
        board.move(6,1);
        ui->btn61->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn62_clicked()
{
    if(board.getColor(6,2) == '_' && board.curColor == '@'){
        board.move(6,2);
        ui->btn62->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(6,2) == '_' && board.curColor == 'O'){
        board.move(6,2);
        ui->btn62->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn63_clicked()
{
    if(board.getColor(6,3) == '_' && board.curColor == '@'){
        board.move(6,3);
        ui->btn63->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(6,3) == '_' && board.curColor == 'O'){
        board.move(6,3);
        ui->btn63->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn64_clicked()
{
    if(board.getColor(6,4) == '_' && board.curColor == '@'){
        board.move(6,4);
        ui->btn64->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(6,4) == '_' && board.curColor == 'O'){
        board.move(6,4);
        ui->btn64->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn65_clicked()
{
    if(board.getColor(6,5) == '_' && board.curColor == '@'){
        board.move(6,5);
        ui->btn65->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(6,5) == '_' && board.curColor == 'O'){
        board.move(6,5);
        ui->btn65->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn66_clicked()
{
    if(board.getColor(6,6) == '_' && board.curColor == '@'){
        board.move(6,6);
        ui->btn66->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(6,6) == '_' && board.curColor == 'O'){
        board.move(6,6);
        ui->btn66->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn67_clicked()
{
    if(board.getColor(6,7) == '_' && board.curColor == '@'){
        board.move(6,7);
        ui->btn67->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(6,7) == '_' && board.curColor == 'O'){
        board.move(6,7);
        ui->btn67->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn70_clicked()
{
    if(board.getColor(7,0) == '_' && board.curColor == '@'){
        board.move(7,0);
        ui->btn70->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(7,0) == '_' && board.curColor == 'O'){
        board.move(7,0);
        ui->btn70->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn71_clicked()
{
    if(board.getColor(7,1) == '_' && board.curColor == '@'){
        board.move(7,1);
        ui->btn71->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(7,1) == '_' && board.curColor == 'O'){
        board.move(7,1);
        ui->btn71->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn72_clicked()
{
    if(board.getColor(7,2) == '_' && board.curColor == '@'){
        board.move(7,2);
        ui->btn72->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(7,2) == '_' && board.curColor == 'O'){
        board.move(7,2);
        ui->btn72->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn73_clicked()
{
    if(board.getColor(7,3) == '_' && board.curColor == '@'){
        board.move(7,3);
        ui->btn73->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(7,3) == '_' && board.curColor == 'O'){
        board.move(7,3);
        ui->btn73->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn74_clicked()
{
    if(board.getColor(7,4) == '_' && board.curColor == '@'){
        board.move(7,4);
        ui->btn74->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(7,4) == '_' && board.curColor == 'O'){
        board.move(7,4);
        ui->btn74->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn75_clicked()
{
    if(board.getColor(7,5) == '_' && board.curColor == '@'){
        board.move(7,5);
        ui->btn75->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(7,5) == '_' && board.curColor == 'O'){
        board.move(7,5);
        ui->btn75->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn76_clicked()
{
    if(board.getColor(7,6) == '_' && board.curColor == '@'){
        board.move(7,6);
        ui->btn76->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(7,6) == '_' && board.curColor == 'O'){
        board.move(7,6);
        ui->btn76->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn77_clicked()
{
    if(board.getColor(7,7) == '_' && board.curColor == '@'){
        board.move(7,7);
        ui->btn77->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(7,7) == '_' && board.curColor == 'O'){
        board.move(7,7);
        ui->btn77->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}



void MainWindow::on_btn43_clicked()
{
    if(board.getColor(4,3) == '_' && board.curColor == '@'){
        board.move(4,3);
        ui->btn43->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(4,3) == '_' && board.curColor == 'O'){
        board.move(4,3);
        ui->btn43->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btn44_clicked()
{
    if(board.getColor(4,4) == '_' && board.curColor == '@'){
        board.move(4,4);
        ui->btn44->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }else if(board.getColor(4,4) == '_' && board.curColor == 'O'){
        board.move(4,4);
        ui->btn44->setStyleSheet("background-color: transparent;"
                                 "background:url(:/images/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
        Move aimove = ai.aiMove(board).move;
        board.move(aimove.row,aimove.col);
    }
    updateBoard();
}

void MainWindow::on_btnUndo_clicked()
{
    if(board.undoboards.size()==0){
        QMessageBox MsgBox;
        MsgBox.setText("There's no more step to undo!");
        MsgBox.exec();

    }else{
        board.undo();
        board.undo();
        board.display_valid_moves();
        updateBoard();
    }

}


void MainWindow::connectTcp(){
    _pSocket = new QTcpSocket(this);
    //connect(_pSocket, SIGNAL(readyRead()), SLOT(readTcpData()));

    _pSocket->connectToHost("127.0.0.1", 5555);
    if(_pSocket->waitForConnected()){}
}