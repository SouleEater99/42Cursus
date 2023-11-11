/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:13:37 by ael-maim          #+#    #+#             */
/*   Updated: 2023/11/11 17:18:01 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				pos;
	int				i;
	unsigned char	uc;

	if (!str)
		return (NULL);
	uc = c;
	i = 0;
	pos = -1;
	while (str[i])
	{
		if (str[i] == uc)
			pos = i;
		i++;
	}
	if (pos >= 0)
		return ((char *)(str + pos));
	return (NULL);
}
