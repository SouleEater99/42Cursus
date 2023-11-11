#include <ctype.h>
#include <stdio.h>

int	ft_isprint(int	arg)
{
	if (arg >= 32 && arg <= 126)
		return (1);
	return (0);
}

int	main()
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (i <= 127)
	{
		if (isprint(i))
		{
			printf("%c is printable, return %d \n", i, isprint(i));
			count++;
		}
		i++;
	}
	printf("---------[ check how many printable in two funcction: %d ]----------\n", count);
	printf ("\n -------------[ test of my ft_isprint ]-------------\n");
	i = 0;
	count = 1;
	while (i <= 127)
	{
		if (ft_isprint(i))
		{
			printf("%c is printable, return %d \n", i, ft_isprint(i));
			count++;
		}
		i++;
	}
	printf("---------[ check how many printable in two funcction: %d ]----------\n", count);
}
