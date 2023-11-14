#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!haystack || !needle || !haystack[0])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
			if (needle[++j] == '\0')
				return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

int	main()
{
	const char	*str = "";
	const char	*needle = "world";
	size_t		n = 14;

	printf("haystack: %s \n needle:%s \n result: %s\n",str ,needle, ft_strnstr(str, needle, n));
}
