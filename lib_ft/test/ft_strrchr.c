
#include "libft.h"

char    *ft_strrchr(const char *str, int c)
{
        int             i;
        unsigned char   uc;

        if (!str)
                return (NULL);
        uc = c;
        i = ft_strlen(str);
	if (uc == str[i])
		return ((char *)&str[i]);
        while (--i >= 0)
                if (str[i] == uc)
                        return ((char *)&str[i]);
        return (NULL);
}

int	main()
{
	const char	*str = "hello world abdelali";
	char	c = '\0';


	printf ("testing strrchr of %c, text starting: %s\n", c, strrchr(str, c));
	printf ("testing strrchr of %c, text starting: %s\n", c, ft_strrchr(str, c));

}
