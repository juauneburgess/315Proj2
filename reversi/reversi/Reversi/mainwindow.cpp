#include <QPushButton>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QMessageBox>
#include <QtGui>
#include <QTcpSocket>
#include <QObject>
#include <unistd.h>

GameBoard board;
AI ai;
QTcpSocket * _pSocket;
string color;
string difficulty;
string game_type_option;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    white_play = new QPushButton("WHITE", this);
    white_play -> setGeometry(QRect(QPoint(100,100),QSize(200,50)));
    connect(white_play, SIGNAL(released()), this, SLOT(whitepressed()));

    black_play = new QPushButton("BLACK", this);
    black_play -> setGeometry(QRect(QPoint(100,150),QSize(200,50)));
    connect(black_play, SIGNAL(released()), this, SLOT(blackpressed()));

    human_ai = new QPushButton("Human-AI", this);
    human_ai -> setGeometry(QRect(QPoint(0,0),QSize(0,0)));
    connect(human_ai, SIGNAL(released()), this, SLOT(human_aipressed()));

    ai_ai = new QPushButton("AI-AI", this);
    ai_ai -> setGeometry(QRect(QPoint(0,0),QSize(0,0)));
    connect(ai_ai, SIGNAL(released()), this, SLOT(ai_aipressed()));

    easy = new QPushButton("Easy", this);
    easy -> setGeometry(QRect(QPoint(0,0),QSize(0,0)));
    connect(easy, SIGNAL(released()), this, SLOT(easypressed()));

    medium = new QPushButton("Medium", this);
    medium -> setGeometry(QRect(QPoint(0,0),QSize(0,0)));
    connect(medium, SIGNAL(released()), this, SLOT(mediumpressed()));

    hard = new QPushButton("Hard", this);
    hard -> setGeometry(QRect(QPoint(0,0),QSize(0,0)));
    connect(hard, SIGNAL(released()), this, SLOT(hardpressed()));

    ai1_easy = new QPushButton("Easy-First Player", this);
    ai1_easy -> setGeometry(QRect(QPoint(0,0),QSize(0,0)));
    connect(ai1_easy, SIGNAL(released()), this, SLOT(ai1_easypressed()));

    ai1_medium = new QPushButton("Medium-First Player", this);
    ai1_medium -> setGeometry(QRect(QPoint(0,0),QSize(0,0)));
    connect(ai1_medium, SIGNAL(released()), this, SLOT(ai1_mediumpressed()));

    ai1_hard = new QPushButton("Hard-First Player", this);
    ai1_hard -> setGeometry(QRect(QPoint(0,0),QSize(0,0)));
    connect(ai1_hard, SIGNAL(released()), this, SLOT(ai1_hardpressed()));

    ai2_easy = new QPushButton("Easy-Second Player", this);
    ai2_easy -> setGeometry(QRect(QPoint(0,0),QSize(0,0)));
    connect(ai2_easy, SIGNAL(released()), this, SLOT(ai2_easypressed()));

    ai2_medium = new QPushButton("Medium-Second Player", this);
    ai2_medium -> setGeometry(QRect(QPoint(0,0),QSize(0,0)));
    connect(ai2_medium, SIGNAL(released()), this, SLOT(ai2_mediumpressed()));

    ai2_hard = new QPushButton("Hard-Second Player", this);
    ai2_hard -> setGeometry(QRect(QPoint(0,0),QSize(0,0)));
    connect(ai2_hard, SIGNAL(released()), this, SLOT(ai2_hardpressed()));

    StartGame = new QPushButton("Start Game", this);
    StartGame -> setGeometry(QRect(QPoint(0,0),QSize(0,0)));
    connect(StartGame, SIGNAL(released()), this, SLOT(on_btnStartGame_clicked()));
	
	//HUYS CODE HERE//
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

bool MainWindow::whitepressed()
{
    //player is white
    choice = "WHITE";
    bool pressed = true;
    delete white_play;
    delete black_play;

    human_ai -> setGeometry(QRect(QPoint(100,100),QSize(200,50)));
    ai_ai -> setGeometry(QRect(QPoint(100,150),QSize(200,50)));
    handle_choice_click(choice);
    return pressed;
}

