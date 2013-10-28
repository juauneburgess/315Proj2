#pragma once

#include <stdio.h>   
#include <stdlib.h>    
#include <time.h> 
#include <string>
#include <vector>
#include <iostream>
#include "gameboard.h"

using namespace std;

class Bestmove{
public:
	Move move;
	double score;
	Bestmove(){
		move.row = 0;
		move.col = 0;
		score = 0;
	}

};

class AI{
private:
	
	int difficulty;
	char ai_color;
	char player_color;
	
public:

	AI();
	
	void set_difficulty(int diff){difficulty = diff;};
	void set_ai_color(char _aicolor, char _playercolor){ai_color = _aicolor; player_color = _playercolor;};
	vector<int> MakeMove(vector<int> possible_moves);
	//Bestmove chooseMove(GameBoard, bool player, int level);
	Bestmove aiMove(GameBoard);
	Bestmove chooseMove(GameBoard, char player, int level);
	Bestmove move(GameBoard);

};
