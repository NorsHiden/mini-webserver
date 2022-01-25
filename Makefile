CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread

SRCS = server.c main.c

NAME = server

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean :
	rm -rf server

re : clean all

.PHONY: all clean re