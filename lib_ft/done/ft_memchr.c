/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:44:23 by ael-maim          #+#    #+#             */
/*   Updated: 2023/11/11 15:47:14 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char	*uc;
	unsigned char	ch;
	size_t			i;

	if (!ptr || n == 0)
		return (NULL);
	ch = c;
	i = 0;
	uc = (unsigned char *)ptr;
	while (i < n)
	{
		if (uc[i] == ch)
			return (&uc[i]);
		i++;
	}
	return (NULL);
}
