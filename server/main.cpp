#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define ERROR_S "SERVER ERROR: "
#define DEFAULT_PORT 1275
#define BUFFER_SIZE 1024
#define CLIENT_CLOSE_CONNECTION_SYMBOL '#'

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

	cout << "SERVER: Socket for server was successfully created. \n";

	server_address.sin_port = htons(DEFAULT_PORT);
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htons(INADDR_ANY);

	int ret = bind(client, reinterpret_cast<struct sockaddr*>(&server_address),
				   sizeof(server_address));

	if (ret < 0) {
		cout << ERROR_S << "binding connection. Socket has already been esteblishing. \n";
		return -1;
	}

	socklen_t size = sizeof(server_address);
	cout << "SERVER: " << "Listning clients...\n";

	listen(client, 1);

	server = accept(client, reinterpret_cast<struct sockaddr*>(&server_address), &size);
	if (server < 0) {
		cout << ERROR_S << "Can't accepting client. \n";
	}

	char buffer[BUFFER_SIZE];
	bool isExit = false;

	while(server > 0) {
		strcpy(buffer, "=> Server connected\n");
		send(server, buffer, BUFFER_SIZE, 0);
		cout << "=> Connected to the client #1 \n" <<
					 "enter " << CLIENT_CLOSE_CONNECTION_SYMBOL << " to the connection\n\n";

		cout << "Client :";
		recv(server, buffer, BUFFER_SIZE, 0);
		cout << buffer << endl;

		if (is_client_connection_close(buffer)) {
			isExit = true;
		}

		while (!isExit) {
			cout << "Server: ";
			cin.getline(buffer, BUFFER_SIZE);
			send(server, buffer, BUFFER_SIZE, 0);
			if(is_client_connection_close(buffer))
				break;

			cout << "Client: ";
			recv(server, buffer, BUFFER_SIZE, 0);
			cout << buffer << endl;
			if (is_client_connection_close(buffer))
				break;
		}

		cout << "\n GoodBye..." <<  endl;
	}

	return 0;
}

bool is_client_connection_close(const char msg[])
{
	for (int i = 0; i < strlen(msg); ++i) {
		if (msg[i] == CLIENT_CLOSE_CONNECTION_SYMBOL)
			return true;
	}
	return false;
}
