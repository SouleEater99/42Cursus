#include "ft_printf.h"
#include <limits.h>

int main(void)
{
    int a[9] = { 0 };
    a[0] = ft_printf("Hello, world!\n");
    a[1] = ft_printf("%s %s\n", "Hello, world!", NULL);
    a[2] = ft_printf("%p %p\n", "Hello, world!", NULL);
    a[3] = ft_printf("%d%i%u %d\n", 0,-10,100, INT_MIN);
    a[4] = ft_printf("%x %X\n", 1337, 1337);
    a[5] = ft_printf("%x %X\n", 0, 0);
    a[6] = ft_printf("%x %X\n", -1337, -1337);
    a[7] = ft_printf("%c %c %c %c", 'a', '1', 32, '\n');
    a[8] = ft_printf("%c%c%c%c\n", 'a', 'a', 'a', 'a');

    printf("---\tBEGIN PRINTF\t---\n");

    int b[9] = { 0 };
    b[0] = printf("Hello, world!\n");
    b[1] = printf("%s %s\n", "Hello, world!", (char *)NULL);
    b[2] = printf("%p %p\n", "Hello, world!", (char *)NULL);
    b[3] = printf("%d%i%u %d\n", 0,-10,100, INT_MIN);
    b[4] = printf("%x %X\n", 1337, 1337);
    b[5] = printf("%x %X\n", 0, 0);
    b[6] = printf("%x %X\n", -1337, -1337);
    b[7] = printf("%c %c %c %c", 'a', '1', 32, '\n');
    b[8] = printf("%c%c%c%c\n", 'a', 'a', 'a', 'a');

    int success = 1;
    for (int i = 0; i < 8; i++)
        if (a[i] != b[i])
        {
            printf("[%d]: Return doesn't match, expected %d, received %d\n", i, b[i], a[i]);
            success = 0;
        }
    if (success)
        printf("SUCCESS RETURN VALUES MATCH\n");

    return (0);
}
