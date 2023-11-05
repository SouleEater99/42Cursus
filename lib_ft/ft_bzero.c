#include <stdio.h>
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	unsigned char *a;

	i = 0;
	a = (unsigned char*)s;
	while (i < n)
		a[i++] = 0;
}

int	main(void)
{
	size_t i = 0;
	size_t n = 10;
	char	buffer[n];

	ft_bzero(buffer, sizeof(buffer));
	while (i < n)
	{
		printf("buffer[%ld] = %d \n", i , buffer[i]);
		i++;
	}

}
