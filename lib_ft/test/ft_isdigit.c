#include <stdio.h>

int     ft_isalpha(int  argument)
{
        if (argument >= '0' && argument <= '9')
                return (1);
        return (0);
}

int     main()
{
        printf ("when char is digit %d\n", ft_isalpha('4'));
        printf ("when char is none_digit %d\n", ft_isalpha('A'));
        printf ("when char is none_digit %d\n", ft_isalpha('#'));
}

