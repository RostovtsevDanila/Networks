#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define ERROR_S "CLIENT ERROR: "
#define SERVER_IP "127.0.0.1"
#define DEFAULT_PORT 1275
#define BUFFER_SIZE 1024
#define SERVER_CLOSE_CONNECTION_SYMBOL '#'

using namespace std;

bool is_client_connection_close(const char msg[]);

int main(int argc, char *argv[])
{
	int client;
	int server;

	struct sockaddr_in server_address;

	client = socket(AF_INET, SOCK_STREAM, 0);
	if (client < 0) {
		::cout << ERROR_S << "esteblishing socket error." << endl;
		exit(0);
	}

	server_address.sin_port = htons(DEFAULT_PORT);
	server_address.sin_family = AF_INET;
	inet_pton(AF_INET, SERVER_IP, &server_address.sin_addr);

	cout << "\n=> Client socked created." << endl;

	int ret = connect(client, reinterpret_cast<const struct sockaddr*>(&server_address),
			sizeof(server_address));
	if (ret == 0) {
		cout << "Connection to server "
			 << inet_ntoa(server_address.sin_addr)
			 << "with number " << DEFAULT_PORT << endl;
	}

	cout << "Waiting for server connection..." << endl;

	char buffer[BUFFER_SIZE];

	recv(client, buffer, BUFFER_SIZE, 0);
	cout << "Connection established." << endl
		 << "Enter " << SERVER_CLOSE_CONNECTION_SYMBOL
		 << " for close the connection." << endl;

	while (true) {
		cout << "Client: ";
		cin.getline(buffer, BUFFER_SIZE);
		send(client, buffer, BUFFER_SIZE, 0);
		if(is_client_connection_close(buffer)) {
			break;
		}

		cout << "Server: ";
		recv(client, buffer, BUFFER_SIZE, 0);
		cout << buffer << endl;
		if(is_client_connection_close(buffer)) {
			break;
		}

	}
	close(client);
	cout << "\n GoodBye..." <<  endl;

	return 0;
}

bool is_client_connection_close(const char msg[])
{
	for (int i = 0; i < strlen(msg); ++i) {
		if (msg[i] == SERVER_CLOSE_CONNECTION_SYMBOL)
			return true;
	}
	return false;
}
