/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:04:59 by ael-maim          #+#    #+#             */
/*   Updated: 2024/02/14 15:05:03 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

// void	ft_print_error(char **envp, char *cmd)
// {


// }

int	ft_first_fork(char **envp, s_pipe *set, int *pip)
{
	int	fd1;

	if (set->path == NULL)
		return (perror(NULL), close(pip[0]), close(pip[1]), 127);
	fd1 = open("file1", O_CREAT | O_RDWR, 0666);
	if (fd1 == -1)
		return (close(pip[0]), close(pip[1]), 1);
	dup2(pip[1], STDOUT_FILENO);
	dup2(fd1, STDIN_FILENO);
	close(fd1);
	close(pip[0]);
	close(pip[1]);
	execve(set->path, set->arg, envp);
	return (1);
}

int	ft_second_fork(char **envp, s_pipe *set, int *pip)
{
	int	fd2;

	if (set->path == NULL)
		return (perror(NULL), close(pip[0]), close(pip[1]), 127);
	fd2 = open("file2", O_CREAT | O_RDWR, 0666);
	if (fd2 == -1)
		return (close(pip[0]), close(pip[1]) ,2);
	dup2(pip[0], STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	close(pip[0]);
	close(pip[1]);
	close(fd2);
	execve(set->path, set->arg, envp);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	s_pipe	*set1;
	s_pipe	*set2;
	int		pip[2];

	set1 = (s_pipe *)malloc(sizeof(s_pipe));	// i need to protect this allocation.
	set2 = (s_pipe *)malloc(sizeof(s_pipe));
	if (ac >= 5)
	{
		if (pipe(pip) == -1)
			return (free(set2), free(set1), 1);
		set1->path = ft_get_path(envp, av[2]);
		set1->arg = ft_split(av[2], ' ');
		set2->path = ft_get_path(envp, av[3]);
		set2->arg = ft_split(av[3], ' ');
		set1->pid = fork();
		if (set1->pid == -1)
			return (ft_free_members(set1), ft_free_members(set2), 1);
		if (set1->pid == 0)
			return (ft_first_fork(envp, set1, pip), ft_free_members(set1),
				ft_free_members(set2), free(set2), free(set1), 1);
		wait(NULL);
		set2->pid = fork();
		if (set2->pid == -1)
			return (ft_free_members(set1), ft_free_members(set2), 1);
		if (set2->pid == 0)
			return (ft_second_fork(envp, set2, pip), ft_free_members(set1),
				ft_free_members(set2), free(set2), free(set1), 1);
	}
	return (ft_free_members(set1), ft_free_members(set2), free(set2),
		free(set1), close(pip[0]), close(pip[1]), 0);
}
