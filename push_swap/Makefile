CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

CHECKER = checker

SRC = push_swap.c \
      push_swap__movement.c \
      push_swap_utils.c \
      push_swap__sort_utils.c \
      push_swap_check_args.c \
      push_swap_compare.c \
      push_swap_sort.c 

SRC_B = checker.c \
	get_next_line.c \
	get_next_line_utils.c \
	push_swap__movement.c \
      	push_swap_utils.c \
      	push_swap__sort_utils.c \
      	push_swap_check_args.c \
      	push_swap_compare.c \
      	push_swap_sort.c 

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT) :
	make -C ./libft all
	make -C ./libft bonus
bonus: $(CHECKER)

$(CHECKER) : $(OBJ_B) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_B) $(LIBFT) -o $(CHECKER)

clean :
	rm -rf $(OBJ) $(OBJ_B)
	make -C ./libft fclean

fclean : clean
	rm -f $(NAME) $(CHECKER)

re : fclean all
