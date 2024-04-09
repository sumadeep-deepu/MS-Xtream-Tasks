#include<multipleServer.h>
void Server::handleClientMessege(int senderFd,string& messege){
	for(int clientfd:clientFds){
		if(clientfd!=senderFd){
			int bytesSent=send(clientfd,messege.c_str(),messege.length(),0);
			if(bytesSent<0){
				cout<<"error in sending messege"<<endl;
			}
		}
	}
}
void handleClient(Server* server,int fd){
	cout<<"new client connection established"<<fd<<endl;
	server->clientFds.insert(fd);

	char buffer[1024];
	ssize_t bytesRead;

	while(true){
		bytesRead=read(fd,buffer,sizeof(buffer));
		if(bytesRead>0){
			string messege(buffer,bytesRead);
			cout<<"messege recived from client : "<<messege<<endl;
			server->handleClientMessege(fd,messege);
		}
		else if(bytesRead==0){
			cout<<"client disconnected : " <<fd<<endl;
			server->clientFds.erase(fd);
			close(fd);
			break;
		}
		else{
			cout<<"error in recieving messege"<<endl;
			server->clientFds.erase(fd);
			close(fd);
			break;
		}

	}
}
void Server::createNewClient(int fd){
	thread t(handleClient,this,fd);
	t.detach();
}

Server::Server(int port):TCPServer(port){}
Server::~Server(){}
