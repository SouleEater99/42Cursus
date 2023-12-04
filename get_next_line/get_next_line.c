/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:45:04 by ael-maim          #+#    #+#             */
/*   Updated: 2023/12/04 16:52:41 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_buffer_line(int fd, char *buckup)
{
	int	rd_byts;
	char	buffer[BUFFER_SIZE + 1];

	if (read(fd, buffer, 0) < 0)// add condition of buckup[0] == '\0' return NULL
	{
		free(buckup);
		return (NULL);
	}
	rd_byts = 1;
	while (rd_byts > 0 && ft_check_nl(buffer) == 0)
	{
		rd_byts = read(fd, buffer, BUFFER_SIZE);
		buffer[rd_byts] = '\0';
		buckup = ft_strjoin(buckup, buffer);
		if (!buckup)
		    return (NULL);
	}
	if (!buckup[0])
	{
	    free(buckup);
	    return NULL;
	}
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
int	main()
{
	int	fd = open("files/41_no_nl", O_RDWR , 0666);

	if (fd == -1)
	    return (0);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);

}

*/

