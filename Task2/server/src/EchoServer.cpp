#include "echoServer.h"
void EchoServer::createNewClient(int fds){
    cout<<"new client connected : "<<endl;
    char buffer[1024];
    int bytesRead;

    while(true){
        if((bytesRead=recv(fds,buffer,sizeof(buffer),0))>0){
            cout<<"data recived from client : "<<buffer<<endl;
            send(fds,buffer,bytesRead,0);
        }
    }
    cout<<"client disconnected sucessfully : "<<fds<<endl;
    close(fds);
}
EchoServer::EchoServer(int port):TCPServer(port){}
EchoServer::~EchoServer(){}



