#include <stdlib.h>
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char		*d;

	i = 0;
	if (!s || !f)
		return (NULL);
	d = (char *)malloc(sizeof(s) + 1);
	if (!d)
		return (NULL);
	while (s[i])
	{
		d[i] = f(i, s[i]);
		i++;
	}
	d[i] = '\0';
	return (d);
}
/*
int	main()
{
	const char *str = "hello world!";
	char	*d = ft_strmapi(str, ft_touper);
	
	printf("%s \n",d);
	free(d);
}

char	ft_touper(unsigned int i, char c)
{
	(void)i;
	return (c);
}
