/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:46:34 by ael-maim          #+#    #+#             */
/*   Updated: 2024/03/24 21:17:22 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib_ft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

typedef struct s_pipe
{
	char	**arg;
	char	**av;
	char	*cmd;
	char	*path;
	char	*file1;
	char	*file2;
	int		pid;
	int		i;
	int		ac;
	int		save_stdin;
}			s_pipe;

char		*ft_get_path(char **envp, char *cmd);
int			ft_check_path(char *cmd);
char		*ft_strjoin_path(char const *s1, char const *s2, char c);
size_t		ft_strlen_delimiter(const char *str, char c);
void		ft_free_members(s_pipe *set);
void		ft_free(char **tab);
int			ft_first_fork(char **envp, s_pipe *set, int *pip);
int			ft_second_fork(char **envp, s_pipe *set, int *pip);
void		ft_assign(char *cmd, char **envp, s_pipe *ps);
char		*ft_get_cmd(char *cmd);
void		ft_free(char **tab);
void		ft_exit(s_pipe *ps, int status);

#endif
