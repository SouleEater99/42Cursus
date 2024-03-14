/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:46:34 by ael-maim          #+#    #+#             */
/*   Updated: 2024/02/06 13:36:48 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
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
	char	*path;
	char	**arg;
	int		pid;

}			s_pipe;


char	*ft_get_path(char **envp, char *cmd);
int		ft_check_path(char *cmd);
char	*ft_strjoin_path(char const *s1, char const *s2, char c);
size_t	ft_strlen_delimiter(const char *str, char c);
void	ft_free_members(s_pipe *set);
void	ft_free(char **tab);
int	ft_first_fork(char **envp, s_pipe *set, int *pip);
int	ft_second_fork(char **envp, s_pipe *set, int *pip);



#endif
