
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#include "game_server.h"
#include "gameboard.h"
#include "ai.h"

void GameServer::error(string s){
	cout<<s<<"\n";
	exit(EXIT_FAILURE);
}

GameServer::GameServer(const unsigned short _port_no, void * (*connection_handler) (int *)){
	int socket_fd, new_fd;
	struct sockaddr_in serv_addr;
	int _backlog = 5;
	
	if((socket_fd = socket(AF_INET, SOCK_STREAM, 0))<0)
		error("error opening server socket");
	//memset(&serv_addr, 0, sizeof(struct sockaddr_in));
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family= AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(_port_no);
	
	if((bind(socket_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)))<0)
		error("bind error");
	
	listen(socket_fd, _backlog);
	
	for(;;){
		cout << "Waiting for new client connection \n";
		if((new_fd = accept(socket_fd, NULL, NULL))<0)
			error("accept error");
		else{
			connection_handler(&new_fd);
			close(new_fd);
			exit(0);
		}	
	}
}

GameServer::GameServer(const int socket_fd){
	wfd = socket_fd;
	rfd = socket_fd;
}

GameServer::~GameServer(){
	close(rfd);
}

string GameServer::cread() {
  char buf[MAX_MESSAGE];
  if (read(rfd, buf, MAX_MESSAGE) < 0) {
    perror(string("Request Channel : Error reading from pipe!").c_str());
  }
  string s = buf;
  return s;
}

int GameServer::cwrite(string _msg) {
  if (_msg.length() >= MAX_MESSAGE) {
    cerr << "Message too long for Channel!\n";
    return -1;
  }
  const char * s = _msg.c_str();
  if (write(wfd, s, strlen(s)+1) < 0) {
    perror(string("Request Channel : Error writing to pipe!").c_str());
  }
}

