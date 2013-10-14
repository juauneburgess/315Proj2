
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
	GameBoard board;
	vector<string> output;
	slave.cwrite("\nWELCOME \n");
	while(check){
		string word;
		string request = slave.cread();
		istringstream oss(request);
		oss >> word;
		if(word == "WHITE" || word == "BLACK"){
			//use color game mechanics
			slave.cwrite("OK \n");
		}
		else if(word == "HUMAN-AI"){
			//use game mechanics
			slave.cwrite("OK \n");
		}
		else if(word == "EASY" || word == "MEDIUM" || word == "HARD"){
			//use difficulty game mechanics
			slave.cwrite("OK \n");
		}
		else if(word == "DISPLAY"){
			if(display)
				display = false;
			else
				display = true;
			slave.cwrite("OK \n");
		}
		else if(word.size() == 2){
			char c = word[1];
			int row = c - 48;
			if(!board.valid_move(word[0], row))
				slave.cwrite("ILLEGAL");
			else{
				board.move(word[0], row);
				slave.cwrite("OK \n");
			}	
		}
		else if(word == "EXIT"){
			check = false;
		}
		if(display){
			output = board.display();
			for(int i = 0; i < output.size() ; i++)
			slave.cwrite(output[i]);
		}	
	}
	
}

int main(){
	GameServer channel(5001, &handleConnection);
}
