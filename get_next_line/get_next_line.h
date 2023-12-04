/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:43:27 by ael-maim          #+#    #+#             */
/*   Updated: 2023/12/04 16:54:20 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char    *ft_get_remaind(char *buckup);
char    *ft_get_nl(char *buckup);
char    *get_buffer_line(int fd, char *buckup);
char    *ft_strjoin(char *buckup, char *buffer);
int     ft_check_nl(char *buffer);
int     ft_strlen(char *str);

#endif
