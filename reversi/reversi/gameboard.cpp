#pragma once

#include "gameboard.h"


GameBoard :: GameBoard(){
	for(int i=0; i<8 ; i++){
		for (int j=0; j<8; j++){
			board[i][j] = '_';
		}
	}
	board[3][3] = 'O';
	board[3][4] = '@';
	board[4][3] = '@';
	board[4][4] = 'O';

	curColor='O';
	saveCurrBoard();
}

GameBoard& GameBoard :: getCurrBoard(){
	GameBoard tempBoard;
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			tempBoard.board[i][j] = board[i][j];
		}
	}
			
	tempBoard.curColor = curColor;
	
	return tempBoard;
}

vector<int> GameBoard :: getMoves()
{
	display_valid_moves();
	vector<int> possible_moves;
	for(int i = 0; i < moves.size(); i++){
		possible_moves.push_back(moves[i]);
	}
	moves.clear();
	clear_possible_moves();
	return possible_moves;
}

vector<string> GameBoard :: display(){//*********
	display_valid_moves();
	stringstream ss;
	vector<string> output;
	ss << "\n\nCurrent player is '" << curColor << "'\n\n"; 
	ss<<"  _ _ _ _ _ _ _ _ \n";
	for(int i=0; i<8 ; i++){
		ss<<i+1;
		for (int j=0; j<8; j++){
			if(j==7){
				ss<<'|'<<board[i][j]<<'|';
			}else ss<<'|'<<board[i][j];
		}
		ss<<endl;
	}
	moves.clear();
	clear_possible_moves();	
	output.push_back(ss.str());
	output.push_back("  a b c d e f g h\n\n");	
	return output;
}

bool GameBoard :: move(int row, int column){
	saveCurrBoard();
	//copyBoard(board, undoboard);
	if(curColor == 'O'){
		board[row][column] = 'O';
		flipColor(row, column);
		curColor = '@';
	}else{
		board[row][column] = '@';
		flipColor(row, column);
		curColor = 'O';		
	}
	moves.clear();
	clear_possible_moves();	
	return true;
}

bool GameBoard :: move(char _column, int _row){
	display_valid_moves();
	int row = _row - 1;
	int col;
	if(_column == 'a')
		col = 0;
	if(_column == 'b')
		col = 1;
	if(_column == 'c')
		col = 2;
	if(_column == 'd')
		col = 3;
	if(_column == 'e')
		col = 4;
	if(_column == 'f')
		col = 5;
	if(_column == 'g')
		col = 6;
	if(_column == 'h')
		col = 7;

	move(row, col);

	return true;
}

void GameBoard :: flipColor(int row, int col){
	
	char opponent;
	if(curColor == '@'){
		opponent = 'O';
	}else if(curColor == 'O'){
		opponent = '@';
	}

	// going LEFT
	int i = col;
	while(board[row][--i] == opponent && i>0){ // check boundaries
		if(board[row][i-1] == curColor){
			// flip from i -> col-1;
			for(int j = i; j < col; j++){
				board[row][j] = curColor;
			}
		}
	}

	// going RIGHT
	i = col;
	while(board[row][++i] == opponent && i<7){
		if(board[row][i+1] == curColor){
			// flip from col+1 -> i-1;
			for(int j = col+1 ; j <= i; j++){
				board[row][j] = curColor;
			}
		}
	}
	
	// going UP
	i = row;
	while(board[--i][col] == opponent && i>0){
		if(board[i-1][col] == curColor){
			// flip from row-1 -> i;
			for(int j = row-1 ; j >= i; j--){
				board[j][col] = curColor;
			}
		}
	}

	// going DOWN
	i = row;
	while(board[++i][col] == opponent && i<7){
		if(board[i+1][col] == curColor){
			// flip from row+1 -> i;
			for(int j = row+1 ; j <= i; j++){
				board[j][col] = curColor;
			}
		}
	}

	// going UP LEFT
	i = row;
	int j = col;
	while(board[--i][--j] == opponent && i>0 && j>0){
		if(board[i-1][j-1] == curColor){
			// flip from row-1,col-1 -> i,j;
			for(int k = row-1, l = col-1 ; k >= i, l >=j; k--,l--){
				board[k][l] = curColor;
			}
		}
	}

	// going UP RIGHT
	i = row;
	j = col;
	while(board[--i][++j] == opponent && i>0 && j<7){
		if(board[i-1][j+1] == curColor){
			// flip from row-1,col+1 -> i,j;
			for(int k = row-1, l = col+1 ; k >= i, l <=j; k--,l++){
				board[k][l] = curColor;
			}
		}
	}

	// going DOWN LEFT
	i = row;
	j = col;
	while(board[++i][--j] == opponent && i<7 && j>0){
		if(board[i+1][j-1] == curColor){
			// flip from row+1,col-1 -> i,j;
			for(int k = row+1, l = col-1 ; k <= i, l >=j; k++,l--){
				board[k][l] = curColor;
			}
		}
	}


	// going DOWN RIGHT
	i = row;
	j = col;
	while(board[++i][++j] == opponent && i<7 && j<7){
		if(board[i+1][j+1] == curColor){
			// flip from row+1,col+1 -> i,j;
			for(int k = row+1, l = col+1 ; k <= i, l <=j; k++,l++){
				board[k][l] = curColor;
			}
		}
	}

}

