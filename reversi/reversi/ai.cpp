#include "ai.h"

AI :: AI(){
	srand(time(NULL));
}

vector<int> AI :: MakeMove(vector<int> possible_moves){
	vector<int> move;
	int rand_num = rand() % (possible_moves.size()/2);
	cout<<rand_num << "\n";
	move.push_back(possible_moves[rand_num*2]);
	move.push_back(possible_moves[rand_num*2+1]);
	cout<<move[0] << " " << move[1];
	return move;
}

//Bestmove AI :: chooseMove(GameBoard currBoard, bool AIplayer, int level){
//	Bestmove mybest; // my best move
//	Bestmove reply;	// opponent's best move
//	if(level == 0 || currBoard.game_over()){ // if level == 0 or board is full
//		mybest.score = currBoard.evaluateMove(mybest.move.row,mybest.move.col);
//		return mybest; // return a best with score, no move
//	}
//
//	if(AIplayer){
//		mybest.score = -9999;
//	}else{
//		mybest.score = 9999;
//	}
//	if(AIplayer){// AI's turn
//
//		//if (currBoard.getValidMoves().size() == 0)
//		for(int i=0; i< currBoard.getValidMoves().size(); i++) //for each Move m in currBoard.possibleMoves
//		{
//			Move move;
//			move = currBoard.getValidMoves()[i];			
//
//			currBoard.move(move.row, move.col); // perform move
//			reply = chooseMove(currBoard, !AIplayer, level-1);
//			currBoard.undo(); // undo move
//			//currBoard.undo();
//			if(reply.score> mybest.score){
//				mybest.move = move;
//				mybest.score = reply.score;
//			}
//		}
//	}else{// optimal human's turn
//		for(int i=0; i< currBoard.getValidMoves().size(); i++)
//		{
//			Move move;
//			move = currBoard.getValidMoves()[i];			
//
//			currBoard.move(move.row, move.col);// perform move
//			reply = chooseMove(currBoard, AIplayer , level-1);
//			currBoard.undo(); // undo move
//			//currBoard.undo(); 
//			if(reply.score < mybest.score){
//				mybest.move = move;
//				mybest.score = reply.score;
//			}
//		}
//	}
//
//	return mybest;
//
//
//}

Bestmove AI :: aiMove(GameBoard currboard){
	Bestmove choosenMove;
	choosenMove = chooseMove(currboard, ai_color, difficulty);
	return choosenMove;
}

Bestmove AI :: chooseMove(GameBoard currBoard, char player, int level){
	Bestmove mybest; // my best move
	Bestmove reply;	// opponent's best move
	if(level == 0){ //|| currBoard.game_over()){ if level == 0 or board is full
		mybest.score = currBoard.evaluateMove(mybest.move.row,mybest.move.col);
		return mybest; // return a best with score, no move
	}
	if(currBoard.getValidMoves().size() == 0 && player == ai_color){
		mybest.score = 9998;
		return mybest;
	}
	if(currBoard.getValidMoves().size() == 0 && player != ai_color){
		mybest.score = -9998;
		return mybest;
	}

	if(player == ai_color){
		mybest.score = -9999;
	}else{
		mybest.score = 9999;
	}
	if(player == ai_color){// AI's turn

		//if (currBoard.getValidMoves().size() == 0)
		for(int i=0; i< currBoard.getValidMoves().size(); i++) //for each Move m in currBoard.possibleMoves
		{
			Move move;
			move = currBoard.getValidMoves()[i];			

			currBoard.move(move.row, move.col); // perform move
			reply = chooseMove(currBoard, 'O', level-1);
			currBoard.undo(); // undo move
			//currBoard.undo();
			if(reply.score> mybest.score){
				mybest.move = move;
				mybest.score = reply.score;
			}
		}
	}else{// optimal human's turn
		for(int i=0; i< currBoard.getValidMoves().size(); i++)
		{
			Move move;
			move = currBoard.getValidMoves()[i];			

			currBoard.move(move.row, move.col);// perform move
			reply = chooseMove(currBoard, '@' , level-1);
			currBoard.undo(); // undo move
			//currBoard.undo(); 
			if(reply.score < mybest.score){
				mybest.move = move;
				mybest.score = reply.score;
			}
		}
	}

	return mybest;


}


Bestmove AI :: move(GameBoard currBoard){
	Bestmove mybest;
	cout<<"\n";
	mybest.score = -9999;
	for(int i=0; i< currBoard.getValidMoves().size(); i++){
		Move move;
		move = currBoard.getValidMoves()[i];
		cout << move.col << move.row << "\n";
		double score = currBoard.evaluateMove(move.row,move.col);
		if(score > mybest.score){
			mybest.move = move;
			mybest.score = score;
		}
	}


	return mybest;
}