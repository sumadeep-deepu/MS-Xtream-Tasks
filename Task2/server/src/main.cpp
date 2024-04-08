#include "echoServer.h"
int main(){
	EchoServer server(12345);
	while(true){
		server.acceptClientConnection();
	}
	return 0;
}
