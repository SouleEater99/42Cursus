/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:36:25 by ael-maim          #+#    #+#             */
/*   Updated: 2023/11/28 09:28:55 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_putstr(char *s, int *len)
{
    int	i;

    i = 0;
    if (!s)
    {
	return (ft_putstr("(null)", len));
    }
    while (s[i])
         ft_putchar(s[i++], len);
    return (s);
}
