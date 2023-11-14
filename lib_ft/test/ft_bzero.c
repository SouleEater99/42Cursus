/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:34:31 by ael-maim          #+#    #+#             */
/*   Updated: 2023/11/12 06:49:24 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	unsigned char *a;

	i = 0;
	a = (unsigned char*)s;
	while (i < n)
		a[i++] = 0;
}
/*
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
*/
#include "/home/souleeater/libft-war-machine/libft.h"

int             main(int argc, const char *argv[])
{
        void    *mem;

        alarm(5);
        if (argc == 1 || !(mem = malloc(sizeof(*mem) * 5)))
                return (0);
        if (atoi(argv[1]) == 1)
        {
                memset(mem, 'e', 5);
                ft_bzero(mem, 5);
                write(1, mem, 5);
        }
        else if (atoi(argv[1]) == 2)
        {
                memset(mem, 'e', 5);
                ft_bzero(mem, 0);
                write(1, mem, 5);
        }
        return (0);
}

