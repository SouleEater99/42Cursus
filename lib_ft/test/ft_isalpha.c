#include <stdio.h>

int	ft_isalpha(int	argument)
{
	if (argument >= 'a' && argument <= 'z')
		return (1);
	else if (argument >= 'A' && argument <= 'Z')
		return (2);
	return (0);
}
