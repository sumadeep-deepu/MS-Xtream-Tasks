#include "echoClient.h"
int main(){
	EchoClient client("127.0.0.1",12345);
	client.runClient();
	return 0;
}


