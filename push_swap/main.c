/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:59:19 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/18 18:21:48 by ael-maim         ###   ########.fr       */
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

void	ft_sort_3(t_list **stack_a)
{
	t_list	*bigger;
	int	offset;

	bigger = ft_to_bigger(*stack_a);
	offset = ft_offset(*stack_a, bigger);
	if (offset != 3)
	{
	    if (ft_lstsize(*stack_a) - offset >= offset)
		ft_rotation(stack_a, 'a');
	    else
		ft_reverse_rotation(stack_a, 'a');
	}
	if (ft_compare_node(*stack_a, (*stack_a)->next))
	    ft_swap(stack_a, 'a');
}

// /*

t_list	*ft_near_node(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*save;
	int	lower;
	int	offset;

	tmp = *stack_a;
	while (tmp)
	{
		offset = ft_offset(stack_a, tmp);
		
	}
}

void	ft_sort_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*near;
	int	offset;

	if (ft_lstsize(*stack_a) <= 3)
	    ft_sort_3(stack_a);
	else
	{
		while (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_b) < 2)
		    ft_push(stack_a, stack_b, 'b');
		near = ft_near_node(stack_a, stack_b);
		offset = ft_offset(stack_a);

	}
}

// */

int	main(int ac, char **av)
{
    t_list	*stack_a;
    t_list	*stack_b;
    char	**tab;

    tab = NULL;
    stack_a = NULL;
    if (ac >= 2)
    {
	if (ac == 2)
	{
	    tab = ft_split(av[1], ' ');
	    if (ft_check_paramters(tab, 's') == -1)
		return (write (2,"Error\n",6), ft_free(tab), 0);
	    stack_a = ft_fill_stack_a(stack_a, tab, 's');
	    ft_free(tab);
	}
	else
	{
	    if (ft_check_paramters(av, 'a') == -1)
		return (write (2,"Error\n",6), 0);
	    stack_a = ft_fill_stack_a(stack_a, av, 'a');
	}



//	/*
	t_list    *tmp;
	printf("---------------------------------\n");
	tmp = stack_a;
	while (tmp)
	{
	printf("stack_A :%d \n", *(int*)tmp->content);
	tmp = tmp->next;
	}
	tmp = stack_b;
	printf("---------------------------------\n");
	while (tmp)
	{
	printf("stack_B :%d \n", *(int*)tmp->content);
	tmp = tmp->next;
	}
	//  */
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);


    }



}
