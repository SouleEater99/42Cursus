#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	while (str1[i] && str2[i] && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

int	main()
{
	const char	*str1 = "hello Bbdelali";
	const char	*str2 = "hello Bbdelalt";
	size_t		n = 152;

	printf("return of strcmp differnce: %d \n", strncmp(str1, str2, n));
	printf("return of ft_strcmp differnce: %d \n", ft_strncmp(str1, str2, n));
}
