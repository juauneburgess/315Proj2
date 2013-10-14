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

	//copyBoard(board, undoboard);

	//GameBoard tempboard = *this;
	//undoBoards.push(&tempboard);

	//undoBoards.push(this);

	//undoboards.board.push(&this);

	//undoboards.board.push(getCurrBoard());
	//undoboards.push(getCurrBoard().board);
	
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
	cout<<"Next turn: "<< curColor <<endl;
}
bool GameBoard :: move(int row, int column){
	//if(move is valid)
	copyBoard(board, undoboard);
	if(curColor == 'O'){
		board[row][column] = 'O';
		flipColor(row, column);
		curColor = '@';

		//undoBoards.push(this);
		//GameBoard tempboard = *this;
		//undoBoards.push(&tempboard);

		//undoboards.board.push(getCurrBoard());

		//copyBoard(board, undoboard);

		display();
	}else{
		board[row][column] = '@';
		flipColor(row, column);
		curColor = 'O';

		//undoBoards.push(this);
		//GameBoard tempboard = *this;
		//undoBoards.push(&tempboard);

		//undoboards.board.push(getCurrBoard());

		//copyBoard(board, undoboard);
		display();
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

void GameBoard :: undo(){
	
	////*this = *undoBoards.top();
	//GameBoard lastBoard = undoboards.board.top();
	//
	//
	//for(int i=0; i<8; i++){
	//	for(int j=0; j<8; j++){
	//		board[i][j] = lastBoard.board[i][j];
	//	}
	//}
	//curColor = lastBoard.curColor;		
	//undoboards.board.pop();
	////undoBoards.pop();

	/*for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			board[i][j] = undoBoards.top()->board[i][j];
		}
	}
	curColor = undoBoards.top()->curColor;
	undoBoards.pop();*/

	copyBoard(undoboard, board);
	if(curColor=='@') curColor='O';
	else curColor='@';
	display();
}

void GameBoard :: winner(){
	int countblack = 0;
	int countwhite = 0;

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

	cout<<"Black: "<<countblack<<"\n";
	cout<<"White: "<<countwhite<<"\n";

	if(countblack < countwhite){
		cout<<"WHITE WIN!\n";
	}else if(countblack > countwhite){
		cout<<"BLACK WIN!\n";
	}else cout<<"DRAW!\n";

}
