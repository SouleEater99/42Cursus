#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

int	main()
{
	unsigned char c = 'A';
	unsigned char c1 = 149;

	printf ("___________ isascii() _________________\n");
	printf ("%c is an ascii charcters:%d \n", c, isascii(c));
	printf ("%c is not an ascii charcters: %d \n", c1, isascii(c1));

	//-------------------------------------//

	printf ("___________ ft_isascii() _________________\n");
	printf ("%c is an ascii charcters:%d \n", c, ft_isascii(c));
	printf ("%c is not an ascii charcters:%d \n", c1,ft_isascii(c1));

}
