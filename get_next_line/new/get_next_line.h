/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:00:49 by ael-maim          #+#    #+#             */
/*   Updated: 2023/12/03 11:00:53 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
char	*ft_read_to_buckup(int fd, char *buckup);
int		ft_check_nl(char *buffer);
int		ft_strlen(char *str);
char	*ft_update_buckup(char *buckup);
char	*ft_strjoin(char *buckup, char *buffer);
char	*ft_extract_line(char *buckup);

#endif
