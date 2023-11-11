#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (dest);
}

int main() {
	char source[] = "Hello, World!";
	char destination[20]; // Make sure there's enough space in the destination.

	// Copy the content of source to destination.
	ft_memcpy(destination, source, 5);

	printf("Source: %s\n", source);
	printf("Destination: %s\n", destination);

	return 0;
}
