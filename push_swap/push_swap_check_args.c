/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:40:58 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/21 12:19:50 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_is_number(char *str)
{
	long long	count;

	count = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		count = (count * 10) + (*str - '0');
		if (count > 2147483647 || count < -2147483648)
			return (-1);
		str++;
	}
	if (*str)
		return (-1);
	return (1);
}

int	ft_check_paramters(char **av, char c)
{
	int	i;
	int	j;
	int	tmp;

	if (c == 's')
		i = 0;
	else
		i = 1;
	while (av[i])
	{
		if (ft_check_is_number(av[i]) == -1)
			return (-1);
		tmp = ft_atoi(av[i]);
		j = i + 1;
		while (av[j])
			if (tmp == ft_atoi(av[j++]))
				return (-1);
		i++;
	}
	return (1);
}

t_list	*ft_fill_stack_a(t_list *stack_a, char **av, char c)
{
	int		i;
	int		*tmp;
	t_list	*current;

	if (c == 's')
		i = 0;
	else
		i = 1;
	tmp = (int *)malloc(sizeof(int));
	if (!tmp)
		return (NULL);
	*tmp = ft_atoi(av[i++]);
	stack_a = ft_lstnew(tmp);
	while (av[i])
	{
		tmp = NULL;
		tmp = (int *)malloc(sizeof(int));
		if (!tmp)
			return (NULL);
		*tmp = ft_atoi(av[i++]);
		current = ft_lstnew(tmp);
		ft_lstadd_back(&stack_a, current);
	}
	return (stack_a);
}

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	ft_fill_stack_split(t_list **stack_a, char **av)
{
	char	**tab;
	t_list	*tmp;

	tab = NULL;
	tmp = *stack_a;
	tab = ft_split(av[1], ' ');
	if (!tab || !tab[0] || ft_check_paramters(tab, 's') == -1)
		return (write(2, "Error\n", 6), ft_free(tab), 0);
	*stack_a = ft_fill_stack_a(tmp, tab, 's');
	ft_free(tab);
	return (1);
}
