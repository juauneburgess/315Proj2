#include "gameboard.h"

using namespace std;

int main(){
	GameBoard board;
	board.display();
	cout<< endl;
	board.move('e',3);
	board.clear_possible_moves();
	board.display();
	board.move('d',6);
	board.display();

	//char t; 
	//cin>> t;
	return 0;
}
