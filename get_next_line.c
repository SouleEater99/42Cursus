/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:59:49 by ael-maim          #+#    #+#             */
/*   Updated: 2023/12/01 18:56:53 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(int fd, char *buckup, char *buffer, char *line)
{

	if (ft_check_line(buckup) == 1)
			return (ft_update_buckup(line, buckup));
	else
	    line = ft_strjoin(line, buckup);
	if ((read(fd, buffer, BUFFER_SIZE)) == 0)
	{
	    	free(line);
		return (NULL);
	}
	if (ft_check_line(buffer) == 1)
	{
		line = ft_strjoin(line, buffer);
		ft_put_remain_buckup(buckup, buffer);
	}
	else
	{
		line = ft_strjoin(line, buffer);
	    	while (ft_check_line(buffer) != 1)
	   	 {
			read(fd, buffer, BUFFER_SIZE);
			line = ft_strjoin(line, buffer);
		}
		ft_put_remain_buckup(buckup, buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buckup[BUFFER_SIZE + 1];
	char 		buffer[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (fd < 0 || read(fd, line, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';	
	line = ft_extract_line(fd, buckup, buffer, line);
	return (line);
}

/*
 *
 *
*/


int	main()
{
	int	fd = open("tt", O_RDWR , 0666);
	
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
