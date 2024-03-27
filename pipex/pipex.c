/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <ael-maim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:24:16 by ael-maim          #+#    #+#             */
/*   Updated: 2024/03/27 14:13:12 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>

void	ft_exit(s_pipe *ps, int status)
{
	int		i;
	char	**tab;

	i = 0;
	if (ps)
	{
		if (ps->cmd)
			free(ps->cmd);
		if (ps->path)
			free(ps->path);
		if (ps->arg)
		{
			tab = ps->arg;
			while (tab[i])
				free(tab[i++]);
			free(tab);
		}
		free(ps);
	}
	exit(status);
}

void	ft_dup_error(s_pipe *ps, int fd1, int fd2)
{
	perror("dup error");
	close(fd1);
	if (fd2 != -1)
		close(fd2);
	ft_exit(ps, 1);
}

void	ft_first_cmd(s_pipe *ps, int *pip, char **envp)
{
	int	fd1;

	close(pip[0]);
	fd1 = open(ps->file1, O_RDONLY);
	if (fd1 == -1)
	{
		write(2, ps->file1, ft_strlen(ps->file1));
		perror(" ");
		close(pip[1]);
		ft_exit(ps, 1);
	}
	ft_assign(ps->av[ps->i], envp, ps);
	if (dup2(fd1, STDIN_FILENO) == -1)
		ft_dup_error(ps, fd1, pip[1]);
	close(fd1);
	if (dup2(pip[1], STDOUT_FILENO) == -1)
		ft_dup_error(ps, pip[1], -1);
	close(pip[1]);
	execve(ps->path, ps->arg, envp);
	perror("error in execve first cmd");
	ft_exit(ps, 1);
}

void	ft_middle_cmd(s_pipe *ps, int *pip, char **envp)
{
	ft_assign(ps->av[ps->i], envp, ps);
	close(pip[0]);
	if (dup2(pip[1], STDOUT_FILENO) == -1)
		ft_dup_error(ps, pip[1], -1);
	close(pip[1]);
	execve(ps->path, ps->arg, envp);
	perror("error in execve middle cmd");
	ft_exit(ps, 1);
}

void	ft_unlink_file2(s_pipe *ps, char **envp)
{
	int		i;
	char	*f_path;

	i = 0;
	f_path = NULL;
	while (envp[i] && !f_path)
		f_path = ft_strnstr(envp[i++], "PWD=", 4);
	f_path = ft_strjoin_path(f_path + 4, ps->file2, '/');
	if (access(f_path, F_OK) == 0)
		unlink(ps->file2);
	free(f_path);
}
void	ft_last_cmd(s_pipe *ps, int *pip, char **envp)
{
	int	fd2;

	if (!ps->limiter)
		ft_unlink_file2(ps, envp);
	ft_assign(ps->av[ps->i], envp, ps);
	close(pip[0]);
	close(pip[1]);
	fd2 = open(ps->file2, O_CREAT | O_RDWR | O_APPEND, 0777);
	if (fd2 == -1)
	{
		write(2, ps->file2, ft_strlen(ps->file2));
		perror(" ");
		ft_exit(ps, 1);
	}
	if (dup2(fd2, STDOUT_FILENO) == -1)
		ft_dup_error(ps, fd2, -1);
	execve(ps->path, ps->arg, envp);
	perror("error in execve last cmd");
	ft_exit(ps, 1);
}

void	ft_child_proc(char **envp, s_pipe *ps, int *pip)
{
	close(ps->save_stdin);
	if (ps->i == 2)
		ft_first_cmd(ps, pip, envp);
	else if (ps->i == ps->ac - 2)
		ft_last_cmd(ps, pip, envp);
	else
		ft_middle_cmd(ps, pip, envp);
}

int	ft_wexitstatus(int status)
{
	status = status >> 8;
	status = status & 255;
	return (status);
}

int	ft_execute(int ac, char **envp, s_pipe *ps)
{
	int	status;
	int	pip[2];

	while (ps->i < ac - 1)
	{
		if (pipe(pip) == -1)
			ft_exit(ps, 1);
		ps->pid = fork();
		if (ps->pid == -1)
			ft_exit(ps, 1);
		if (ps->pid == 0)
			ft_child_proc(envp, ps, pip);
		close(pip[1]);
		if (dup2(pip[0], STDIN_FILENO) == -1)
			ft_dup_error(ps, pip[0], -1);
		close(pip[0]);
		ps->i++;
	}
	waitpid(ps->pid, &status, 0);
	while (ps->i != -1)
		ps->i = wait(NULL);
	return (ft_wexitstatus(status));
}

void	ft_here_doc(int ac, char **av, s_pipe *ps)
{
	char	*line;
	int		pip[2];

	if (pipe(pip) == -1)
		ft_exit(ps, 1);
	ps->path = NULL;
	ps->cmd = NULL;
	ps->arg = NULL;
	ps->file1 = NULL;
	ps->file2 = av[ac - 1];
	ps->limiter = av[2];
	ps->av = av;
	ps->ac = ac;
	ps->i = 3;
	ft_putstr_fd("Here_Doc Pipe --> ", 1);
	line = get_next_line(0);
	while (line && ft_strncmp(line, av[2], ft_strlen(av[2])) != 0)
	{
		write(pip[1], line, ft_strlen(line));
		free(line);
		ft_putstr_fd("Here_Doc Pipe --> ", 1);
		line = get_next_line(0);
	}
	close(pip[1]);
	free(line);
	if (dup2(pip[0], STDIN_FILENO) == -1)
		ft_dup_error(ps, pip[0], -1);
	close(pip[0]);
}

int	main(int ac, char **av, char **envp)
{
	s_pipe	*ps;
	int		i;

	ps = malloc(sizeof(s_pipe));
	ps->save_stdin = dup(STDIN_FILENO);
	if (!ps)
		return (0);
	if (ac >= 5)
	{
		if (!ft_strnstr(av[1], "here_doc", 9))
		{
			ps->path = NULL;
			ps->cmd = NULL;
			ps->arg = NULL;
			ps->limiter = NULL;
			ps->file1 = av[1];
			ps->file2 = av[ac - 1];
			ps->av = av;
			ps->ac = ac;
			ps->i = 2;
			i = ft_execute(ac, envp, ps);
		}
		else
		{
			ft_here_doc(ac, av, ps);
			i = ft_execute(ac, envp, ps);
		}
	}
	dup2(ps->save_stdin, STDIN_FILENO);
	close(ps->save_stdin);
	return (free(ps), i);
}
