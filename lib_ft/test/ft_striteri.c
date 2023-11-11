#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return;
	while (s[i])
	{
		f(i, s);
		i++;
	}
}
/*
int	main()
{
	char d[]= "hello ali!";
	ft_striteri(d, ft_put);

	printf("%s\n",d);

}

void	ft_put(unsigned int i, char *s)
{
	s[i] = 'c';
}


