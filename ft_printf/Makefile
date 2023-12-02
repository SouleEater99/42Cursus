CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
AR = ar rcs
RM = rm -f

# List of your source files
SRC = ft_check_precent.c \
      ft_print_hex_low.c \
      ft_printf.c \
      ft_putnbr_unsigned.c \
      ft_print_addres.c \
      ft_print_hex_up.c \
      ft_putchar.c \
      ft_putstr.c \
      ft_print_arg.c \
      ft_print_index.c \
      ft_putnbr.c

# Convert .c filenames to .o to obtain a list of object files
OBJ = $(SRC:.c=.o)

# The all rule makes the library
all: $(NAME)

# Rule to make the library
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Pattern rule for object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Removing object files
clean:
	$(RM) $(OBJ)

# Removing object files and the library
fclean: clean
	$(RM) $(NAME)

# Re-make the library 
re: fclean all

.PHONY: all clean fclean re
