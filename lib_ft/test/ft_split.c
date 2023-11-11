#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static size_t   ft_count_word(const char *str, char c)
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
        return (count);
}

static const char	*ft_strrchr(const char *str, char c)
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

static char *ft_strdup(char const *str, char c)
{
	size_t	i;
	char	*d;
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

size_t	ft_free(char **tab, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
		free(tab[j]);
	free(tab);
	return (1);
}

char **ft_split(char const *s, char c)
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
		if ((tab[i++] = ft_strdup(s, c)) == NULL)
			if (ft_free(tab,i) == 1)
				return (NULL);
		printf("%s, %s \n",s, ft_strrchr(s,c));
		s = ft_strrchr(s, c);
		while (*s == c)
			s++;
	}
	tab[count] = NULL;
	return (tab);
}

int main() {
    const char *str = "this is a test string";
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
