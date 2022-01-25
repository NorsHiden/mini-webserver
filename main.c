#include "server.h"

void *ft_respond(void *ss)
{
	int fd;
	int eof;
	char buff[BUFSIZE + 1];
	server_s *server = (server_s *)ss;

	server->new_soc = accept(server->soc_fd, (struct sockaddr *)&(server->address), &(server->addlen));
	fd = open("template.html", O_RDONLY);
	eof = 1;
	while (eof)
	{
		eof = read(fd, buff, BUFSIZE);
		if (eof < 0)
			eof = 0;
		buff[eof] = 0;
		write(server->new_soc, buff, strlen(buff));
	}
	close(fd);
	return (NULL);
}

int	main(void)
{
	server_s ss;
	pthread_t thread;

	setup_server(&ss);
	while (1)
	{
		if (listen(ss.soc_fd, 3) < 0)
		{
			perror("listen failed");
			exit(EXIT_FAILURE);
		}
		pthread_create(&thread, NULL, ft_respond, &ss);
	}
	return (0);
}