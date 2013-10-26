#include "ai_engine.h"

AIEngine::AIEngine(){
	srand(time(NULL));
}

vector<int> AIEngine::MakeMove(vector<int> possible_moves){
	vector<int> move;
	int rand_num = rand() % (possible_moves.size()/2);
	cout<<rand_num << "\n";
	move.push_back(possible_moves[rand_num*2]);
	move.push_back(possible_moves[rand_num*2+1]);
	cout<<move[0] << " " << move[1];
	return move;
}