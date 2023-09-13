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
int sock(network_socket)
{
	/**int network_socket;**/

	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	return (0);
}
