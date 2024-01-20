CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRC = push_swap.c \
      push_swap__movement.c \
      push_swap_utils.c \
      push_swap__sort_utils.c \
      push_swap_check_args.c \
      push_swap_compare.c \
      push_swap_sort.c 


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
