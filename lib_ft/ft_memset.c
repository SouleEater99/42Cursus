#include <string.h>
#include <stdio.h>

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	unsigned char *s;

	i = 0;
	s = (unsigned char *)str;
	while (i < n)
		s[i++] = (unsigned char)c;
	return (str);
}

int	main()
{
	size_t	i;
	size_t	n = 5;
	char	buffer[n];

	i = 0;
	ft_memset(buffer, 0x65, sizeof(buffer));
	while (i < n)
	{
		printf("array[%ld] = %c  \n",i ,buffer[i]);
		i++;
	}
}