bool MainWindow::blackpressed()
{
    //player is black
    choice = "BLACK";
    bool pressed = true;
    delete white_play;
    delete black_play;

    human_ai -> setGeometry(QRect(QPoint(100,100),QSize(200,50)));
    ai_ai -> setGeometry(QRect(QPoint(100,150),QSize(200,50)));
    handle_choice_click(choice);
    return pressed;
}

bool MainWindow::human_aipressed()
{
    //game play is human-ai
    choice = "HUMAN-AI";
    bool pressed = true;
    delete human_ai;
    delete ai_ai;

    easy -> setGeometry(QRect(QPoint(100,100),QSize(200,50)));
    medium -> setGeometry(QRect(QPoint(100,150),QSize(200,50)));
    hard -> setGeometry(QRect(QPoint(100,200),QSize(200,50)));
    handle_choice_click(choice);
    return pressed;
}

bool MainWindow::ai_aipressed()
{
    //game play is ai-ai
    choice = "AI-AI";
    bool pressed = true;
    delete human_ai;
    delete ai_ai;

    ai1_easy -> setGeometry(QRect(QPoint(100,100),QSize(200,50)));
    ai1_medium -> setGeometry(QRect(QPoint(100,150),QSize(200,50)));
    ai1_hard -> setGeometry(QRect(QPoint(100,200),QSize(200,50)));
    handle_choice_click(choice);
    return pressed;
}

bool MainWindow::easypressed()
{
    //difficulty is easy
    choice = "EASY";
    bool pressed = true;
    delete easy;
    delete medium;
    delete hard;

    StartGame -> setGeometry(QRect(QPoint(100,100),QSize(200,50)));
    handle_choice_click(choice);
    return pressed;
}

bool MainWindow::mediumpressed()
{
    //difficulty is medium
    choice = "MEDIUM";
    bool pressed = true;
    delete easy;
    delete medium;
    delete hard;

    StartGame -> setGeometry(QRect(QPoint(100,100),QSize(200,50)));
    handle_choice_click(choice);
    return pressed;
}

bool MainWindow::hardpressed()
{
    //difficulty is hard
    choice = "HARD";
    bool pressed = true;
    delete easy;
    delete medium;
    delete hard;

    StartGame -> setGeometry(QRect(QPoint(100,100),QSize(200,50)));
    handle_choice_click(choice);
    return pressed;
}

bool MainWindow::ai1_easypressed()
{
    //ai1 difficulty is easy
    choice = "EASY";
    bool pressed = true;
    delete ai1_easy;
    delete ai1_medium;
    delete ai1_hard;

    ai2_easy -> setGeometry(QRect(QPoint(100,100),QSize(200,50)));
    ai2_medium -> setGeometry(QRect(QPoint(100,150),QSize(200,50)));
    ai2_hard -> setGeometry(QRect(QPoint(100,200),QSize(200,50)));
    handle_choice_click(choice);
    return pressed;
}

bool MainWindow::ai1_mediumpressed()
{
    //ai1 difficulty is medium
    choice = "MEDIUM";
    bool pressed = true;
    delete ai1_easy;
    delete ai1_medium;
    delete ai1_hard;

    ai2_easy -> setGeometry(QRect(QPoint(100,100),QSize(200,50)));
    ai2_medium -> setGeometry(QRect(QPoint(100,150),QSize(200,50)));
    ai2_hard -> setGeometry(QRect(QPoint(100,200),QSize(200,50)));
    handle_choice_click(choice);
    return pressed;
}

bool MainWindow::ai1_hardpressed()
{
    //ai1 difficulty is hard
    choice = "HARD";
    bool pressed = true;
    delete ai1_easy;
    delete ai1_medium;
    delete ai1_hard;

    ai2_easy -> setGeometry(QRect(QPoint(100,100),QSize(200,50)));
    ai2_medium -> setGeometry(QRect(QPoint(100,150),QSize(200,50)));
    ai2_hard -> setGeometry(QRect(QPoint(100,200),QSize(200,50)));
    handle_choice_click(choice);
    return pressed;
}

