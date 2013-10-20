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
	
public:

	AI();
	
	vector<int> MakeMove(vector<int> possible_moves);
	//Bestmove chooseMove(GameBoard, bool player, int level);
	Bestmove chooseMove(GameBoard, char player, int level);
	Bestmove move(GameBoard);

};