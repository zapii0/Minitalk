SERVER = server
CLIENT = client

S_SRC = server.c
C_SRC = client.c

S_OBJ = $(S_SRC:.c=.o)
C_OBJ = $(C_SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_DIR = /home/mzapora/Desktop/Minitalk/libtf
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I $(LIBFT_DIR)
LIBFT_LNK = -L $(LIBFT_DIR) -lft

all: $(LIBFT) $(SERVER) $(CLIENT)

$(SERVER): $(S_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(S_OBJ) -o $(SERVER) $(LIBFT_LNK) $(LIBFT_INC)

$(CLIENT): $(C_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(C_OBJ) -o $(CLIENT) $(LIBFT_LNK) $(LIBFT_INC)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBFT_INC)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(S_OBJ) $(C_OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(LIBFT) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re

