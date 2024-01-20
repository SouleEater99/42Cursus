/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__sort_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:52:22 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/20 18:52:54 by ael-maim         ###   ########.fr       */
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

void	ft_sort_b_equal_bottom(t_list **stack_a, t_list **stack_b, t_list *near)
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
		ft_reverse_rotation(stack_a, 'r');
		ft_reverse_rotation(stack_b, '2');
	}
}

void	ft_sort_b_remain(t_list **stack_a, t_list **stack_b, t_list *near)
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