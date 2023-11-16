/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:18:38 by ael-maim          #+#    #+#             */
/*   Updated: 2023/11/16 15:04:20 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*d;

	i = 0;
	j = 0;
	if (!s || start > ft_strlen(s))
	{
		d = malloc(1);
		if (!d)
			return (NULL);
		d[0] = '\0';
		return (d);
	}
	d = malloc(len + 1);
	if (!d)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			d[j++] = s[i];
		i++;
	}
	d[j] = '\0';
	return (d);
}
