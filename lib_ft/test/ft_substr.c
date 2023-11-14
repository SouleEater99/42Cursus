#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*d;

	i = 0;
	while (s[i])
		i++;
	if (start >= i || i - start < len)
		return (NULL);
	d = (char *)malloc(len + 1);
	if (d == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

int	main()
{

const char *input = "Data";
char *substring = ft_substr(input, 0, 0);
if (substring) {
    printf("Substring: %s\n", substring);  // Output: "" (empty string)
    free(substring);  // Don't forget to free the allocated memory
}


}
