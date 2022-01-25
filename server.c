#include "server.h"

void	setup_server(server_s *server)
{
	server->domain = AF_INET;
	server->socktype = SOCK_STREAM;
	server->soc_fd = socket(server->domain, server->socktype, 0);
	if (server->soc_fd < 0)
	{
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
	server->address.sin_family = AF_INET;
	server->address.sin_addr.s_addr = INADDR_ANY;
	server->address.sin_port = htons(80);
	server->addlen = sizeof(server->address);
	if (bind(server->soc_fd, (struct sockaddr *)&(server->address), server->addlen) < 0)
	{
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
}