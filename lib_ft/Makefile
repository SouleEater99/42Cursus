BINARY = libft.a
CC = gcc -Wextra -Wall -Werror
LIB = ar rcs

all : $(BINARY)

$(BINARY):
	$(CC) -c *.c
	$(LIB)  $(BINARY) *.o
clean :
	rm -rf *.o
fclean : clean
	rm -rf $(BINARY)
re: fclean all



