/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:09:56 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/20 13:10:14 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_offset(t_list *stack, t_list *node)
{
        int     i;

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

t_list  *ft_get_pos_a(t_list *target, t_list **stack_a)
{
        t_list  *tmp;
        t_list  *lower;
        t_list  *bigger;

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

t_list  *ft_get_pos_b(t_list *target, t_list **stack_b)
{
        t_list  *tmp;
        t_list  *lower;
        t_list  *bigger;

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

void    ft_sort_stack_b(t_list **stack_a, t_list **stack_b, t_list *near)
{
        int             offset_a;
        int             offset_b;
        int             size_a;
        int             size_b;
        t_list  *pos;

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
        else if (size_a - offset_a + 1 <= offset_a - 1 &&
                                size_b - offset_b + 1 <= offset_b - 1)
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

int     ft_check_sort(t_list **stack_a, t_list **stack_b, t_list *tail)
{
        t_list  *tmp;

        tmp = *stack_a;
        while (tmp->next && ft_lstsize(tail) != 1)
        {
                if (ft_compare_node(tmp, tmp->next))
                        return (0);
                tmp = tmp->next;
        }
        if (ft_lstsize(*stack_b) == 0 && (tail == NULL
                        || tail == ft_lstlast(*stack_a)))
                return (1);
        return (0);
}
