#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
	int client_socket;
	char response[4096];	
	char *address;
	char* request = "GET / HTTP/1.1\r\n\r\n";
	struct sockaddr_in remote_address;

	address = argv[argc];
	/* Create a socket */

	client_socket = socket(AF_INET, SOCK_STREAM, 0);

	/* Connect to an address */
	remote_address.sin_family = AF_INET;
	remote_address.sin_port = htons(80);
	inet_aton(address, &remote_address.sin_addr);

	connect(client_socket, (struct sockaddr *) &remote_address, sizeof(remote_address));

	send(client_socket, request, sizeof(request), 0);
	recv(client_socket, &response, sizeof(response), 0);

	printf("Response from the server: %s\n", response);
	close(client_socket);

	return (0);
}
