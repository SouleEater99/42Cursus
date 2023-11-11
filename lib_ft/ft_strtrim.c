#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static size_t	ft_check_set(char c, char const	*set)
{
	if (!set)
		return (1);
	while (*set)
		if (*set++ == c)
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	size_t	end;
	char	*str;

	i = 0;
	end = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	while (s1[i] && !ft_check_set(s1[i], set))
		i++;
	while (len > i && !ft_check_set(s1[len - 1], set))
		len--;
	str = malloc(len - i + 1);
	while (i < len)
		str[end++] = s1[i++];
	str[end] = '\0';
	return (str);
}

/*
int main()
{
  char *str= ft_strtrim("haaaaaaaaaahataa", "hat");
  printf("%s \n", str);
 free(str); 
  
  
}

*/