bool MainWindow::ai2_easypressed()
{
    //ai2 difficulty is easy
    choice = "EASY";
    bool pressed = true;
    delete ai2_easy;
    delete ai2_medium;
    delete ai2_hard;

    StartGame -> setGeometry(QRect(QPoint(100,100),QSize(200,50)));
    handle_choice_click(choice);
    return pressed;
}

bool MainWindow::ai2_mediumpressed()
{
    //ai2 difficulty is medium
    choice = "MEDIUM";
    bool pressed = true;
    delete ai2_easy;
    delete ai2_medium;
    delete ai2_hard;

    StartGame -> setGeometry(QRect(QPoint(100,100),QSize(200,50)));
    handle_choice_click(choice);
    return pressed;
}

bool MainWindow::ai2_hardpressed()
{
    //ai2 difficulty is hard
    choice = "HARD";
    bool pressed = true;
    delete ai2_easy;
    delete ai2_medium;
    delete ai2_hard;

    StartGame -> setGeometry(QRect(QPoint(100,100),QSize(200,50)));
    handle_choice_click(choice);
    return pressed;
}

string MainWindow::handle_game_click(string index)
{
    QString ind = index.c_str();
    clicks.push_back(index);
    qDebug() << ind << "Vector Size: " << clicks.size();
    //receive_click();
    return index;
}

string MainWindow::handle_choice_click(string choice)
{
    QString cho = choice.c_str();
    qDebug() << cho;
    choices.push_back(choice);
    //receive_choice();
    if(choice == "WHITE")
        color = "WHITE ";
    if(choice == "BLACK")
        color = "BLACK ";
    if(choice == "EASY")
        difficulty = "EASY ";
    if(choice == "MEDIUM")
        difficulty = "MEDIUM ";
    if(choice == "HARD")
        difficulty = "HARD ";
    if(choice == "HUMAN-AI")
        game_type_option = "HUMAN-AI ";
    if(choice == "AI-AI")
        game_type_option = "AI-AI ";
    return choice;
}

/*void MainWindow::receive_click(vector<string> clicked)
{
    for(int i = 0; i < clicks.size(); i++)
    {
        clicked.push_back(clicks[i]);
    }
}*/

