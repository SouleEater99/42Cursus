#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	unsigned char uc;

	uc = c;
	while (*str)
	{
		if (*str == uc)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

int	main()
{
	const char*	str = "hello world abdelali el maimouni";
	unsigned char	c = 'l';
	const char*	dest = strchr(str, c);

	printf ("---[%s]--- \n \n", str);
	//--------[ test my ft_strchr() ]---------//
	while (dest != NULL)
	{
		printf("found %c in %ld ----> text start: %s \n", c, dest-str+1, dest);
		dest = strchr(++dest, c);
	}
	//--------[ test my ft_strchr() ]---------//
	printf ("\n-------[ ft_strchr ]---------\n\n");
	dest = ft_strchr(str, c);
	while (dest != NULL)
	{
		printf("found %c in %ld ----> text start: %s \n", c, dest-str+1, dest);
		dest = ft_strchr(++dest, c);
	}
}
