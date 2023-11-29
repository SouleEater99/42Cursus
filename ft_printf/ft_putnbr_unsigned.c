/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:00:15 by ael-maim          #+#    #+#             */
/*   Updated: 2023/11/27 19:49:33 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(int nb, int *len)
{
	unsigned int	nbr;

	nbr = nb;
	if (nbr > 9)
		ft_putnbr_unsigned(nbr / 10, len);
	ft_putchar((nbr % 10) + '0', len);
}
