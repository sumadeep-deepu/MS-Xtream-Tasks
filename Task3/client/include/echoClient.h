#ifndef ECHO_CLIENT_H
#define ECHO_CLIENT_H
#include<iostream>
using namespace std;
#include<ubacipc/TCPClient.h>
class EchoClient:public UBACIPC::TCPClient{
	public:
		EchoClient(string ip,int port);
		~EchoClient();
		void runClient();
};
#endif
		
