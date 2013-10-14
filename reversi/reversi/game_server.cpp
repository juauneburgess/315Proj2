
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
#include "ai_engine.h"

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
	bool check = true;
	bool display = false;
	bool condition = false;
	bool player_skip = false;
	int count = 0;
	vector<int> possible_moves;
	vector<int> move;
	string playerColor;
	string request;
	char str [5];
	string ai_move = "";
	GameBoard board;
	AIEngine ai;
	vector<string> output;
	slave.cwrite("\nWELCOME \n");
	while(check){
		string word;
		if(!board.skip_turn()){
			player_skip = true;
		}
		else{
			request = slave.cread();
			istringstream oss(request);
			oss >> word;
		}	
		if(word == "WHITE" && !condition){
			count++;
			playerColor = "WHITE";
			slave.cwrite("OK \n");
		}
		if(word == "BLACK" && !condition){
			count++;
			playerColor = "BLACK";
			slave.cwrite("OK \n");
		}
		else if(word == "HUMAN-AI"&& !condition){
			count++;
			slave.cwrite("OK \n");
		}
		else if(word == "EASY" || word == "MEDIUM" || word == "HARD" && !condition){
			count++;
			slave.cwrite("OK \n");
		}
		else if(word == "DISPLAY"){
			if(display)
				display = false;
			else
				display = true;
			slave.cwrite("OK \n");
		}
		else if(word.size() == 2 && condition){
			char c = word[1];
			int row = c - 48;
			if(!board.valid_move(word[0], row) && !player_skip)
				slave.cwrite("ILLEGAL");
			else if(player_skip){
				slave.cwrite("You have no moves, it will be the AI's turn now ");
				possible_moves = board.getMoves();
				if(possible_moves.size()==0){
					slave.cwrite("AI has no moves, the game will end");
					
				}
				else{
					move = ai.MakeMove(possible_moves);
					board.move(move[1], move[0]);
					char col;
					if(move[0] == 0)
						col = 'a';
					else if(move[0] == 1)
						col = 'b';
					else if(move[0] == 2)
						col = 'c';
					else if(move[0] == 3)
						col = 'd';
					else if(move[0] == 4)
						col = 'e';
					else if(move[0] == 5)
						col = 'f';
					else if(move[0] == 6)
						col = 'g';
					else if(move[0] == 7)
						col = 'h';
					ai_move+= col;
					sprintf(str, "%d" ,move[1]+1);
					ai_move+= str;
					slave.cwrite(ai_move);
					ai_move = "";
				}
				player_skip = false;
			}	
			else{
				board.move(word[0], row);
				slave.cwrite("OK \n");
				possible_moves = board.getMoves();
				if(possible_moves.size()==0){
					slave.cwrite("AI has no moves, it will be your turn now ");
					board.skip_turn();
				}
				else{
					move = ai.MakeMove(possible_moves);
					board.move(move[1], move[0]);
					char col;
					if(move[0] == 0)
						col = 'a';
					else if(move[0] == 1)
						col = 'b';
					else if(move[0] == 2)
						col = 'c';
					else if(move[0] == 3)
						col = 'd';
					else if(move[0] == 4)
						col = 'e';
					else if(move[0] == 5)
						col = 'f';
					else if(move[0] == 6)
						col = 'g';
					else if(move[0] == 7)
						col = 'h';
					ai_move+= col;
					sprintf(str, "%d" ,move[1]+1);
					ai_move+= str;
					slave.cwrite(ai_move);
					ai_move = "";
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
				possible_moves = board.getMoves();
				move = ai.MakeMove(possible_moves);
				board.move(move[1], move[0]);
				char col;
				if(move[0] == 0)
					col = 'a';
				else if(move[0] == 1)
					col = 'b';
				else if(move[0] == 2)
					col = 'c';
				else if(move[0] == 3)
					col = 'd';
				else if(move[0] == 4)
					col = 'e';
				else if(move[0] == 5)
					col = 'f';
				else if(move[0] == 6)
					col = 'g';
				else if(move[0] == 7)
					col = 'h';
				ai_move+= col;
				int num = move[1]+1;
				sprintf(str, "%d" , num);
				ai_move+= str;
				slave.cwrite(ai_move);
				ai_move = "";
			}
		}
		if(display){
			output = board.display();
			for(int i = 0; i < output.size() ; i++)
			slave.cwrite(output[i]);
		}
		if(board.game_over()){
			cout<<"check";
			vector<string> winner_statement;
			winner_statement = board.winner();
			for(int i = 0; i < winner_statement.size() ; i++)
				slave.cwrite(winner_statement[i]);
			check = false;
		}
	}
	
}

int main(){
	GameServer channel(5001, &handleConnection);
}
