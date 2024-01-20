/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:59:19 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/20 19:21:42 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		if (ac == 2)
		{
			if (!ft_fill_stack_split(&stack_a, av))
				return (0);
		}
		else
		{
			if (ft_check_paramters(av, 'a') == -1)
				return (write(2, "Error\n", 6), 0);
			stack_a = ft_fill_stack_a(stack_a, av, 'a');
		}
		ft_sort_stack(&stack_a, &stack_b);
		ft_lstclear(&stack_a, free);
		ft_lstclear(&stack_b, free);
	}
}
