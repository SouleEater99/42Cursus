/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <ael-maim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:02:41 by ael-maim          #+#    #+#             */
/*   Updated: 2024/03/13 11:07:03 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
#define PIPEX_BONUS_H

#include "pipex.h"

typedef struct  t_lst_pipe
{
    char                *path;
    char                *cmd;
    char                **arg;
    int                 pid;
}   t_lst_pipe;





#endif
