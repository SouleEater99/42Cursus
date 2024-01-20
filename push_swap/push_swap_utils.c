/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 06:51:54 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/20 19:07:33 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_get_pos_a(t_list *target, t_list **stack_a)
{
	t_list	*tmp;
	t_list	*lower;
	t_list	*bigger;

	tmp = *stack_a;
	bigger = ft_to_bigger(*stack_a);
	lower = ft_to_lower(*stack_a);
	if (!ft_compare_node(target, lower) || ft_compare_node(target, bigger))
		return (lower);
	while (lower)
	{
		if (!ft_compare_node(target, lower))
			return (lower);
		lower = lower->next;
	}
	lower = ft_to_lower(*stack_a);
	while (tmp && tmp != lower)
	{
		if (!ft_compare_node(target, tmp))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_list	*ft_get_pos_b(t_list *target, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*lower;
	t_list	*bigger;

	tmp = *stack_b;
	if (ft_lstsize(tmp) < 2)
		return (NULL);
	bigger = ft_to_bigger(*stack_b);
	lower = ft_to_lower(*stack_b);
	if (!ft_compare_node(target, lower) || ft_compare_node(target, bigger))
		return (bigger);
	while (bigger)
	{
		if (ft_compare_node(target, bigger))
			return (bigger);
		bigger = bigger->next;
	}
	bigger = ft_to_bigger(*stack_b);
	while (tmp && tmp != bigger)
	{
		if (ft_compare_node(target, tmp))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int	ft_move_number_top(t_list **stack_a, t_list **stack_b, t_list *target)
{
	int	top_a;
	int	top_b;
	int	offset;

	offset = ft_offset(*stack_a, target);
	top_a = offset - 1;
	offset = ft_offset(*stack_b, ft_get_pos_b(target, stack_b));
	top_b = offset - 1;
	if (top_a == 0)
		return (top_b + 1);
	else if (top_b == 0)
		return (top_a + 1);
	else if (top_a < top_b)
		return ((top_b - top_a) + top_b + 1);
	else if (top_a > top_b)
		return ((top_a - top_b) + top_a + 1);
	return (top_a + 1);
}

int	ft_move_number_bottom(t_list **stack_a, t_list **stack_b, t_list *target)
{
	int	bottom_a;
	int	bottom_b;
	int	offset;

	offset = ft_offset(*stack_a, target);
	bottom_a = ft_lstsize(*stack_a) - offset + 1;
	offset = ft_offset(*stack_b, ft_get_pos_b(target, stack_b));
	bottom_b = ft_lstsize(*stack_b) - offset + 1;
	if (bottom_a == 0)
		return (bottom_b + 1);
	else if (bottom_b == 0)
		return (bottom_a + 1);
	else if (bottom_a < bottom_b)
		return ((bottom_b - bottom_a) + bottom_b + 1);
	else if (bottom_a > bottom_b)
		return ((bottom_a - bottom_b) + bottom_a + 1);
	return (bottom_a + 1);
}

int	ft_move_number(t_list **stack_a, t_list **stack_b, t_list *target)
{
	int	top_a;
	int	top_b;
	int	bottom_a;
	int	bottom_b;
	int	offset;

	offset = ft_offset(*stack_a, target);
	top_a = offset - 1;
	bottom_a = ft_lstsize(*stack_a) - offset + 1;
	offset = ft_offset(*stack_b, ft_get_pos_b(target, stack_b));
	top_b = offset - 1;
	bottom_b = ft_lstsize(*stack_b) - offset + 1;
	if (bottom_a >= top_a && bottom_b >= top_b)
		return (ft_move_number_top(stack_a, stack_b, target));
	else if (bottom_a <= top_a && bottom_b <= top_b)
		return (ft_move_number_bottom(stack_a, stack_b, target));
	else if (bottom_a >= top_a && bottom_b <= top_b)
		return (top_a + bottom_b + 1);
	else if (bottom_a <= top_a && bottom_b >= top_b)
		return (bottom_a + top_b + 1);
	return (0);
}