void* handleConnection(int *socket_fd){
	GameServer slave(*socket_fd);
	Bestmove ai_move;
	bool check = true;
	bool display = false;
	bool condition = false;
	bool player_skip = false;
	int count = 0;
	int undo_count = 0;
	vector<int> possible_moves;
	vector<int> move;
	string playerColor;
	char playerChar;
	char aiChar;
	string request;
	char str [5];
	string ai_move_output = "";
	GameBoard board;
	AI ai;
	vector<string> output;
	slave.cwrite("\nWELCOME \n");
	while(check){
		string word;
		if(!board.skip_turn()){
			player_skip = true;
			word = "i1";
		}
		else{
			request = slave.cread();
			istringstream oss(request);
			oss >> word;
		}	
		if(word == "WHITE" && !condition){
			count++;
			playerColor = "WHITE";
			playerChar = 'O';
			aiChar = '@';
			ai.set_ai_color(aiChar);
			slave.cwrite("OK \n");
		}
		if(word == "BLACK" && !condition){
			count++;
			playerColor = "BLACK";
			playerChar = '@';
			aiChar = 'O';
			ai.set_ai_color(aiChar);
			slave.cwrite("OK \n");
		}
		else if(word == "HUMAN-AI"&& !condition){
			count++;
			slave.cwrite("OK \n");
		}
		else if(word == "EASY" || word == "MEDIUM" || word == "HARD" && !condition){
			count++;
			if(word == "EASY"){
				ai.set_difficulty(1);
			}
			else if(word == "MEDIUM"){
				ai.set_difficulty(3);
			}
			else if(word == "HARD"){
				ai.set_difficulty(5);
			}
			slave.cwrite("OK \n");
		}
		else if(word == "DISPLAY"){
			if(display)
				display = false;
			else
				display = true;
			slave.cwrite("OK \n");
		}
		else if(word == "UNDO"){
			if(undo_count < 10 && board.undo_size() >1 && playerColor!="BLACK"){
				board.undo();
				board.undo();
				undo_count++;
			}
			else if(undo_count < 10 && board.undo_size() >2 && playerColor=="BLACK"){
				board.undo();
				board.undo();
				undo_count++;
			}
			else if(board.undo_size() <=1 && playerColor!="BLACK"){
				slave.cwrite("Not enough previous game states	\n");
			}
			else if(board.undo_size() <=2 && playerColor=="BLACK"){
				slave.cwrite("Not enough previous game states	\n");
			}
			else{
				slave.cwrite("You are out of Undo's \n");
			}
		}
		else if(word.size() == 2 && condition){
			char c = word[1];
			int row = c - 48;
			if(!board.valid_move(word[0], row) && !player_skip)
				slave.cwrite("ILLEGAL");
			else if(player_skip){
				slave.cwrite("You have no moves, it will be the AI's turn now ");
				//possible_moves = board.getMoves();
				if(board.countPossibleMove()==0){
					slave.cwrite("AI has no moves, the game will end");
					
				}
				else{
					ai_move = ai.aiMove(board);
					//board.move(move[1], move[0]);
					board.move(ai_move.move.row, ai_move.move.col);
					char col;
					if(ai_move.move.col== 0)
						col = 'a';
					else if(ai_move.move.col == 1)
						col = 'b';
					else if(ai_move.move.col == 2)
						col = 'c';
					else if(ai_move.move.col == 3)
						col = 'd';
					else if(ai_move.move.col == 4)
						col = 'e';
					else if(ai_move.move.col == 5)
						col = 'f';
					else if(ai_move.move.col == 6)
						col = 'g';
					else if(ai_move.move.col == 7)
						col = 'h';
					ai_move_output+= col;
					int num = ai_move.move.row+1;
					sprintf(str, "%d" , num);
					ai_move_output+= str;
					slave.cwrite(ai_move_output);
					ai_move_output = "";
				}
				player_skip = false;
			}	
			else{
				board.move(word[0], row);
				slave.cwrite("OK \n");
				if(board.countPossibleMove()==0){
					slave.cwrite("AI has no moves, it will be your turn now ");
					board.skip_turn();
				}
				else{
					ai_move = ai.aiMove(board);
					//board.move(move[1], move[0]);
					board.move(ai_move.move.row, ai_move.move.col);
					char col;
					if(ai_move.move.col== 0)
						col = 'a';
					else if(ai_move.move.col == 1)
						col = 'b';
					else if(ai_move.move.col == 2)
						col = 'c';
					else if(ai_move.move.col == 3)
						col = 'd';
					else if(ai_move.move.col == 4)
						col = 'e';
					else if(ai_move.move.col == 5)
						col = 'f';
					else if(ai_move.move.col == 6)
						col = 'g';
					else if(ai_move.move.col == 7)
						col = 'h';
					ai_move_output+= col;
					int num = ai_move.move.row+1;
					sprintf(str, "%d" , num);
					ai_move_output+= str;
					slave.cwrite(ai_move_output);
					ai_move_output = "";
				}	
			}
		}
		else if(word == "EXIT"){
			check = false;
		}
		if(count == 3){
			condition = true;
			count = 0;
			if(playerColor == "BLACK"){
				
				//possible_moves = board.getMoves();
				ai_move = ai.aiMove(board);
				//board.move(move[1], move[0]);
				board.move(ai_move.move.row, ai_move.move.col);
				char col;
				if(ai_move.move.col== 0)
					col = 'a';
				else if(ai_move.move.col == 1)
					col = 'b';
				else if(ai_move.move.col == 2)
					col = 'c';
				else if(ai_move.move.col == 3)
					col = 'd';
				else if(ai_move.move.col == 4)
					col = 'e';
				else if(ai_move.move.col == 5)
					col = 'f';
				else if(ai_move.move.col == 6)
					col = 'g';
				else if(ai_move.move.col == 7)
					col = 'h';
				ai_move_output+= col;
				int num = ai_move.move.row+1;
				sprintf(str, "%d" , num);
				ai_move_output+= str;
				slave.cwrite(ai_move_output);
				ai_move_output = "";
			}
		}
		if(display){
			output = board.display();
			for(int i = 0; i < output.size() ; i++)
			slave.cwrite(output[i]);
		}
		if(board.game_over()){
			vector<string> winner_statement;
			winner_statement = board.winner();
			for(int i = 0; i < winner_statement.size() ; i++)
				slave.cwrite(winner_statement[i]);
			check = false;
		}
	}
	
}

int main(){
	int port_no = 0;
	cout<<"Port Number for Server:: ";
	cin>> port_no;
	GameServer channel(port_no, &handleConnection);
}
