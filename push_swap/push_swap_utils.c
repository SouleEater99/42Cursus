/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 06:51:54 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/19 11:55:26 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_check_is_number(char *str)
{
    long long       count;

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

int     ft_check_paramters(char **av, char c)
{
    int i;
    int j;
    int tmp;

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

t_list  *ft_fill_stack_a(t_list *stack_a, char **av, char c)
{
    int i;
    int *tmp;
    t_list      *current;

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

int     ft_compare_node(t_list *value1, t_list *value2)
{
    if (ft_lstsize(value2) == 0)
	return (1);
    if (ft_lstsize(value1) == 0)
	return (0);
    if (*(int*)value1->content > *(int*)value2->content)
	return (1);
    return (0);
}

t_list  *ft_to_lower(t_list *stack)
{
    t_list      *tmp;
    t_list      *lower;

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

t_list  *ft_to_bigger(t_list *stack)
{
    t_list      *tmp;
    t_list      *bigger;

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

int     ft_offset(t_list *stack, t_list *node)
{
    int i;

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

t_list  *ft_get_pos_b(t_list *target, t_list **stack_b)
{
    t_list      *tmp;

    tmp = *stack_b;
    if (ft_lstsize(tmp) < 2)
	return (NULL);
    while (tmp)
    {
	if (ft_compare_node(target, tmp))
	    return (tmp);
	tmp = tmp->next;
    }
    return (ft_lstlast(*stack_b));
}

void    ft_sort_stack_b(t_list  **stack_a, t_list **stack_b, t_list *near)
{
    int 	offset_a;
    int 	offset_b;
    int		size_a;
    int		size_b;
    t_list	*pos;

    pos = ft_get_pos_b(near, stack_b);
    offset_a = ft_offset(*stack_a, near);
    offset_b = ft_offset(*stack_b, pos);
    size_a = ft_lstsize(*stack_a);
    size_b = ft_lstsize(*stack_b);
    {
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
    t_list      *tmp;

    tmp = *stack_a;
    while (tmp->next && ft_lstsize(tail) != 1)
    {
	if (ft_compare_node(tmp, tmp->next))
	    return (0);
	tmp = tmp->next;
    }
    if (ft_lstsize(*stack_b) == 0 && (tail == NULL  || tail == ft_lstlast(*stack_a)))
	return (1);
    return (0);
}
