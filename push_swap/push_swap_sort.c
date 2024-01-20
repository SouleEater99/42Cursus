/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:44:56 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/20 18:38:38 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_b_equal_top(t_list **stack_a, t_list **stack_b, t_list *near)
{
    int		offset_a;
    int		offset_b;
    int		size_a;
    int		size_b;
    t_list	*pos;

    pos = ft_get_pos_b(near, stack_b);
    offset_a = ft_offset(*stack_a, near);
    offset_b = ft_offset(*stack_b, pos);
    size_a = ft_lstsize(*stack_a);
    size_b = ft_lstsize(*stack_b);
    while (ft_offset(*stack_a, near) != 1 && ft_offset(*stack_b, pos) != 1)
    {
	ft_rotation(stack_a, 'r');
	ft_rotation(stack_b, '2');
    }
}

void	ft_sort_stack_b(t_list **stack_a, t_list **stack_b, t_list *near)
{
    int		offset_a;
    int		offset_b;
    int		size_a;
    int		size_b;
    t_list	*pos;

    pos = ft_get_pos_b(near, stack_b);
    offset_a = ft_offset(*stack_a, near);
    offset_b = ft_offset(*stack_b, pos);
    size_a = ft_lstsize(*stack_a);
    size_b = ft_lstsize(*stack_b);
    if (size_a - offset_a + 1 > offset_a - 1 &&
	    size_b - offset_b + 1 > offset_b - 1)
    {
	while (ft_offset(*stack_a, near) != 1 && ft_offset(*stack_b, pos) != 1)
	{
	    ft_rotation(stack_a, 'r');
	    ft_rotation(stack_b, '2');
	}
    }
    else if (size_a - offset_a + 1 <= offset_a - 1 && size_b - offset_b + 1 <= offset_b - 1)
    {
	while (ft_offset(*stack_a, near) != 1 && ft_offset(*stack_b, pos) != 1)
	{
	    ft_reverse_rotation(stack_a, 'r');
	    ft_reverse_rotation(stack_b, '2');
	}
    }
    if (size_a - offset_a + 1 > offset_a - 1)
	while (ft_offset(*stack_a, near) != 1)
	    ft_rotation(stack_a, 'a');
    else if (size_a - offset_a + 1 <= offset_a - 1)
	while (ft_offset(*stack_a, near) != 1)
	    ft_reverse_rotation(stack_a, 'a');
    if (size_b - offset_b + 1 > offset_b - 1)
	while (ft_offset(*stack_b, pos) != 1)
	    ft_rotation(stack_b, 'b');
    else if (size_b - offset_b + 1 <= offset_b - 1)
	while (ft_offset(*stack_b, pos) != 1)
	    ft_reverse_rotation(stack_b, 'b');
    if (ft_offset(*stack_a, near) == 1)
	ft_push(stack_a, stack_b, 'b');
}

void	ft_sort_3(t_list **stack_a)
{
    t_list	*bigger;
    int		offset;

    bigger = ft_to_bigger(*stack_a);
    offset = ft_offset(*stack_a, bigger);
    if (offset != 3 && ft_lstsize(*stack_a) > 2)
    {
	if (ft_lstsize(*stack_a) - offset >= offset)
	    ft_rotation(stack_a, 'a');
	else
	    ft_reverse_rotation(stack_a, 'a');
    }
    if (ft_compare_node(*stack_a, (*stack_a)->next))
	ft_swap(stack_a, 'a');
}

void	ft_sort_stack_a(t_list **stack_a, t_list **stack_b)
{
    int		offset;
    t_list	*pos;

    pos = ft_get_pos_a(*stack_b, stack_a);
    offset = ft_offset(*stack_a, pos);
    if (ft_lstsize(*stack_a) - offset + 1 > offset - 1)
    {
	while (ft_offset(*stack_a, pos) != 1)
	    ft_rotation(stack_a, 'a');
    }
    else
	while (ft_offset(*stack_a, pos) != 1)
	    ft_reverse_rotation(stack_a, 'a');
    ft_push(stack_b, stack_a, 'a');
}

void	ft_sort_stack(t_list **stack_a, t_list **stack_b)
{
    t_list	*near;
    int		offset;

    if (ft_lstsize(*stack_a) <= 3)
	ft_sort_3(stack_a);
    else
    {
	while (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_b) < 2)
	    ft_push(stack_a, stack_b, 'b');
	while (ft_lstsize(*stack_a) > 3)
	{
	    near = ft_near_node(stack_a, stack_b);
	    ft_sort_stack_b(stack_a, stack_b, near);
	}
	ft_sort_3(stack_a);
	while (ft_lstsize(*stack_b) > 0)
	    ft_sort_stack_a(stack_a, stack_b);
	offset = ft_offset(*stack_a, ft_to_lower(*stack_a));
	if (ft_lstsize(*stack_a) - offset + 1 >= offset - 1)
	    while (ft_offset(*stack_a, ft_to_lower(*stack_a)) != 1)
		ft_rotation(stack_a, 'a');
	else
	    while (ft_offset(*stack_a, ft_to_lower(*stack_a)) != 1)
		ft_reverse_rotation(stack_a, 'a');
    }
}
