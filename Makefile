# Library Name
NAME = libftprintf.a
# Compiler
CC = gcc
# Flag to compile
CFLAGS = -Wall -Wextra -Werror
# Generated objects dir
OBJ_DIR = objs
# Sources dir
SRC_DIR = srcs
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
	ar rc $(NAME) $(addprefix $(OBJ_DIR)/,$^)
	ranlib $(NAME)
# Generating objects
%.o: $(SRC_DIR)/%.c object
	@echo "\033[0;33mGenerating obj..."
	$(CC) $(CFLAGS) -c -o $(OBJ_DIR)/$@ $<
	@echo "\033[0m"
# Make the object dir
object:
	mkdir -p objs
# Remove the object dir
clean:
	rm -rf ./objs
# Remove the object dir and the library
fclean: clean
	rm -f $(NAME)
# Re link
re: fclean all

.PHONY: all clean fclean re
