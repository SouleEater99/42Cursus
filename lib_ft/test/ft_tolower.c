#include <stdio.h>

int	ft_tolower(int argument)
{
        if (argument >= 'A' && argument <= 'Z')
                return (argument + 32);
        return (argument);

}

int     main()
{
        printf ("when char is lowercase %c\n", ft_tolower('Z'));
        printf ("when char is upercase %c\n", ft_tolower('A'));
        printf ("when char is none_alphabitical %c\n", ft_tolower('!'));
}

