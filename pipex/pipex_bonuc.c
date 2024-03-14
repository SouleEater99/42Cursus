/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonuc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:04:59 by ael-maim          #+#    #+#             */
/*   Updated: 2024/03/13 12:55:27 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void ft_free(char **tab)
{
    int i;

    i = 0;
    if (tab)
    {
        while (tab[i])
            free(tab[i++]);
        free(tab);
    }
}

void ft_free_ps(t_lst_pipe *ps)
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

char *ft_get_cmd(char *cmd)
{
    int i;
    int j;
    char *new_cmd;

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

void ft_assign(char *cmd, char **envp, t_lst_pipe *ps)
{
    //if (ps)
     //   ft_free_ps(ps);
    ps->path = ft_get_path(envp, cmd);
    ps->cmd = ft_get_cmd(cmd);
    ps->arg = ft_split(cmd, ' ');
}

void ft_first_fork1(char **envp, t_lst_pipe *ps, int *pip)
{
    int fd1;

    if (ps->path == NULL)
    {
        perror(NULL);
        exit(127);
    }
    fd1 = open("file1", O_CREAT | O_RDWR, 0666);
    if (fd1 == -1)
        exit(1);
    dup2(pip[1], STDOUT_FILENO);
    dup2(fd1, STDIN_FILENO);
    close(fd1);
    close(pip[0]);
    close(pip[1]);
    execve(ps->path, ps->arg, envp);
    exit(1);
}

void ft_middle_fork(char **envp, t_lst_pipe *ps, int *pip)
{

    if (ps->path == NULL)
    {
        perror(NULL);
        exit(127);
    }
    dup2(pip[0], STDIN_FILENO);
    dup2(pip[1], STDOUT_FILENO);
    close(pip[0]);
    close(pip[1]);
    execve(ps->path, ps->arg, envp);
    exit(1);
}

void ft_last_fork(char **envp, t_lst_pipe *ps, int *pip)
{
    int fd2;

    if (ps->path == NULL)

        exit(127);
    fd2 = open("file2", O_CREAT | O_RDWR, 0666);
    if (fd2 == -1)
        exit(2);
    dup2(pip[0], STDIN_FILENO);
    dup2(fd2, STDOUT_FILENO);
    close(pip[0]);
    close(pip[1]);
    close(fd2);
    execve(ps->path, ps->arg, envp);
    exit(1);
}



int ft_multi_pipe(int ac, char **av, char **envp, int *pip)
{
    t_lst_pipe *ps;
    int i;

    i = -1;
    ps = malloc(sizeof(t_lst_pipe));
    ft_assign(av[2], envp, ps);
    ps->pid = fork();
    if (ps->pid == -1)
        return (ft_free_ps(ps), 1);
    if (ps->pid == 0)
        ft_first_fork1(envp, ps, pip);
    else
    {
        while (++i < ac - 4)
        {
            ft_assign(av[i + 3], envp, ps);
            wait(NULL);
            if (i == ac - 5)
            {
                ps->pid = fork();
                if (ps->pid == -1)
                    return (ft_free_ps(ps), 1);
                if (ps->pid == 0)
                    ft_last_fork(envp, ps, pip);
            }
            else
            {
                ps->pid = fork();
                if (ps->pid == -1)
                    return (ft_free_ps(ps), 1);
                if (ps->pid == 0)
                    ft_middle_fork(envp, ps, pip);
            }
        }
    }
}

int main(int ac, char **av, char **envp)
{
    int pip[2];

    if (ac >= 5)
    {
        if (pipe(pip) == -1)
            return (1);
        if (ft_strncmp(av[1], "here_doc", 9) != 0)
        {
            ft_multi_pipe(ac, av, envp, pip);
        }
        else
            return (0);
    }
}
