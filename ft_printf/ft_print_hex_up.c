/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:33:09 by ael-maim          #+#    #+#             */
/*   Updated: 2023/11/27 19:48:21 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex_up(unsigned long long i, int *len)
{
	if (i >= 16)
		ft_print_hex_up(i / 16, len);
	ft_print_index("0123456789ABCDEF", i % 16, len);
}
