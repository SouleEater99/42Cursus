/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__sort_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:52:22 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/26 10:57:33 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_b_equal_top(t_list **stack_a, t_list **stack_b, t_list *near)
{
	t_list	*pos;

	pos = ft_get_pos_b(near, stack_b);
	while (ft_offset(*stack_a, near) != 1 && ft_offset(*stack_b, pos) != 1)
	{
		ft_rotation(stack_a, 'r');
		ft_rotation(stack_b, '2');
	}
}

void	ft_sort_b_equal_bottom(t_list **stack_a, t_list **stack_b, t_list *near)
{
	t_list	*pos;

	pos = ft_get_pos_b(near, stack_b);
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

int	ft_check_sort(t_list *stack_a, t_list *stack_b)
{
	if (ft_lstsize(stack_b) > 0)
		return (0);
	while (stack_a->next)
	{
		if (ft_compare_node(stack_a, stack_a->next))
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

char	*ft_strjoin_2(char *str1, char *str2)
{
	int		i;
	int		len_1;
	char	*new;

	if (!str2)
		return (NULL);
	if (!str1)
		len_1 = 0;
	else
		len_1 = ft_strlen(str1) + 1;
	i = -1;
	new = malloc(len_1 + ft_strlen(str2) + 1);
	if (!new)
		return (NULL);
	while (str1 && str1[++i])
		new[i] = str1[i];
	if (str1)
		new[i] = ' ';
	i = -1;
	while (str2[++i])
		new[len_1 + i] = str2[i];
	new[len_1 + i] = '\0';
	if (str1)
		free(str1);
	return (new);
}
