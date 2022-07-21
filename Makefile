# Library Name
NAME = libftprintf.a
# Compiler
CC = gcc
# Flag to compile
CFLAGS = -Wall -Wextra -Werror

# Source code
SRC = ft_printf.c \
	ft_num.c \
	ft_str.c \
# Object files
OBJ = $(SRC:.c=.o)
# Main rule
all: $(NAME)
# libftprintf.a rule
$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)
# Generating objects
%.o: %.c 
	@echo "\033[0;33mGenerating obj..."
	$(CC) $(CFLAGS) -c -o $@ $<
	@echo "\033[0m"
# Remove the object files
clean:
	rm -f ./*.o
# Remove the object files and the library
fclean: clean
	rm -f $(NAME)
# Re link
re: fclean all

.PHONY: all clean fclean re
