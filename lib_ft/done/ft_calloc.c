/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:02:18 by ael-maim          #+#    #+#             */
/*   Updated: 2023/11/11 12:03:07 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void			*allocate;
	unsigned char	*bzero;
	size_t			i;

	i = 0;
	allocate = malloc(size * num);
	if (allocate == NULL)
		return (NULL);
	bzero = (unsigned char *)allocate;
	while (i < size)
		bzero[i++] = 0;
	return ((void *)allocate);
}
