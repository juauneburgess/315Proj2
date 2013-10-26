#include <QPushButton>
#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "game_server.cpp"
//#include "game_server.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)//,
   // ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
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
    connect(ai2_hard, SIGNAL(released()), this, SLOT(a2_hardpressed()));
}


MainWindow::~MainWindow()
{
   // delete ui;
}

bool MainWindow::whitepressed()
{
    //player is white
    bool pressed = true;
    delete white_play;
    delete black_play;

    human_ai -> setGeometry(QRect(QPoint(100,100),QSize(200,50)));
    ai_ai -> setGeometry(QRect(QPoint(100,150),QSize(200,50)));

    return pressed;
}

bool MainWindow::blackpressed()
{
    //player is black
    bool pressed = true;
    delete white_play;
    delete black_play;

    human_ai -> setGeometry(QRect(QPoint(100,100),QSize(200,50)));
    ai_ai -> setGeometry(QRect(QPoint(100,150),QSize(200,50)));

    return pressed;
}

bool MainWindow::human_aipressed()
{
    //game play is human-ai
    bool pressed = true;
    delete human_ai;
    delete ai_ai;

    easy -> setGeometry(QRect(QPoint(100,100),QSize(200,50)));
    medium -> setGeometry(QRect(QPoint(100,150),QSize(200,50)));
    hard -> setGeometry(QRect(QPoint(100,200),QSize(200,50)));

    return pressed;
}

bool MainWindow::ai_aipressed()
{
    //game play is ai-ai
    bool pressed = true;
    delete human_ai;
    delete ai_ai;

    ai1_easy -> setGeometry(QRect(QPoint(100,100),QSize(200,50)));
    ai1_medium -> setGeometry(QRect(QPoint(100,150),QSize(200,50)));
    ai1_hard -> setGeometry(QRect(QPoint(100,200),QSize(200,50)));

    return pressed;
}

bool MainWindow::easypressed()
{
    //difficulty is easy
    bool pressed = true;
    delete easy;
    delete medium;
    delete hard;

    return pressed;
}

bool MainWindow::mediumpressed()
{
    //difficulty is medium
    bool pressed = true;
    delete easy;
    delete medium;
    delete hard;

    return pressed;
}

bool MainWindow::hardpressed()
{
    //difficulty is hard
    bool pressed = true;
    delete easy;
    delete medium;
    delete hard;

    return pressed;
}

bool MainWindow::ai1_easypressed()
{
    //ai1 difficulty is easy
    bool pressed = true;
    delete ai1_easy;
    delete ai1_medium;
    delete ai1_hard;

    ai2_easy -> setGeometry(QRect(QPoint(100,100),QSize(200,50)));
    ai2_medium -> setGeometry(QRect(QPoint(100,150),QSize(200,50)));
    ai2_hard -> setGeometry(QRect(QPoint(100,200),QSize(200,50)));

    return pressed;
}

bool MainWindow::ai1_mediumpressed()
{
    //ai1 difficulty is medium
    bool pressed = true;
    delete ai1_easy;
    delete ai1_medium;
    delete ai1_hard;

    ai2_easy -> setGeometry(QRect(QPoint(100,100),QSize(200,50)));
    ai2_medium -> setGeometry(QRect(QPoint(100,150),QSize(200,50)));
    ai2_hard -> setGeometry(QRect(QPoint(100,200),QSize(200,50)));

    return pressed;
}

bool MainWindow::ai1_hardpressed()
{
    //ai1 difficulty is hard
    bool pressed = true;
    delete ai1_easy;
    delete ai1_medium;
    delete ai1_hard;

    ai2_easy -> setGeometry(QRect(QPoint(100,100),QSize(200,50)));
    ai2_medium -> setGeometry(QRect(QPoint(100,150),QSize(200,50)));
    ai2_hard -> setGeometry(QRect(QPoint(100,200),QSize(200,50)));

    return pressed;
}

bool MainWindow::ai2_easypressed()
{
    //ai2 difficulty is easy
    bool pressed = true;
    delete ai2_easy;
    delete ai2_medium;
    delete ai2_hard;

    return pressed;
}

bool MainWindow::ai2_mediumpressed()
{
    //ai2 difficulty is medium
    bool pressed = true;
    delete ai2_easy;
    delete ai2_medium;
    delete ai2_hard;

    return pressed;
}

bool MainWindow::ai2_hardpressed()
{
    //ai2 difficulty is hard
    bool pressed = true;
    delete ai2_easy;
    delete ai2_medium;
    delete ai2_hard;

    return pressed;
}
