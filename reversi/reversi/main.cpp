#include "gameboard.h"
#include "gameboard.cpp"

using namespace std;

int main(){
	GameBoard board;
	board.display();
	vector<int> valmoves;	
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
	/*board.getMoves().swap(valmoves);
	cout << valmoves.size() << "\n";
	for(int i = 0; i < valmoves.size(); i++)
	{
		cout << "\n\nMove: " << valmoves[i] << "\n\n";
	}*/

	char t; 
	cin>> t;
	return 0;
}