#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char	*uc;
	unsigned char	ch;
	size_t		i;

	ch = c;
	i = 0;
	uc = (unsigned char *)ptr;
	while (i < n)
	{
		if (uc[i] == ch)
			return (&uc[i]);
		i++;
	}
	return (NULL);
}

int	main()
{
	char	*str = "hello abdelali";
	char	c = 'o';
	size_t	n = 4;
	unsigned char *dest= (unsigned char *)memchr(str, c, n);

	printf("\n-------[ %s ] [ %c ] is char to find, starting from : %s \n", str,c, dest);
	
	printf ("\n --------here test of my ft_memchr()---------  \n");
	
	dest= (unsigned char *)ft_memchr(str, c, n);
	printf("\n ------[ %s ] [ %c ] is char to find, starting from : %s \n", str,c, dest);
}
