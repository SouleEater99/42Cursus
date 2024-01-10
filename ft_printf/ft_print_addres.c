/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addres.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:34:28 by ael-maim          #+#    #+#             */
/*   Updated: 2023/11/28 14:14:25 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_addres(void *add, int *len)
{
	unsigned long long	i;

	if (add)
	{
		i = (unsigned long long)add;
		ft_putstr("0x", len);
		ft_print_hex_low(i, len);
	}
	else
		ft_putstr("(nil)", len);
}