void GameBoard:: copyBoard(char srcBoard[8][8], char destBoard[8][8])
{
	for(int i=0; i<8; i++)
	{
		for(short j=0; j<8; j++)
		{
			destBoard[i][j] = srcBoard[i][j];
		}
	}
}

void GameBoard :: saveCurrBoard(){

	char** tempBoard = new char*;

	for(int i=0; i< 8; i++){
		tempBoard[i] = new char[8];
	}
	
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			tempBoard[i][j] = board[i][j];
		}
	}

	undoboards.push(tempBoard);	

	/*cout<<"======UNDO BOARD ====\n";
	cout<<"  _ _ _ _ _ _ _ _ \n";
	for(int i=0; i<8 ; i++){
		cout<<i+1;
		for (int j=0; j<8; j++){
			if(j==7){
				cout<<'|'<<undoboards.top()[i][j]<<'|';
			}else cout<<'|'<<undoboards.top()[i][j];
		}
		cout<<endl;
	}
	cout<<"  a b c d e f g h\n";*/

	/*for(int i = 0; i < 8; i++) {
		delete [] tempBoard[i];
	}
	
	delete [] tempBoard;*/
	
}

void GameBoard :: undo(){	
	
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			board[i][j] = undoboards.top()[i][j];
		}
	}

	undoboards.pop();

	if(curColor=='@') curColor='O';
	else curColor='@';
	display();
}

/*This function checks if any moves are available
 *and if none are available the turn is forfeited*/
bool GameBoard :: skip_turn()
{
	if(display_valid_moves()==false)
	{
		//cout << "No valid moves available, your turn is forfeited.\n\n";
		if(curColor=='@') curColor='O';
		else curColor='@';
		moves.clear();
		clear_possible_moves();	
		return false;
	}
	else{
		moves.clear();
		clear_possible_moves();	
		return true;
	}	
}

/*This function clears the previous possible moves so 
 *the next possible moves can be displayed correctly*/
void GameBoard :: clear_possible_moves()
{
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if(board[i][j]=='*')	//find all '*' and replace with '_'
			{
				board[i][j] = '_';
			}
		}
	}
}

/*This function checks all spaces above the current 
 *space until it finds the current player or '_'*/
bool GameBoard :: lookUp(int i, int j)
{
	if(i==0||board[i-1][j]==curColor||board[i-1][j]=='_'||board[i-1][j]=='*')
	{									//if space directly adjacent is the 
		return false;						//current player, a blank space or
	}									//already a possible move, exit
	for(i-=1; i >= 1; i--)				
	{									//if current player is found in this	
		if(board[i][j]==curColor||board[i][j]=='*'||i==-1)		//line, exit
		{
			return false;
		}
		else if (board[i][j]=='_')		//if line is all opposing players 
		{								//followed by a '_' display possible				
			board[i][j] = '*';			//move
			moves.push_back(j);
			moves.push_back(i);
			return true;
		}
	}
}

/*This function checks all spaces below the current 
 *space until it finds the current player or '_'*/
bool GameBoard :: lookDown(int i, int j)
{
	if(i==7||board[i+1][j]==curColor||board[i+1][j]=='_'||board[i+1][j]=='*')
	{
		return false;
	}
	for(i+=1; i <= 7; i++)
	{
		if(board[i][j]==curColor||board[i][j]=='*'||i==8)
		{
			return false;
		}
		else if (board[i][j]=='_')
		{
			board[i][j] = '*';
			moves.push_back(j);
			moves.push_back(i);
			return true;
		}
	}
}

