#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

/**
 * servr - a TCP server
 *
 * @server_socket: socket call
 *
 */
int servr(server_socket, client_socket)
{
	char server_message[256] = "You have reached the server";

	/* Create the server socket */
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	/* Define the server address */
	struct sockaddr_in server_address;

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9003);
	server_address.sin_addr.s_addr = INADDR_ANY;

	/* Bind the socket to our specified IP and port */
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

	/* Listen for connections */
	listen(server_socket, 5);

	/* Accept a connection */
	client_socket = accept(server_socket, NULL, NULL);

	/* Send data to the socket(s) in the accepted connection */
	send(client_socket, server_message, sizeof(server_message), 0);

	/* Close the socket */
	close(server_socket);

	return (0);
}
