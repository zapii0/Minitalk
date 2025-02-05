SRC = client.c server.c
OBS = ${SRC:c=.o}
AR = ar rcs
CC = cc
all: server client

server: server.o libft-updated
	$(CC) -o $@ $< -L
