# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Project name
NAME = libft.a

# Source files
SRCS = ft_lstadd_front_bonus.c ft_memset.c ft_strlen.c \
       ft_lstclear_bonus.c ft_putchar_fd.c ft_strmapi.c \
       ft_bzero.c ft_lstdelone_bonus.c ft_putendl_fd.c ft_strncmp.c \
       ft_calloc.c ft_lstiter_bonus.c ft_putnbr_fd.c ft_strnstr.c \
       ft_lstlast_bonus.c ft_putstr_fd.c ft_strrchr.c \
       ft_lstmap_bonus.c ft_split.c ft_strtrim.c \
       ft_isalpha.c ft_lstnew_bonus.c ft_strchr.c ft_substr.c \
       ft_isascii.c ft_lstsize_bonus.c ft_strdup.c ft_tolower.c \
       ft_isdigit.c ft_memchr.c ft_striteri.c \
       ft_isprint.c ft_memcmp.c ft_strjoin.c \
       ft_itoa.c ft_memcpy.c ft_strlcat.c \
       ft_lstadd_back_bonus.c ft_memmove.c ft_strlcpy.c

# Object files
OBJS = $(SRCS:.c=.o)

# Rule to compile each object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile the library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Rule to compile everything
all: $(NAME)

# Rule to clean object files
clean:
	$(RM) $(OBJS)

# Rule to clean object files and the library
fclean: clean
	$(RM) $(NAME)

# Rule to clean, recompile, and remake everything
re: fclean all

# Declare the rules not related to files
.PHONY: all clean fclean re

