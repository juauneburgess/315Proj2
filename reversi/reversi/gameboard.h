#pragma once

#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <string>

using namespace std;
class GameBoard{

public:
	char board[8][8];
	char curColor;
	vector<int> moves;

	GameBoard(); // construtor (setup board)
	vector<string> display();
	bool move(char column, int row);
	bool move(int row, int column);
	bool valid_move(char _column, int row);				//returns 1 if move is legal
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

	char undoboard[8][8];
	void copyBoard(char srcBoard[8][8], char destBoard[8][8]);
	void undo(); // can only undo 1 level
	
	GameBoard& getCurrBoard();
	vector<string> winner();

};
