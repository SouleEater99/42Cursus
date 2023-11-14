#include <stdio.h>
#include <string.h>
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t		i;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	if (d == NULL || s == NULL)
		return (NULL);
	if (d > s)
		while (n-- > 0)
			d[n] = s[n];
	else
		while (i++ < n)
			*d++ = *s++;
	return (dest);
}

int	main()
{
	unsigned char src[] = "hello world";
	unsigned char src2[] = "hello world";
	unsigned char *dest = (unsigned char *)memmove(src + 6, src, 0);
	
	printf("memmove from standard lib: src[ %s ] | dest [ %s ] \n", src, dest);
	unsigned char *dest2 = (unsigned char *)ft_memmove(src2 + 6, src2, 0);
	printf("my ft_memmove(): src[ %s ] | dest [ %s ] \n", src2,dest2);
}
