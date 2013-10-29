#ifndef _game_server_h_                   // include file only once
#define _game_server_h_  

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>


using namespace std;

class GameServer{

private:
	
	int wfd;
	int rfd;
	int client_wfd;
	int client_rfd;
	static const int MAX_MESSAGE = 255;
	
public:

	void error(string s);

	GameServer(const unsigned short _port_no, void * (*connection_handler) (int *));
	//Server protocol for setting up the socket
	
	GameServer(const string _server_host_name, const unsigned short _port_no);
	//Protocol for server to connect to another server as a client
	
	GameServer(const int socket_fd);	
	//Sets file descriptors for reading and writing to the socket
	
	~GameServer();
	// Destructor of local copy of channel
	
	string cread();
	//read from socket as server
	
	int cwrite(string _msg);
	//write to socket as server
	
	string client_read();
	//read from socket as client
	
	int client_write(string _msg);
	//write to socket as client
	
	//void* handleConnection(int *socket_fd);
};

#endif