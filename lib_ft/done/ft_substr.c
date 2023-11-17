/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:18:38 by ael-maim          #+#    #+#             */
/*   Updated: 2023/11/17 10:51:36 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	s_len;
	char	*d;

	i = 0;
	j = 0;
	s_len = ft_strlen(s);
	if (!s || start > s_len)
	{
		d = malloc(1);
		if (!d)
			return (NULL);
		d[0] = '\0';
		return (d);
	}
	if (start + len > s_len)
		len = s_len - start;
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
