SERVER = server
CLIENT = client

S_SRC = server.c
C_SRC = client.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I $(LIBFT_DIR)
LIBFT_LNK = -L $(LIBFT_DIR) -lft

all: $(LIBFT) $(SERVER) $(CLIENT)

$(SERVER): $(S_SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(S_SRC) -o $(SERVER) $(LIBFT_LNK)

$(CLIENT): $(C_SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(C_SRC) -o $(CLIENT) $(LIBFT_LNK)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(SERVER) $(CLIENT)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(LIBFT)

re: fclean all
