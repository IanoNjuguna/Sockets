#include <stdio.h>
#include <stdlib.h>

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
 * sock - creates a socket
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
int sock(network_socket, connection_status)
{
	/**int network_socket;**/

	/* Create a socket */
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	/* Connect to a remote address */
	/* Specify an address for the socket */
	struct sockaddr_in server_address;

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9003);
	server_address.sin_addr.s_addr = INADDR_ANY;

	connection_status = connect(network_socket, (struct sockaddr *) & server_address, sizeof(server_address));

	/* Check for an error with the connection */
	if (connection_status == -1)
	{
		printf("There was an error making a connection to the remote socket \n \n");
	}

	return (0);
}
