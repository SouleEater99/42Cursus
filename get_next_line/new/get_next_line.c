/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:59:49 by ael-maim          #+#    #+#             */
/*   Updated: 2023/12/03 15:06:55 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*ft_extract_line(char *buckup)
{
	char	*line;
	int		i;

	i = 0;
	while (buckup[i] && buckup[i] != '\n')
		i++;
	if (buckup[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (buckup[i] && buckup[i] != '\n')
	{
		line[i] = buckup[i];
		i++;
	}
	if (buckup[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buckup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buckup = ft_read_to_buckup(fd, buckup);
	if (!buckup)
		return (NULL);
	line = ft_extract_line(buckup);
	buckup = ft_update_buckup(buckup);
	return (line);
}
/*
*/
int	main(void)
{
	int		fd;
	char	*line;

	//int fd = open("files/big_line_no_nl", O_RDWR, 0666);
	fd = open("../text", O_RDWR, 0666);
	//int fd = open("test2", O_RDWR, 0666);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
