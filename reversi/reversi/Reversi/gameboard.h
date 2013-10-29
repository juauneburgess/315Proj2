#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#pragma once

#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <sstream>
#include <string>
//#include "mainwindow.h"
//#include "ui_mainwindow.h"

using namespace std;

struct Move{
    int row;
    int col;
};

class GameBoard {

public:
    char board[8][8];
    char curColor;
    vector<int> moves;
    stack<char**> undoboards;
    GameBoard(); // construtor (setup board)
    vector<string> display();
    bool move(char column, int row);
    bool move(int row, int column);
    bool valid_move(char _column, int row);				//returns 1 if move is legal
    bool valid_move(int row, int col);
    bool display_valid_moves();		//displays all legal moves
    bool game_over();				//checks termination conditions
    int count_tiles();				//counts white and black tiles and returns total tiles used
    void clear_possible_moves();	//clears last plays possible moves
    bool lookUp(int i, int j);		//checks  above space
    bool lookDown(int i, int j);	//checks below space
    bool lookLeft(int i, int j);	//checks left of space
    bool lookRight(int i, int j);	//checks right of space
    bool lookUpLeft(int i, int j);	//checks diagonally up and left of space
    bool lookUpRight(int i, int j);	//checks diagonally up and right of space
    bool lookDownLeft(int i, int j);	//checks diagonally down and left of space
    bool lookDownRight(int i, int j);	//checks diagonally down and right of space
    bool skip_turn();
    void flipColor(int row, int column);
    vector<int> getMoves();

    //char undoboard[8][8];
    void copyBoard(char srcBoard[8][8], char destBoard[8][8]);

    void saveCurrBoard();
    void undo();
    int undo_size();
    GameBoard& getCurrBoard();
    vector<string> winner();

    //===helper functions for AI===
    int countBlack();
    int countWhite();
    int countPossibleMove();
    bool isCorner(int row, int col);
    double evaluateMove(int row, int col); // return the score of a move
    double evaluateBoard(int row, int col);
    vector<Move> getValidMoves();
    //=============================
    //=======GUI client=========
    char getColor(int row, int col);
    void setColor(int row, int col, char _color);
/*
public slots:
     void updateBoard(){}

 signals:
     void valueChanged(int newValue);
*/

};

#endif // GAMEBOARD_H
