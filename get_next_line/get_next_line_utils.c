/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:38:20 by ael-maim          #+#    #+#             */
/*   Updated: 2023/12/02 17:50:39 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_line(char *buffer)
{
	while (*buffer)
		if (*buffer++ == '\n')
			return (1);
	return (0);
}

void	ft_put_remain_buckup(char *buckup, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i])
		if (buffer[i++] == '\n')
			break ;
	while (buffer[i])
		buckup[j++] = buffer[i++];
	buckup[j] = '\0';
}

char	*ft_update_buckup(char *line, char *buckup)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buckup[i])
		if (buckup[i++] == '\n')
			break ;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buckup[i])
	{
		line[i] = buckup[i];
		if (buckup[i++] == '\n')
			break ;
	}
	line[i] = '\0';
	while (buckup[i])
		buckup[j++] = buckup[i++];
	buckup[j] = '\0';
	return (line);
}

char	*ft_strjoin(char *line, char *buffer)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	while (buffer[i])
		if (buffer[i++] == '\n')
			break ;
	while (line && line[j])
		j++;
	new_line = malloc(j + i + 1);
	new_line[i + j] = '\0';
	i = 0;
	while (line && line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	j = 0;
	while (buffer[j])
	{
		new_line[i++] = buffer[j];
		if (buffer[j++] == '\n')
			break ;
	}
	if (line)
		free(line);
	return (new_line);
}
