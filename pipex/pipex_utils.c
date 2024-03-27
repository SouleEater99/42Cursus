/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:05:42 by ael-maim          #+#    #+#             */
/*   Updated: 2024/03/27 16:12:42 by ael-maim         ###   ########.fr       */
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

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
}

void	ft_free_ps(s_pipe *ps)
{
	if (ps)
	{
		if (ps->path)
			free(ps->path);
		if (ps->cmd)
			free(ps->cmd);
		if (ps->arg)
			ft_free(ps->arg);
		free(ps);
	}
}

char	*ft_get_cmd(char *cmd)
{
	int		i;
	int		j;
	char	*new_cmd;

	while (*cmd == ' ')
		cmd++;
	if (ft_check_path(cmd))
		return (ft_strdup(cmd));
	while (cmd[i] && cmd[i] != ' ')
		if (cmd[i++] == '/')
			j = i;
	if ((ft_strlen_delimiter(cmd + j, ' ') + 1) == 1)
		return (NULL);
	new_cmd = malloc(ft_strlen_delimiter(cmd + j, ' ') + 1);
	if (!new_cmd)
		return (NULL);
	i = 0;
	while (cmd[j] && cmd[j] != ' ')
		new_cmd[i++] = cmd[j++];
	new_cmd[i] = '\0';
	return (new_cmd);
}

void	ft_print_error(char *cmd)
{
	int	size;

	size = ft_strlen(cmd);
	write(2, cmd, size);
	write(2, ": command not found\n", 21);
}

void	ft_assign(char *cmd, char **envp, s_pipe *ps)
{
	ps->path = ft_get_path(envp, cmd);
	ps->cmd = ft_get_cmd(cmd);
	ps->arg = ft_split(cmd, ' ');
	if (!ps->path)
	{
		ft_print_error(ps->cmd);
		ft_exit(ps, 127);
	}
}

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

	while (cmd && *cmd == ' ')
		cmd++;
	i = 0;
	if (ft_check_path(cmd) == 0)
		return (ft_strdup(cmd));
	while (envp[i] && (ft_strnstr(envp[i], "PATH=", 6) == NULL))
		i++;
	if (envp[i] == NULL)
		return (NULL);
	tab = ft_split(envp[i] + 6, ':');
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
