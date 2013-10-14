#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
class GameBoard{

public:
	char board[8][8];
	char curColor;

	GameBoard(); // construtor (setup board)
	void display();
	bool move(char column, int row);
	bool move(int row, int column);
	bool valid_move(int column, int row);				//returns 1 if move is legal
	bool display_valid_moves();		//displays all legal moves
	void game_over();				//checks termination conditions
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
	void skip_turn();
	
	char undoboard[8][8];
	void copyBoard(char srcBoard[8][8], char destBoard[8][8]);
	void undo(); // can only undo 1 level
	
	GameBoard& getCurrBoard();
	void winner();

};










/*This function checks if any moves are available
 *and if none are available the turn is forfeited*/
void GameBoard :: skip_turn()
{
	if(display_valid_moves()==false)
	{
		cout << "No valid moves available, your turn is forfeited.\n\n";
		curColor = !curColor;
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
	bool upmove;
	if(board[i-1][j]==curColor||board[i-1][j]=='_'||board[i-1][j]=='*')
	{									//if space directly adjacent is the 
		upmove = false;					//current player, a blank space or
		return 0;						//already a possible move, exit
	}
	for(i-=1; i >= 0; i--)				//if current player is found in this
	{									//line, exit
		if(board[i][j]==curColor)
		{
			upmove = false;
			return 0;
		}
		else if (board[i][j]=='_')		//if line is all opposing players 
		{								//followed by a '_' display possible
			upmove = true;				//move
			board[i][j] = '*';
			return 1;
		}
	}
}

/*This function checks all spaces below the current 
 *space until it finds the current player or '_'*/
bool GameBoard :: lookDown(int i, int j)
{
	bool downmove;
	if(board[i+1][j]==curColor||board[i+1][j]=='_'||board[i+1][j]=='*')
	{
		downmove = false;
		return 0;
	}
	for(i+=1; i <= 8; i++)
	{
		if(board[i][j]==curColor)
		{
			downmove = false;
			return 0;
		}
		else if (board[i][j]=='_')
		{
			downmove = true;
			board[i][j] = '*';
			return 1;
		}
	}
}

/*This function checks all spaces to the left of current 
 *space until it finds the current player or '_'*/
bool GameBoard :: lookLeft(int i, int j)
{
	bool leftmove;
	if(board[i][j-1]==curColor||board[i][j-1]=='_'||board[i][j-1]=='*')
	{
		leftmove = false;
		return 0;
	}
	for(j-=1; j >= 0; j--)
	{
		if(board[i][j]==curColor)
		{
			leftmove = false;
			return 0;
		}
		else if (board[i][j]=='_')
		{
			leftmove = true;
			board[i][j] = '*';
			return 1;
		}
	}
}

/*This function checks all spaces to the right of current 
 *space until it finds the current player or '_'*/
bool GameBoard :: lookRight(int i, int j)
{
	bool rightmove;
	if(board[i][j+1]==curColor||board[i][j+1]=='_'||board[i][j+1]=='*')
	{
		rightmove = false;
		return 0;
	}
	for(j+=1; j <= 8; j++)
	{
		if(board[i][j]==curColor)
		{
			rightmove = false;
			return 0;
		}
		else if (board[i][j]=='_')
		{
			rightmove = true;
			board[i][j] = '*';
			return 1;
		}
	}
}

/*This function checks all spaces diagonally up and left 
 *of current space until it finds the current player or '_'*/
bool GameBoard :: lookUpLeft(int i, int j)
{
	bool upleftmove;
	if(board[i-1][j-1]==curColor||board[i-1][j-1]=='_'||board[i-1][j-1]=='*')
	{
		upleftmove = false;
		return 0;
	}
	for(i -= 1; i >= 0; i--)
	{
		for(j -= 1; j >= 0; j--)
		{
			if((i-=1) && (j-=1))
			{
				if(board[i][j]==curColor)
				{
					upleftmove = false;
					return 0;
				}
				else if (board[i][j]=='_')
				{
					upleftmove = true;
					board[i][j] = '*';
					return 1;
				}
			}
		}
	}
}

/*This function checks all spaces diagonally up and right 
 *of current space until it finds the current player or '_'*/
bool GameBoard :: lookUpRight(int i, int j)
{
	bool uprightmove;
	if(board[i-1][j+1]==curColor||board[i-1][j+1]=='_'||board[i-1][j+1]=='*')
	{
		uprightmove = false;
		return 0;
	}
	for(i -= 1; i >= 0; i--)
	{
		for(j += 1; j <= 8; j++)
		{
			if((i-=1) && (j+=1))
			{
				if(board[i][j]==curColor)
				{
					uprightmove = false;
					return 0;
				}
				else if (board[i][j]=='_')
				{
					uprightmove = true;
					board[i][j] = '*';
					return 1;
				}
			}
		}
	}
}

/*This function checks all spaces diagonally down and left 
 *of current space until it finds the current player or '_'*/
bool GameBoard :: lookDownLeft(int i, int j)
{
	bool downleftmove;
	if(board[i+1][j-1]==curColor||board[i+1][j-1]=='_'||board[i+1][j-1]=='*')
	{
		downleftmove = false;
		return 0;
	}
	for(i += 1; i <= 8; i++)
	{
		for(j -= 1; j >= 0; j--)
		{
			if((i+=1) && (j-=1))
			{
				if(board[i][j]==curColor)
				{
					downleftmove = false;
					return 0;
				}
				else if (board[i][j]=='_')
				{
					downleftmove = true;
					board[i][j] = '*';
					return 1;
				}
			}
		}
	}
}

/*This function checks all spaces diagonally down and right 
 *of current space until it finds the current player or '_'*/
bool GameBoard :: lookDownRight(int i, int j)
{
	if(board[i+1][j+1]==curColor||board[i+1][j+1]=='_'||board[i+1][j+1]=='*')
	{
		return false;
	}
	for(i += 1; i <= 8; i++)
	{
		for(j += 1; j <= 8; j++)
		{
			if((i+=1) && (j+=1))
			{
				if(board[i][j]==curColor)
				{
					return false;
				}
				else if (board[i][j]=='_')
				{
					board[i][j] = '*';
					return true;
				}
			}
		}
	}
}

/*This function checks in all 8 directions from every
 *space occupied by the current player and determines
 *each space examined as a valid move or not*/
bool GameBoard :: display_valid_moves(){
	bool up,down,left,right,upleft,upright,downleft,downright,valid;
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
	return valid;
}

/*This function uses the '*' placed by display_valid_moves()
 *as a marker for where a valid move is located and if a 
 *player tries to make a move to a space that is not marked
 *by a '*' the move is determined illegal*/
bool GameBoard :: valid_move(int column, int row){
	if(board[row][column] == '*')
		return true;
	else{
		cout << "Illegal move, try again.\n";
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
	for(int i = 0; i <=8; i++)
	{
		for(int j = 0; j <=8; j++)
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
void GameBoard :: game_over(){
	if(!display_valid_moves() || count_tiles() == 64)//if no moves or board is full
		cout << "game over\n\n";					 //end game
}


