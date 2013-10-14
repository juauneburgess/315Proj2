#include "gameboard.h"

using namespace std;

int main(){
	GameBoard board;
	board.display();	
	cout<< endl;
	cout<<"Enter a move: ";
	while(1){ // just for testing
		char row;
		int col;
		cin>>row;
		cin>>col;
		board.move(row,col);
		cout<<"Enter a move: ";

	}
	

	char t; 
	cin>> t;
	return 0;
}