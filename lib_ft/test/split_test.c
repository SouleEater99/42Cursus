#include "libft.h"

static char	**ft_creat_tab(char **tab, const char *str, char c)
{
	size_t  i;
	size_t  count;

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
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	tab[count] = NULL;
	return (tab);
}

static char	*ft_strdup_char(char const *str, char c)
{
	size_t  i;
	char    *d;
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if ((d = (char *)malloc(i + 1)) == NULL)
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

static size_t  ft_free(char **tab, int i)
{
	int  j;

	j = 0;
	while (j < i)
		free(tab[j]);
	free(tab);
	return (1);
}

static const char	*ft_replace_str(const char *s, char c)
{
	while (*s && *s != c)
		s++;
	while (*s == c)
		s++;
	return (s);
}


char **ft_split(char const *s, char c)
{
	int	i;
	char	**tab;

	if (!s && c != '\0')
		return (NULL);
	while (*s == c)
		s++;
	i = 0;
	tab = NULL;
	tab = ft_creat_tab(tab, s, c);
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		tab[i] = ft_strdup_char(s, c);
		if (!tab[i++])
			if (ft_free(tab, i) == 1)
				return (NULL);
		s = ft_replace_str(s, c);
	}
	return (tab);
}





/*

int main() {
    const char *str = " lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ";
    char **result = ft_split(str, ' ');

    if (result == NULL) {
        printf("RETURN NULL\n");
        return 1;
    }

    for (int i = 0; result[i] != NULL; i++) {
        printf("Word %d: %s\n", i, result[i]);
        free(result[i]); // Don't forget to free the individual strings
    }

    free(result); // Free the array of pointers

    return 0;
}

*/

