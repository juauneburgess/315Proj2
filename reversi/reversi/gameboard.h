#include <iostream>

using namespace std;
class GameBoard{

public:
	char board[8][8];
	char curColor;

	GameBoard(); // construtor (setup board)
	void display();
	bool move(char column, int row);
	bool move(int row, int column);

	
	void showNextPos();

};

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
}


void GameBoard :: display(){
	cout<<"  _ _ _ _ _ _ _ _ \n";
	for(int i=0; i<8 ; i++){
		cout<<i+1;
		for (int j=0; j<8; j++){
			if(j==7){
				cout<<'|'<<board[i][j]<<'|';
			}else cout<<'|'<<board[i][j];
		}
		cout<<endl;
	}
	cout<<"  a b c d e f g h\n";		
}
bool GameBoard :: move(int row, int column){
	if(curColor == 'O'){
		board[row][column] = 'O';
		curColor = '@';
	}else{
		board[row][column] = '@';
		curColor = 'O';
	}
	return true;
}

bool GameBoard :: move(char _column, int _row){

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