/*This function checks all spaces to the left of current 
 *space until it finds the current player or '_'*/
bool GameBoard :: lookLeft(int i, int j)
{
	if(j==0||board[i][j-1]==curColor||board[i][j-1]=='_'||board[i][j-1]=='*')
	{
		return false;
	}
	for(j-=1; j >= 1; j--)
	{
		if(board[i][j]==curColor||board[i][j]=='*'||j==-1)
		{
			return false;
		}
		else if (board[i][j]=='_')
		{
			board[i][j] = '*';
			moves.push_back(j);
			moves.push_back(i);
			return true;
		}
	}
}

/*This function checks all spaces to the right of current 
 *space until it finds the current player or '_'*/
bool GameBoard :: lookRight(int i, int j)
{
	if(j==7||board[i][j+1]==curColor||board[i][j+1]=='_'||board[i][j+1]=='*')
	{
		return false;
	}
	for(j+=1; j <= 8; j++)
	{
		if(board[i][j]==curColor||board[i][j]=='*'||j==8)
		{
			return false;
		}
		else if (board[i][j]=='_')
		{
			board[i][j] = '*';
			moves.push_back(j);
			moves.push_back(i);
			return true;
		}
	}
}

/*This function checks all spaces diagonally up and left 
 *of current space until it finds the current player or '_'*/
bool GameBoard :: lookUpLeft(int i, int j)
{
	int tempi = i;
	int tempj = j;
	if(i==0||j==0||board[i-1][j-1]==curColor||board[i-1][j-1]=='_'||board[i-1][j-1]=='*')
	{
		return false;
	}
	for(j -= 1; j >= -1; j--)
	{
		for(i -= 1; i >= -1; i--)
		{
			if((i == tempi-1) && (j == tempj-1))
			{	
				if(board[i][j]==curColor||board[i][j]=='*'||i==-1||j==-1)
				{
					return false;
				}
				else if (board[i][j]=='_')
				{
					board[i][j] = '*';
					moves.push_back(j);
					moves.push_back(i);
					return true;
				}
				tempi = i;
				tempj = j;
			}
		}
		i = tempi;
	}
}

/*This function checks all spaces diagonally up and right 
 *of current space until it finds the current player or '_'*/
bool GameBoard :: lookUpRight(int i, int j)
{
	int tempi = i;
	int tempj = j;
	if(i==0||j==7||board[i-1][j+1]==curColor||board[i-1][j+1]=='_'||board[i-1][j+1]=='*')
	{
		return false;
	}
	for(j += 1; j <= 8; j++)
	{
		for(i -= 1; i >= -1; i--)
		{
			if((i == tempi-1) && (j == tempj+1))
			{
				if(board[i][j]==curColor||board[i][j]=='*'||i==-1||j==8)
				{
					return false;
				}
				else if (board[i][j]=='_')
				{
					board[i][j] = '*';
					moves.push_back(j);
					moves.push_back(i);
					return true;
				}
				tempi = i;
				tempj = j;
			}
		}
		i = tempi;
	}
}

/*This function checks all spaces diagonally down and left 
 *of current space until it finds the current player or '_'*/
bool GameBoard :: lookDownLeft(int i, int j)
{
	int tempi = i;
	int tempj = j;
	if(i==7||j==0||board[i+1][j-1]==curColor||board[i+1][j-1]=='_'||board[i+1][j-1]=='*'||((j==1)||(i==7)))
	{
		return false;
	}
	for(j -= 1; j >= -1; j--)
	{
		for(i += 1; i <= 8; i++)
		{
			if((i == tempi+1) && (j == tempj-1))
			{
				if(board[i][j]==curColor||board[i][j]=='*'||i==8||j==-1)
				{
					return false;
				}
				else if (board[i][j]=='_')
				{
					board[i][j] = '*';
					moves.push_back(j);
					moves.push_back(i);
					return true;
				}
				tempi = i;
				tempj = j;
			}
		}
		i = tempi;
	}
}

/*This function checks all spaces diagonally down and right 
 *of current space until it finds the current player or '_'*/
