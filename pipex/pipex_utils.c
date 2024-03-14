/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:05:42 by ael-maim          #+#    #+#             */
/*   Updated: 2024/02/14 15:16:03 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_members(s_pipe *set)
{
	if (set)
	{
		if (set->path)
			free(set->path);
		if (set->arg)
			ft_free(set->arg);
	}
}

// void	ft_print_error(char **envp, char *cmd)
// {
// 	char	**tab;
// 	int		i;
// 	char 	*error;
	
// 	i = 0;
// 	while (envp[i] && (ft_strnstr(envp[i], "SHELL=", 7) == NULL))
// 		i++;
// 	tab = ft_split(&(envp[i]) + 7, '/');
// 	i = 0;
// 	while (tab[i])
// 		i++;
// 	write(2, tab[i -1], sizeof(tab[i - 1]));
// 	write(2, ": command not found: ", 22);
// 	while )////// we stop here i eed to rite the same error in 127;
// }

size_t	ft_strlen_delimiter(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_strjoin_path(char const *s1, char const *s2, char c)
{
	size_t	i;
	size_t	s1_len;
	char	*d;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1) + 1;
	d = (char *)malloc(s1_len + ft_strlen_delimiter(s2, ' ') + 1);
	if (d == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		d[i] = s1[i];
	d[i] = c;
	i = 0;
	while (s2[i] && s2[i] != ' ')
	{
		d[s1_len + i] = s2[i];
		i++;
	}
	d[s1_len + i] = '\0';
	return (d);
}

int	ft_check_path(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] == ' ')
		i++;
	while (cmd[i] && cmd[i] != ' ')
		if (cmd[i++] == '/')
			return (0);
	return (1);
}

char	*ft_get_path(char **envp, char *cmd)
{
	int		i;
	char	*path;
	char	**tab;

	i = 0;
	if (ft_check_path(cmd) == 0)
		return (ft_strdup(cmd));
	while (envp[i] && (ft_strnstr(envp[i], "PATH=", 6) == NULL))
		i++;
	tab = ft_split(envp[i]  , ':');
	i = 0;
	while (tab[i])
	{
		path = ft_strjoin_path(tab[i], cmd, '/');
		if (access(path, X_OK) == 0)
			return (ft_free(tab), path);
		free(path);
		i++;
	}
	return (ft_free(tab), NULL);
}
