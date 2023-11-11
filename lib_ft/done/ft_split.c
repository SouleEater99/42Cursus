/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:27:13 by ael-maim          #+#    #+#             */
/*   Updated: 2023/11/11 17:28:36 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] == c)
		i++;
	if (str[i] != '\0')
		count = 1;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1])
			count++;
		i++;
	}
	return (count);
}

static const char	*ft_strrchr_split(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (str + i);
}

static char	*ft_strdup_split(char const *str, char c)
{
	size_t	i;
	char	*d;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	d = (char *)malloc(i + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (str[i] != c && str[i])
	{
		d[i] = str[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

static size_t	ft_free(char **tab, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
		free(tab[j]);
	free(tab);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	count;
	char	**tab;

	i = 0;
	if (s == NULL)
		return (NULL);
	count = ft_count_word(s, c);
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (tab == NULL)
		return (NULL);
	while (i < count && *s)
	{
		if ((tab[i++] = ft_strdup_split(s, c)) == NULL)
			if (ft_free(tab, i) == 1)
				return (NULL);
		s = ft_strrchr_split(s, c);
		while (*s == c)
			s++;
	}
	tab[count] = NULL;
	return (tab);
}
