/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:38:20 by ael-maim          #+#    #+#             */
/*   Updated: 2023/12/03 13:12:18 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_check_nl(char *buffer)
{
	if (!buffer)
		return (0);
	while (*buffer)
		if (*buffer++ == '\n')
			return (1);
	return (0);
}

char	*ft_strjoin(char *buckup, char *buffer)
{
	int		i;
	int		j;
	char	*new_buckup;

	i = 0;
	j = 0;
	new_buckup = malloc(ft_strlen(buckup) + ft_strlen(buffer) + 1);
	if (!new_buckup)
		return (NULL);
	while (buckup && buckup[i])
	{
		new_buckup[i] = buckup[i];
		i++;
	}
	while (buffer[j])
		new_buckup[i++] = buffer[j++];
	new_buckup[i] = '\0';
	if (buckup)
		free(buckup);
	return (new_buckup);
}

char	*ft_read_to_buckup(int fd, char *buckup)
{
	int		read_byts;
	char	*buffer;

	read_byts = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if ((read(fd, buffer, 0)) == -1)
		return (NULL);
	while (ft_check_nl(buckup) == 0 && read_byts != 0)
	{
		read_byts = read(fd, buffer, BUFFER_SIZE);
		if (read_byts == 0)
		{
			free(buffer);
			free(buckup);
			return (NULL);
		}
		buffer[read_byts] = '\0';
		buckup = ft_strjoin(buckup, buffer);
	}
	free(buffer);
	return (buckup);
}

char	*ft_update_buckup(char *buckup)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(buckup);
	while (buckup[i] && buckup[i] != '\n')
		i++;
	if (buckup[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (j - i + 1));
	if (!str)
	{
		free(buckup);
		return (NULL);
	}
	j = 0;
	while (buckup[i + j])
	{
		str[j] = buckup[i + j];
		j++;
	}
	str[j] = '\0';
	free(buckup);
	return (str);
}
