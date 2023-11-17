/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:02:18 by ael-maim          #+#    #+#             */
/*   Updated: 2023/11/17 10:46:03 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*allocate;

	if (num == 0 || size == 0)
	{
		num = 1;
		size = 1;
	}
	if (size > SIZE_MAX / num)
		return (NULL);
	allocate = malloc(num * size);
	if (allocate == NULL)
		return (NULL);
	ft_bzero(allocate, num * size);
	return ((void *)allocate);
}
