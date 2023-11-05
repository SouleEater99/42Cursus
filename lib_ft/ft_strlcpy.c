#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && --size > 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

int	main()
{
	char	str[] = "asdfghjklwertyuiopzxcvbnmasdfghjkl";
	char	dest[10];
	int	len = strlen(str);

	printf("len of str %d \n dest ==>:[%s]:\n return value: %ld \n", len, dest, ft_strlcpy(dest, str, sizeof(dest)));
}