bool GameBoard :: lookDownRight(int i, int j)
{
	int tempi = i;
	int tempj = j;
	if(i==7||j==7||board[i+1][j+1]==curColor||board[i+1][j+1]=='_'||board[i+1][j+1]=='*'||((j==7)||(i==7)))
	{
		return false;
	}
	for(j += 1; j <= 8; j++)
	{
		for(i += 1; i <= 8; i++)
		{
			if((i == tempi+1) && (j == tempj+1))
			{
				if(board[i][j]==curColor||board[i][j]=='*'||i==8||j==8)
				{
					return false;
				}
				else if (board[i][j]=='_')
				{
					board[i][j] = '*';
					moves.push_back(j);
					moves.push_back(i);
					return true;
				}
				tempi = i;
				tempj = j;
			}
		}
		i = tempi;
	}
}

/*This function checks in all 8 directions from every
 *space occupied by the current player and determines
 *each space examined as a valid move or not*/
bool GameBoard :: display_valid_moves(){
	bool up,down,left,right,upleft,upright,downleft,downright,valid;
	valid = false;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){			
			if(board[i][j] == curColor)		//check all spaces for current player
			{
				up = lookUp(i,j);
				down = lookDown(i,j);
				left = lookLeft(i,j);
				right = lookRight(i,j);
				upleft = lookUpLeft(i,j);
				upright = lookUpRight(i,j);
				downleft = lookDownLeft(i,j);
				downright = lookDownRight(i,j);
				if(up||down||right||left||upleft||upright||downleft||downright)
					valid = true;
			}
		}
	}
	/*cout << "Possible moves: \n";
	for(int k = 0; k < moves.size(); k+=2)
	{
		cout << moves[k] << " " << moves[k+1] << ", \n";
	}*/
	return valid;
}

/*This function uses the '*' placed by display_valid_moves()
 *as a marker for where a valid move is located and if a 
 *player tries to make a move to a space that is not marked
 *by a '*' the move is determined illegal*/
bool GameBoard :: valid_move(char _column, int _row){
	display_valid_moves();
	int row = _row - 1;
	int col = 0;
	if(_column == 'a')
		col = 0;
	if(_column == 'b')
		col = 1;
	if(_column == 'c')
		col = 2;
	if(_column == 'd')
		col = 3;
	if(_column == 'e')
		col = 4;
	if(_column == 'f')
		col = 5;
	if(_column == 'g')
		col = 6;
	if(_column == 'h')
		col = 7;
	cout<<board[col][row];
	if(board[row][col] == '*'){
		return true;
	}	
	else{
		moves.clear();
		clear_possible_moves();
		return false;
	}
}

/*This function goes through every tile on the board
 *and determines if it is white or black and keeps 
 *a tally of each color for scoring purposes. It also
 *adds up these scores to determine if the board is full*/
int GameBoard :: count_tiles()
{
	int whitetiles = 0;
	int blacktiles = 0;
	int fulltiles = 0;
	for(int i = 0; i <8; i++)
	{
		for(int j = 0; j <8; j++)
		{
			if(board[i][j]=='O')
				whitetiles++;
			if(board[i][j]=='@')
				blacktiles++;
		}
	}
	cout << "\n\nWhite: " << whitetiles << "	Black: " << blacktiles << "\n\n";
	fulltiles = whitetiles + blacktiles;
	return fulltiles;
}

/*This function uses the count from count_tiles and the
 *return value from display_valid_moves() to determine
 *if the game is over*/
bool GameBoard :: game_over(){
	if(!display_valid_moves() || count_tiles() == 64){//if no moves or board is full
		if(curColor=='@') curColor='O';
		else curColor='@';
		
		if(!display_valid_moves())
			return true;					 //end game
			
		if(curColor=='@') curColor='O';
		else curColor='@';	
	}
	moves.clear();
	clear_possible_moves();
	return false;
}

vector<string> GameBoard :: winner(){
	int countblack = 0;
	int countwhite = 0;
	stringstream ss;
	vector<string> output;
	for(int i=0; i<8; i++)
	{
		for(short j=0; j<8; j++)
		{
			if(board[i][j] == '@'){
				countblack++;
			}else if(board[i][j] == 'O'){
				countwhite++;
			}
		}
	}

	ss<<"Black: "<<countblack<<"\n";
	ss<<"White: "<<countwhite<<"\n";

	if(countblack < countwhite){
		ss<<"WHITE WIN!\n";
	}else if(countblack > countwhite){
		ss<<"BLACK WIN!\n";
	}else ss<<"DRAW!\n";
	output.push_back(ss.str());
	return output;
}
