CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRC = main.c \
      movement.c \
      push_swap_utils.c


LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT) :
	make -C ./libft all
	make -C ./libft bonus

clean :
	make -C ./libft fclean

fclean : clean
	rm -f $(NAME)

re : fclean all