//HUYS CODE HERE//
void MainWindow::on_btnStartGame_clicked()
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
    QByteArray temp_choice(game_type_option.c_str());
    _pSocket->write(temp_choice);
    test = _pSocket->read(max);
    qDebug() << temp_choice;
    QByteArray temp_color(color.c_str());
    _pSocket->write(temp_color);
    qDebug() << temp_color;
    QByteArray temp_difficulty(difficulty.c_str());
    _pSocket->write(temp_difficulty);
    qDebug() << temp_difficulty;
    /*while(check){
        max = 255;
        test = _pSocket->read(max);
        qDebug() << test;
        string test2(test.constData(), test.length());
       if(test2 == "/nOK"&& count == 100){
            QByteArray temp_color(color.c_str());
            _pSocket->write(temp_color);
            check = false;
        }
        count++;


    }*/
    /*QMessageBox MsgBox;
    MsgBox.setText("Hello World!");
    MsgBox.exec();
    */

    //ui->btn22->setStyleSheet("QPushButton{background:url(:/Resources/pause_nor.png);border:0px;}"
    //    "QPushButton:hover{background:url(:/Resources/pause_over.png);border:0px}"
    //    "QPushButton:pressed{background:url(:/Resources/pause_over.png); position: relative;top: 1px; left: 1px;}");

    delete StartGame;

    QPainter painter(this);
    ui->lblBoard->setText("<img src =':/board.jpg'>");
    painter.drawEllipse(QPointF(400,400), 10, 10);

    ui->label_2->setText("<img src =':/white.png'>");
    painter.drawEllipse(QPointF(400,400), 10, 10);
    ui->label_3->setText("<img src =':/white.png'>");
    painter.drawEllipse(QPointF(300,300), 10, 10);

    ui->label_4->setText("<img src =':/black.png'>");
    painter.drawEllipse(QPointF(400,400), 10, 10);
    ui->label_5->setText("<img src =':/black.png'>");
    painter.drawEllipse(QPointF(400,400), 10, 10);

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
    index = "00";
    if(board.getColor(0,0) == '_' && board.curColor == '@'){
        board.move(0,0);
        ui->btn00->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,0) == '_' && board.curColor == 'O'){
        board.move(0,0);
        ui->btn00->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn01_clicked()
{
    index = "01";
    if(board.getColor(0,1) == '_' && board.curColor == '@'){
        board.move(0,1);
        ui->btn01->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,1) == '_' && board.curColor == 'O'){
        board.move(0,1);
        ui->btn01->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn02_clicked()
{
    index = "02";
    if(board.getColor(0,2) == '_' && board.curColor == '@'){
        board.move(0,2);
        ui->btn02->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,2) == '_' && board.curColor == 'O'){
        board.move(0,2);
        ui->btn02->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}



void MainWindow::on_btn03_clicked()
{
    index = "03";
    if(board.getColor(0,3) == '_' && board.curColor == '@'){
        board.move(0,3);
        ui->btn03->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,3) == '_' && board.curColor == 'O'){
        board.move(0,3);
        ui->btn03->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn04_clicked()
{
    index = "04";
    if(board.getColor(0,4) == '_' && board.curColor == '@'){
        board.move(0,4);
        ui->btn04->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,4) == '_' && board.curColor == 'O'){
        board.move(0,4);
        ui->btn04->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn05_clicked()
{

    index = "05";
    if(board.getColor(0,5) == '_' && board.curColor == '@'){
        board.move(0,5);
        ui->btn05->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,5) == '_' && board.curColor == 'O'){
        board.move(0,5);
        ui->btn05->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn06_clicked()
{
    index = "06";
    if(board.getColor(0,6) == '_' && board.curColor == '@'){
        board.move(0,6);
        ui->btn06->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,6) == '_' && board.curColor == 'O'){
        board.move(0,6);
        ui->btn06->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn07_clicked()
{
    index = "07";
    if(board.getColor(0,7) == '_' && board.curColor == '@'){
        board.move(0,7);
        ui->btn07->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(0,7) == '_' && board.curColor == 'O'){
        board.move(0,7);
        ui->btn07->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn10_clicked()
{
    index = "10";
    if(board.getColor(1,0) == '_' && board.curColor == '@'){
        board.move(1,0);
        ui->btn10->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,0) == '_' && board.curColor == 'O'){
        board.move(1,0);
        ui->btn10->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn11_clicked()
{
    index = "11";
    if(board.getColor(1,1) == '_' && board.curColor == '@'){
        board.move(1,1);
        ui->btn11->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,1) == '_' && board.curColor == 'O'){
        board.move(1,1);
        ui->btn11->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn12_clicked()
{
    index = "12";
    if(board.getColor(1,2) == '_' && board.curColor == '@'){
        board.move(1,2);
        ui->btn12->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,2) == '_' && board.curColor == 'O'){
        board.move(1,2);
        ui->btn12->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn13_clicked()
{
    index = "13";
    if(board.getColor(1,3) == '_' && board.curColor == '@'){
        board.move(1,3);
        ui->btn13->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,3) == '_' && board.curColor == 'O'){
        board.move(1,3);
        ui->btn13->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn14_clicked()
{
    index = "14";
    if(board.getColor(1,4) == '_' && board.curColor == '@'){
        board.move(1,4);
        ui->btn14->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,4) == '_' && board.curColor == 'O'){
        board.move(1,4);
        ui->btn14->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn15_clicked()
{
    index = "15";
    if(board.getColor(1,5) == '_' && board.curColor == '@'){
        board.move(1,5);
        ui->btn15->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,5) == '_' && board.curColor == 'O'){
        board.move(1,5);
        ui->btn15->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn16_clicked()
{
    index = "16";
    if(board.getColor(1,6) == '_' && board.curColor == '@'){
        board.move(1,6);
        ui->btn16->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,6) == '_' && board.curColor == 'O'){
        board.move(1,6);
        ui->btn16->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn17_clicked()
{
    index = "17";
    if(board.getColor(1,7) == '_' && board.curColor == '@'){
        board.move(1,7);
        ui->btn17->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(1,7) == '_' && board.curColor == 'O'){
        board.move(1,7);
        ui->btn17->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn20_clicked()
{
    index = "20";
    if(board.getColor(2,0) == '_' && board.curColor == '@'){
        board.move(2,0);
        ui->btn20->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,0) == '_' && board.curColor == 'O'){
        board.move(2,0);
        ui->btn20->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn21_clicked()
{
    index = "21";
    if(board.getColor(2,1) == '_' && board.curColor == '@'){
        board.move(2,1);
        ui->btn21->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,1) == '_' && board.curColor == 'O'){
        board.move(2,1);
        ui->btn21->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn22_clicked()
{
    index = "22";
    if(board.getColor(2,2) == '_' && board.curColor == '@'){
        board.move(2,2);
        ui->btn22->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,2) == '_' && board.curColor == 'O'){
        board.move(2,2);
        ui->btn22->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn23_clicked()
{
    index = "23";
    if(board.getColor(2,3) == '_' && board.curColor == '@'){
        board.move(2,3);
        ui->btn23->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,3) == '_' && board.curColor == 'O'){
        board.move(2,3);
        ui->btn23->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn24_clicked()
{
    index = "24";
    if(board.getColor(2,4) == '_' && board.curColor == '@'){
        board.move(2,4);
        ui->btn24->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,4) == '_' && board.curColor == 'O'){
        board.move(2,4);
        ui->btn24->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn25_clicked()
{
    index = "25";
    if(board.getColor(2,5) == '_' && board.curColor == '@'){
        board.move(2,5);
        ui->btn25->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,5) == '_' && board.curColor == 'O'){
        board.move(2,5);
        ui->btn25->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn26_clicked()
{
    index = "26";
    if(board.getColor(2,6) == '_' && board.curColor == '@'){
        board.move(2,6);
        ui->btn26->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,6) == '_' && board.curColor == 'O'){
        board.move(2,6);
        ui->btn26->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn27_clicked()
{
    index = "27";
    if(board.getColor(2,7) == '_' && board.curColor == '@'){
        board.move(2,7);
        ui->btn27->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(2,7) == '_' && board.curColor == 'O'){
        board.move(2,7);
        ui->btn27->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn30_clicked()
{
    index = "30";
    if(board.getColor(3,0) == '_' && board.curColor == '@'){
        board.move(3,0);
        ui->btn30->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,0) == '_' && board.curColor == 'O'){
        board.move(3,0);
        ui->btn30->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn31_clicked()
{
    index = "31";
    if(board.getColor(3,1) == '_' && board.curColor == '@'){
        board.move(3,1);
        ui->btn31->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,1) == '_' && board.curColor == 'O'){
        board.move(3,1);
        ui->btn31->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn32_clicked()
{
    index = "32";
    if(board.getColor(3,2) == '_' && board.curColor == '@'){
        board.move(3,2);
        ui->btn32->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,2) == '_' && board.curColor == 'O'){
        board.move(3,2);
        ui->btn32->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn35_clicked()
{
    index = "35";
    if(board.getColor(3,5) == '_' && board.curColor == '@'){
        board.move(3,5);
        ui->btn35->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,5) == '_' && board.curColor == 'O'){
        board.move(3,5);
        ui->btn35->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn36_clicked()
{
    index = "36";
    if(board.getColor(3,6) == '_' && board.curColor == '@'){
        board.move(3,6);
        ui->btn36->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,6) == '_' && board.curColor == 'O'){
        board.move(3,6);
        ui->btn36->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn37_clicked()
{
    index = "37";
    if(board.getColor(3,7) == '_' && board.curColor == '@'){
        board.move(3,7);
        ui->btn37->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(3,7) == '_' && board.curColor == 'O'){
        board.move(3,7);
        ui->btn37->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn40_clicked()
{
    index = "40";
    if(board.getColor(4,0) == '_' && board.curColor == '@'){
        board.move(4,0);
        ui->btn40->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,0) == '_' && board.curColor == 'O'){
        board.move(4,0);
        ui->btn40->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn41_clicked()
{
    index = "41";
    if(board.getColor(4,1) == '_' && board.curColor == '@'){
        board.move(4,1);
        ui->btn41->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,1) == '_' && board.curColor == 'O'){
        board.move(4,1);
        ui->btn41->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn42_clicked()
{
    index = "42";
    if(board.getColor(4,2) == '_' && board.curColor == '@'){
        board.move(4,2);
        ui->btn42->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,2) == '_' && board.curColor == 'O'){
        board.move(4,2);
        ui->btn42->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn45_clicked()
{
    index = "45";
    if(board.getColor(4,5) == '_' && board.curColor == '@'){
        board.move(4,5);
        ui->btn45->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,5) == '_' && board.curColor == 'O'){
        board.move(4,5);
        ui->btn45->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn46_clicked()
{
    index = "46";
    if(board.getColor(4,6) == '_' && board.curColor == '@'){
        board.move(4,6);
        ui->btn46->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,6) == '_' && board.curColor == 'O'){
        board.move(4,6);
        ui->btn46->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn47_clicked()
{
    index = "47";
    if(board.getColor(4,7) == '_' && board.curColor == '@'){
        board.move(4,7);
        ui->btn47->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(4,7) == '_' && board.curColor == 'O'){
        board.move(4,7);
        ui->btn47->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn50_clicked()
{
    index = "50";
    if(board.getColor(5,0) == '_' && board.curColor == '@'){
        board.move(5,0);
        ui->btn50->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,0) == '_' && board.curColor == 'O'){
        board.move(5,0);
        ui->btn50->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn51_clicked()
{
    index = "51";
    if(board.getColor(5,1) == '_' && board.curColor == '@'){
        board.move(5,1);
        ui->btn51->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,1) == '_' && board.curColor == 'O'){
        board.move(5,1);
        ui->btn51->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn52_clicked()
{
    index = "52";
    if(board.getColor(5,2) == '_' && board.curColor == '@'){
        board.move(5,2);
        ui->btn52->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,2) == '_' && board.curColor == 'O'){
        board.move(5,2);
        ui->btn52->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn53_clicked()
{
    index = "53";
    if(board.getColor(5,3) == '_' && board.curColor == '@'){
        board.move(5,3);
        ui->btn53->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,3) == '_' && board.curColor == 'O'){
        board.move(5,3);
        ui->btn53->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn54_clicked()
{
    index = "54";
    if(board.getColor(5,4) == '_' && board.curColor == '@'){
        board.move(5,4);
        ui->btn54->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,4) == '_' && board.curColor == 'O'){
        board.move(5,4);
        ui->btn54->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn55_clicked()
{
    index = "55";
    if(board.getColor(5,5) == '_' && board.curColor == '@'){
        board.move(5,5);
        ui->btn55->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,5) == '_' && board.curColor == 'O'){
        board.move(5,5);
        ui->btn55->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn56_clicked()
{
    index = "56";
    if(board.getColor(5,6) == '_' && board.curColor == '@'){
        board.move(5,6);
        ui->btn56->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,6) == '_' && board.curColor == 'O'){
        board.move(5,6);
        ui->btn56->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn57_clicked()
{
    index = "57";
    if(board.getColor(5,7) == '_' && board.curColor == '@'){
        board.move(5,7);
        ui->btn57->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(5,7) == '_' && board.curColor == 'O'){
        board.move(5,7);
        ui->btn57->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn60_clicked()
{
    index = "60";
    if(board.getColor(6,0) == '_' && board.curColor == '@'){
        board.move(6,0);
        ui->btn60->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,0) == '_' && board.curColor == 'O'){
        board.move(6,0);
        ui->btn60->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn61_clicked()
{
    index = "61";
    if(board.getColor(6,1) == '_' && board.curColor == '@'){
        board.move(6,1);
        ui->btn61->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,1) == '_' && board.curColor == 'O'){
        board.move(6,1);
        ui->btn61->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn62_clicked()
{
    index = "62";
    if(board.getColor(6,2) == '_' && board.curColor == '@'){
        board.move(6,2);
        ui->btn62->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,2) == '_' && board.curColor == 'O'){
        board.move(6,2);
        ui->btn62->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn63_clicked()
{
    index = "63";
    if(board.getColor(6,3) == '_' && board.curColor == '@'){
        board.move(6,3);
        ui->btn63->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,3) == '_' && board.curColor == 'O'){
        board.move(6,3);
        ui->btn63->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn64_clicked()
{
    index = "64";
    if(board.getColor(6,4) == '_' && board.curColor == '@'){
        board.move(6,4);
        ui->btn64->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,4) == '_' && board.curColor == 'O'){
        board.move(6,4);
        ui->btn64->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn65_clicked()
{
    index = "65";
    if(board.getColor(6,5) == '_' && board.curColor == '@'){
        board.move(6,5);
        ui->btn65->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,5) == '_' && board.curColor == 'O'){
        board.move(6,5);
        ui->btn65->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn66_clicked()
{
    index = "66";
    if(board.getColor(6,6) == '_' && board.curColor == '@'){
        board.move(6,6);
        ui->btn66->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,6) == '_' && board.curColor == 'O'){
        board.move(6,6);
        ui->btn66->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn67_clicked()
{
    index = "67";
    if(board.getColor(6,7) == '_' && board.curColor == '@'){
        board.move(6,7);
        ui->btn67->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(6,7) == '_' && board.curColor == 'O'){
        board.move(6,7);
        ui->btn67->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn70_clicked()
{
    index = "70";
    if(board.getColor(7,0) == '_' && board.curColor == '@'){
        board.move(7,0);
        ui->btn70->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,0) == '_' && board.curColor == 'O'){
        board.move(7,0);
        ui->btn70->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn71_clicked()
{
    index = "71";
    if(board.getColor(7,1) == '_' && board.curColor == '@'){
        board.move(7,1);
        ui->btn71->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,1) == '_' && board.curColor == 'O'){
        board.move(7,1);
        ui->btn71->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn72_clicked()
{
    index = "72";
    if(board.getColor(7,2) == '_' && board.curColor == '@'){
        board.move(7,2);
        ui->btn72->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,2) == '_' && board.curColor == 'O'){
        board.move(7,2);
        ui->btn72->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn73_clicked()
{
    index = "73";
    if(board.getColor(7,3) == '_' && board.curColor == '@'){
        board.move(7,3);
        ui->btn73->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,3) == '_' && board.curColor == 'O'){
        board.move(7,3);
        ui->btn73->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn74_clicked()
{
    index = "74";
    if(board.getColor(7,4) == '_' && board.curColor == '@'){
        board.move(7,4);
        ui->btn74->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,4) == '_' && board.curColor == 'O'){
        board.move(7,4);
        ui->btn74->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn75_clicked()
{
    index = "75";
    if(board.getColor(7,5) == '_' && board.curColor == '@'){
        board.move(7,5);
        ui->btn75->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,5) == '_' && board.curColor == 'O'){
        board.move(7,5);
        ui->btn75->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn76_clicked()
{
    index = "76";
    if(board.getColor(7,6) == '_' && board.curColor == '@'){
        board.move(7,6);
        ui->btn76->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,6) == '_' && board.curColor == 'O'){
        board.move(7,6);
        ui->btn76->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::on_btn77_clicked()
{
    index = "77";
    if(board.getColor(7,7) == '_' && board.curColor == '@'){
        board.move(7,7);
        ui->btn77->setStyleSheet("background-color: transparent;"
                                 "background:url(:/black.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }else if(board.getColor(7,7) == '_' && board.curColor == 'O'){
        board.move(7,7);
        ui->btn77->setStyleSheet("background-color: transparent;"
                                 "background:url(:/white.png);position: center;padding:5px;"
                                 "background-repeat: none;"
                                 "border: none;");
    }
    handle_game_click(index);
}

void MainWindow::end_game()
{
    if(board.countBlack() + board.countWhite() == 64 )
    {
        QMessageBox MsgBox;
        MsgBox.setText("Game Over!");
        MsgBox.exec();

    }
}

void MainWindow::connectTcp(){
    _pSocket = new QTcpSocket(this);
    //connect(_pSocket, SIGNAL(readyRead()), SLOT(readTcpData()));

    _pSocket->connectToHost("127.0.0.1", 5555);
    if(_pSocket->waitForConnected()){}
}

