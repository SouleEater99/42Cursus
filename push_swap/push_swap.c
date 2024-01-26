/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:59:19 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/24 15:55:17 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (ft_check_sort(stack_a, stack_b) == 1)
			return (ft_lstclear(&stack_a, free), 0);
		ft_sort_stack(&stack_a, &stack_b);
		ft_lstclear(&stack_a, free);
		ft_lstclear(&stack_b, free);
	}
}
