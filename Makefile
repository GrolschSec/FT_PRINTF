NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj

SRC = ft_printf.c \
	ft_num.c \
	ft_str.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "\033[0;33mGenerating obj..."
	$(CC) -c $(CFLAGS) $^
	@echo "\033[0m"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
