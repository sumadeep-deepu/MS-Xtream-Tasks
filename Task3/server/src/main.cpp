#include<multipleServer.h>
int main(){
	Server server(12345);
	while(true){
		server.acceptClientConnection();
	}
	return 0;
}

