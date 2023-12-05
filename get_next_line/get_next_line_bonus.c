/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:45:04 by ael-maim          #+#    #+#             */
/*   Updated: 2023/12/05 10:40:17 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *to_free)
{
	free(to_free);
	return (NULL);
}

char	*get_buffer_line(int fd, char *buckup)
{
	int		rd_byts;
	char	*buffer;

	rd_byts = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
		return (ft_free(buffer));
	while (rd_byts > 0 && ft_check_nl(buckup) == 0)
	{
		rd_byts = read(fd, buffer, BUFFER_SIZE);
		buffer[rd_byts] = '\0';
		buckup = ft_strjoin(buckup, buffer);
	}
	free(buffer);
	if (!buckup[0])
		return (ft_free(buckup));
	return (buckup);
}

char	*get_next_line(int fd)
{
	static char	*buckup[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buckup[fd] = get_buffer_line(fd, buckup[fd]);
	if (!buckup[fd])
		return (NULL);
	line = ft_get_nl(buckup[fd]);
	buckup[fd] = ft_get_remaind(buckup[fd]);
	return (line);
}


	/*
int	main(void)
{
	int		fd = 0;
	char	*line;

	fd = open("text", O_RDWR , 0666);
	int fd2 = open("test2", O_RDWR , 0666);
	if (fd == -1 || fd2 == -1)
	    return (0);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);
	
	while((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	while((line = get_next_line(fd2)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	close (fd2);
	close(fd);
}

*/
