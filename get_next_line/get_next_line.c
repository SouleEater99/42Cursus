/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:59:49 by ael-maim          #+#    #+#             */
/*   Updated: 2023/12/02 18:13:57 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int	ft_check_buckup(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
		if (buffer[i++] == '\n')
			return (1);
	return (0);
}

char	*ft_extract_line(int fd, char *buckup, char *buffer, char *line)
{
	int	read_byts;

	if (ft_check_buckup(buckup) == 1)
		return (ft_update_buckup(line, buckup));
	else
		line = ft_strjoin(line, buckup);
	if ((read_byts = read(fd, buffer, BUFFER_SIZE)) == 0)
	{
		free(line);
		return (NULL);
	}
	while (ft_check_line(buffer) != 1 && read_byts == BUFFER_SIZE)
	{
		line = ft_strjoin(line, buffer);
		read_byts = read(fd, buffer, BUFFER_SIZE);
	}
	if (read_byts < BUFFER_SIZE)
		buffer[read_byts] = '\0';
	line = ft_strjoin(line, buffer);
	ft_put_remain_buckup(buckup, buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buckup[BUFFER_SIZE + 1];
	char		buffer[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (fd < 0 || read(fd, line, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	line = ft_extract_line(fd, buckup, buffer, line);
	return (line);
}


int	main(void)
{
	int		fd;
	char	*line;

	//int fd = open("files/big_line_no_nl", O_RDWR, 0666);
	fd = open("ff", O_RDWR, 0666);
	//int fd = open("test2", O_RDWR, 0666);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}


