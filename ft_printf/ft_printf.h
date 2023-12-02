#ifndef FT_PRINTF_H
#define	FT_PRINTF_H

# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

void    ft_print_arg(va_list ptr, int c, int *len);
void    ft_print_addres(void *add, int *len);
void    ft_print_hex_low(unsigned long long i, int *len);
void    ft_print_hex_up(unsigned long long i, int *len);
void    ft_print_index(char *str, int index, int *len);
int     ft_printf(const char *format, ...);
void    ft_putnbr(int nb, int *len);
int     ft_check_precent(int *i, const char *str, int *len);
char    *ft_putstr(char *s, int *len);
void    ft_putchar(char c, int *len);
void    ft_putnbr_unsigned(int nb, int *len);

#endif
