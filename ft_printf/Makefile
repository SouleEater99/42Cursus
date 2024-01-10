CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
AR = ar rcs
RM = rm -f

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

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
