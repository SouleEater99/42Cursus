/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:02:18 by ael-maim          #+#    #+#             */
/*   Updated: 2023/11/16 15:03:44 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*allocate;

	allocate = malloc(size * num);
	if (allocate == NULL)
		return (NULL);
	ft_bzero(allocate, size * num);
	return ((void *)allocate);
}
