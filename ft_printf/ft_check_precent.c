/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_precent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:36:51 by ael-maim          #+#    #+#             */
/*   Updated: 2023/11/28 16:24:12 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_precent(int *i, const char *str, int *len)
{
	int	n;

	n = 0;
	str = str + (*i);
	while (str[n] && str[n] == '%')
		n++;
	*i = *i + n;
	if (n % 2 == 0)
	{
		n = n / 2;
		while (n-- > 0)
			ft_putchar('%', len);
		return (0);
	}
	else
	{
		n = n / 2;
		while (n-- > 0)
			ft_putchar('%', len);
	}
	return (1);
}
