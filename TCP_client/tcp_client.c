#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

/**
 * types.h  - for definitions about the socket functions used
 * socket.h - most of the important functionality and APIs used ...
 *			  for socket creation are here
 */
#include <sys/types.h>
#include <sys/socket.h>

/**
 * in.h - contains structures needed to store address information
 */
#include <netinet/in.h>

/**
 * main - creates a socket
 *
 * @network_socket: stores the result of the socket() function in an int,
 *					basically a file descriptor
 *
 * AF_INET: a constant
 *			domain for an internet socket
 *
 * SOCK_STREAM: a type
 *				indicates this is a TCP socket, i.e. a connection socket
 *
 * 0: default protocol, i.e TCP
 */
int main(void)
{

	int network_socket;
	int connection_status;
	char server_response[256];
	struct sockaddr_in server_address;

	/**int network_socket;**/

	/* Create a socket */
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	/* Connect to a remote address */
	/* Specify an address for the socket */
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9003);
	server_address.sin_addr.s_addr = INADDR_ANY;

	connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

	/* Check for an error with the connection */
	if (connection_status == -1)
	{
		printf("Connection Error: Failed to connect to the remote socket.\n\n");
		printf("Server Details: %s\n", strerror(errno));
	}
	else
	{
		/* Receive data from the server */
		recv(network_socket, &server_response, sizeof(server_response), 0);

		/* Print out the server's response */
		printf("The server sent the following data: %s\n", server_response);

		/* Close the socket */
		close(network_socket);
	}
	return (0);
}
