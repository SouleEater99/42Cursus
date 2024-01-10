/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:01:50 by ael-maim          #+#    #+#             */
/*   Updated: 2023/11/27 19:49:22 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *len)
{
	long long	nbr;

	nbr = nb;
	if (nb < 0)
	{
		nbr = -nbr;
		ft_putchar('-', len);
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10, len);
	ft_putchar((nbr % 10) + '0', len);
}
