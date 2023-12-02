#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

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


char	*get_next_line(int fd);
int     ft_check_line(char *buffer);
void    ft_put_remain_buckup(char *buckup, char *buffer);
char    *ft_update_buckup(char *line, char *buckup);
char    *ft_strjoin(char *line, char *buffer);
char    *ft_extract_line(int fd, char *buckup, char *buffer, char *line);


#endif
