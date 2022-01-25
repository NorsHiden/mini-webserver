#ifndef SERVER_H
# define SERVER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <string.h>
# include <fcntl.h>
# define BUFSIZE 30000

typedef struct server_t
{
	int domain;
	int socktype;
	int soc_fd;
	int new_soc;
	socklen_t addlen;
	struct sockaddr_in address;
} server_s;

void	setup_server(server_s *server);
void	*ft_respond(void *ss);

#endif