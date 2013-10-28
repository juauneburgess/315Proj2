
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

GameServer::GameServer(const string _server_host_name, const unsigned short _port_no){
	//myside = CLIENT_SIDE;
	int my_socket;
	struct sockaddr_in serv_addr;
    struct hostent *server;
	
	if((my_socket = socket(AF_INET, SOCK_STREAM, 0))<0)
		error("error opening client socket");
	bzero((char *) &serv_addr, sizeof(serv_addr));
	if(inet_pton(AF_INET, _server_host_name.c_str(), &serv_addr.sin_addr)<=0)
		error("Host DNE");
	serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(_port_no);
	if ((connect(my_socket,(struct sockaddr *) &serv_addr,sizeof(serv_addr))) < 0) 
        error("ERROR connecting");
	client_wfd = my_socket;
	client_rfd = my_socket;
}

GameServer::GameServer(const int socket_fd){
	client_wfd = socket_fd;
	client_rfd = socket_fd;
}

GameServer::~GameServer(){
	close(client_rfd);
}

string GameServer::client_read() {
  char buf[MAX_MESSAGE];
  if (read(client_rfd, buf, MAX_MESSAGE) < 0) {
    perror(string("Request Channel : Error reading from pipe!").c_str());
  }
  string s = buf;
  return s;
}

int GameServer::client_write(string _msg) {
  if (_msg.length() >= MAX_MESSAGE) {
    cerr << "Message too long for Channel!\n";
    return -1;
  }
  const char * s = _msg.c_str();
  if (write(client_wfd, s, strlen(s)+1) < 0) {
    perror(string("Request Channel : Error writing to pipe!").c_str());
  }
}