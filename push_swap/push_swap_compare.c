/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_compare.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:42:33 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/20 14:43:36 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_compare_node(t_list *value1, t_list *value2)
{
	if (ft_lstsize(value2) == 0)
		return (1);
	if (ft_lstsize(value1) == 0)
		return (0);
	if (*(int *)value1->content > *(int *)value2->content)
		return (1);
	return (0);
}

t_list	*ft_to_lower(t_list *stack)
{
	t_list	*tmp;
	t_list	*lower;

	if (ft_lstsize(stack) == 0)
		return (NULL);
	tmp = stack;
	lower = stack;
	while (tmp->next)
	{
		if (ft_compare_node(lower, tmp->next))
			lower = tmp->next;
		tmp = tmp->next;
	}
	return (lower);
}

t_list	*ft_to_bigger(t_list *stack)
{
	t_list	*tmp;
	t_list	*bigger;

	if (ft_lstsize(stack) == 0)
		return (NULL);
	tmp = stack;
	bigger = stack;
	while (tmp->next)
	{
		if (!ft_compare_node(bigger, tmp->next))
			bigger = tmp->next;
		tmp = tmp->next;
	}
	return (bigger);
}

int	ft_offset(t_list *stack, t_list *node)
{
	int	i;

	i = 1;
	if (ft_lstsize(stack) == 0)
		return (0);
	while (stack != node)
	{
		stack = stack->next;
		i++;
		if (!stack)
			return (0);
	}
	return (i);
}
