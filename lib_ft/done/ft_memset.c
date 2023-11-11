/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:54:08 by ael-maim          #+#    #+#             */
/*   Updated: 2023/11/11 17:33:41 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	if (!str)
		return (NULL);
	i = 0;
	s = (unsigned char *)str;
	while (i < n)
		s[i++] = (unsigned char)c;
	return (str);
}
