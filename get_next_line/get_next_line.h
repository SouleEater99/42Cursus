#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42

# include <ctype.h>
# include <stdint.h>
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

char *get_next_line(int fd);

#endif
