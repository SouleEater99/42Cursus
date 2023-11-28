/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:38:18 by ael-maim          #+#    #+#             */
/*   Updated: 2023/11/27 19:47:58 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_print_arg(va_list ptr, int c, int *len)
{
        if (c == 'c')
            ft_putchar(va_arg(ptr, int), len);
        else if (c == 'd' || c == 'i')
            ft_putnbr(va_arg(ptr, int), len);
        else if (c == 'u')
            ft_putnbr_unsigned(va_arg(ptr, unsigned int), len);
        else if (c == 's')
            ft_putstr(va_arg(ptr, char *), len);
        else if (c == 'x')
            ft_print_hex_low(va_arg(ptr, unsigned int), len);
        else if (c == 'X')
            ft_print_hex_up(va_arg(ptr, unsigned int), len);
        else if (c == 'p')
            ft_print_addres(va_arg(ptr, char *), len);
	else
	{
		ft_putchar('%', len);
		ft_putchar(c, len);
	}


}
