#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
/**
 * main - HTTP SERVER
 *
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	FILE *html_data;
	char response_data[1024];
	char http_header[2048] = "HTTP/1.1 200 0K \r\n\n";
	int server_socket;
	struct sockaddr_in server_address;
	int client_socket;

	/* Open a file to Serve */
	html_data = fopen("index.html", "r");

	fgets(response_data, 1024, html_data);

	strcat(http_header, response_data);

	/* Create a server socket */
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	/* Define the address */
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9003);
	server_address.sin_addr.s_addr = INADDR_ANY;

	bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

	listen(server_socket, 5);

	while (1)
	{
		client_socket = accept(server_socket, NULL, NULL);
		send(client_socket, http_header, sizeof(http_header), 0);
		close(client_socket);
	}

	return (0);
}
