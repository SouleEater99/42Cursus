/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:45:04 by ael-maim          #+#    #+#             */
/*   Updated: 2023/12/05 10:43:42 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*buckup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buckup = get_buffer_line(fd, buckup);
	if (!buckup)
		return (NULL);
	line = ft_get_nl(buckup);
	buckup = ft_get_remaind(buckup);
	return (line);
}
/*
 *
int	main(void)
{
	int		fd = 0;
	char	*line;

//	fd = open("files/41_no_nl", O_RDWR , 0666);
//	if (fd == -1)
//			return (0);
	while((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}

*/



