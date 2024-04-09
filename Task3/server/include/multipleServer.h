#ifndef ECHO_SERVER_H
#define ECHO_SERVER_H
#include<ubacipc/TCPServer.h>
#include<iostream>
#include<thread>
#include<unordered_set>
using namespace std;

class Server:public UBACIPC::TCPServer{
	public:
		Server(int port);
		~Server();

		virtual void createNewClient(int fds) override;
		void handleClientMessege(int senderFd,std::string& messege);
		unordered_set<int> clientFds;
};
#endif
