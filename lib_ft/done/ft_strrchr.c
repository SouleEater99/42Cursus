/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:13:37 by ael-maim          #+#    #+#             */
/*   Updated: 2023/11/12 09:06:17 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	unsigned char	uc;

	if (!str)
		return (NULL);
	uc = c;
	i = ft_strlen(str);
	if (uc == str[i])
		return ((char *)&str[i]);
	while (--i >= 0)
		if (str[i] == uc)
			return ((char *)&str[i]);
	return (NULL);
}
