#define _POSIX_C_SOURCE 200112L
#define _BSD_SOURCE
#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <arpa/inet.h>

/**
 * main - a HTTP client
 *
 * @argc: argument count
 * @argv: list of arguments
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	int client_socket;
	char response[4096];
	char *address;
	char request[] = "GET / HTTP/1.1\r\n\r\n";
	struct sockaddr_in remote_address;

	address = argv[argc - 1];
	/* Create a socket */

	client_socket = socket(AF_INET, SOCK_STREAM, 0);

	/* Connect to an address */
	remote_address.sin_family = AF_INET;
	remote_address.sin_port = htons(80);
	if (inet_aton(address, &remote_address.sin_addr) == 0)
	{
		perror("inet_aton");
		return (1);
	}

	if (connect(client_socket, (struct sockaddr *) &remote_address,
				sizeof(remote_address)) == -1)
	{
		perror("connect");

		close(client_socket);
		exit(1);
	}

	send(client_socket, request, sizeof(request), 0);
	recv(client_socket, &response, sizeof(response), 0);

	printf("Response from the server: %s\n", response);
	close(client_socket);

	return (0);
}
