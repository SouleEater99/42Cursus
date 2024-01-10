/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:14:25 by ael-maim          #+#    #+#             */
/*   Updated: 2023/11/29 10:38:30 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ptr, format);
	if (!format || (format[i] && format[i + 1] == '\0'))
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && ft_check_precent(&i, format, &len) == 1)
		{
			if ((ft_print_arg(ptr, format[i++], &len)) == -1)
				return (-1);
		}
		else if (format[i])
			ft_putchar(format[i++], &len);
	}
	va_end(ptr);
	return (len);
}
