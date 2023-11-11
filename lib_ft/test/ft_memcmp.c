#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t		i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (*s1 - *s2);
}

int	main()
{
	char	*s1 = "hello world Abdelali";
	char	*s2 = "hello world abdelali";
	size_t	n = 15;

	printf ("------- check memcmp -------\n");
	printf ("result of memcmp(): %d \n", memcmp(s1, s2, n));
	printf ("------- check my ft_memcmp -------\n");
	printf ("result of memcmp(): %d \n", ft_memcmp(s1, s2, n));
}
