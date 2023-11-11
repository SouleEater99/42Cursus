#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	int		pos;
	int		i;
	unsigned char	uc;

	uc = c;
	i = 0;
	pos = -1;
	while (str[i])
	{
		if (str[i] == uc)
			pos = i;
		i++;
	}
	if (pos >= 0)
		return ((char *)(str + pos));
	return (NULL);
}

int	main()
{
	char	*str = "hello world abdelali";
	char	c = 'o';


	printf ("testing strrchr of %c, text starting: %s\n", c, strrchr(str, c));
	printf ("testing ft_strrchr of %c, text starting: %s\n", c, ft_strrchr(str, c));

}
