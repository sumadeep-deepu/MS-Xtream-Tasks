#include "echoClient.h"

EchoClient::EchoClient(std::string ip, int port) : TCPClient(ip, port) {}

void EchoClient::runClient() {
    std::string msg;
    while (true) {
        cout << "Enter a message or (type 'exit' to exit): ";
        getline(std::cin, msg);
        if (msg == "exit") {
            break;
        }
        int bytesSent = sendData(msg);
        if (bytesSent > 0) {
            std::cout << "Message sent successfully" << std::endl;
            char buffer[1024];
            int bytesRead = recv(this->getDescriptor(), buffer, sizeof(buffer), 0);
            
            if (bytesRead > 0) {
                cout << "Received from server: " << buffer << endl;
            } else {
                cerr << "Error receiving response from server" << endl;
            }
        } else {
            cerr << "Error sending message" << endl;
        }
    }
}
EchoClient::~EchoClient() {}