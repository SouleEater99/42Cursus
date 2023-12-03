#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_check_line(char *buffer);
void	ft_put_remain_buckup(char *buckup, char *buffer);
char	*ft_update_buckup(char *line, char *buckup);
char	*ft_strjoin(char *line, char *buffer);
char	*ft_extract_line(int fd, char *buckup, char *buffer, char *line);

#endif
