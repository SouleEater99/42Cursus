#include <stdlib.h>
#include <stdio.h>

static int	ft_count_digits(int num)
{
	long	i;
	long	n;

	i = 0;
	n = num;
	if (num == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}


char	*ft_itoa(int n)
{
	long	nbr;
	long	tmp;
	char	*str;

	nbr = n;
	tmp = ft_count_digits(nbr);
	if ((str = (char *)malloc(tmp + 1)) == NULL)
		return (NULL);
	str[tmp--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		nbr = -nbr;
		str[0] = '-';
	}
	while (nbr > 0)
	{
		str[tmp--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}

int	main()
{
	//	printf("c ->%c i -> %ld n -> %ld \n", str[tmp - i], i,nbr); for ft_itoa
	printf ("string: %s :\n", ft_itoa(0));
}
