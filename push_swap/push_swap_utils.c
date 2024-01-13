/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 06:51:54 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/13 13:16:11 by ael-maim         ###   ########.fr       */
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

int     ft_check_paramters(int  ac, char **av)
{
    int i;
    int j;
    int tmp;

    i = 1;
    while (i < ac)
    {
	if (ft_check_is_number(av[i]) == -1)
	    return (-1);
	tmp = ft_atoi(av[i]);
	j = i + 1;
	while (av[j] && j < ac)
	    if (tmp == ft_atoi(av[j++]))
		return (-1);
	i++;
    }
    return (1);
}

t_list  *ft_fill_stack_a(t_list *stack_a, int ac, char **av)
{
    int i;
    int *tmp;
    t_list      *current;

    i = 1;
    tmp = (int *)malloc(sizeof(int));
    *tmp = ft_atoi(av[i++]);
    stack_a = ft_lstnew(tmp);
    while (i < ac)
    {
	tmp = NULL;
	tmp = (int *)malloc(sizeof(int));
	*tmp = ft_atoi(av[i++]);
	current = ft_lstnew(tmp);
	ft_lstadd_back(&stack_a, current);
    }
    return (stack_a);
}

int     ft_compare_node(void *value1, void *value2)
{
    if (*(int*)value1 > *(int*)value2)
	return (1);
    return (0);
}

t_list  *ft_to_bigger(t_list *stack)
{
    t_list      *tmp;
    t_list      *bigger;

    tmp = stack;
    bigger = stack;
    while (tmp->next)
    {
	if (!ft_compare_node(bigger->content, tmp->next->content))
	    bigger = tmp->next;
	tmp = tmp->next;
    }
    return (bigger);
}

int     ft_offset(t_list *stack, t_list *node)
{
    int i;

    i = 1;
    if (!stack)
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

void    ft_swap_top_element(t_list **stack_a, t_list **stack_b)
{
    int a;
    int b;

    if (*stack_b && *stack_a)
    {
	a = ft_compare_node((*stack_a)->content, (*stack_a)->next->content);
	if ((*stack_b)->next)
		b = ft_compare_node((*stack_b)->content, (*stack_b)->next->content);
	else
	    b = 1;
	if (a == 0 && b == 0)
	{
	    ft_swap(stack_b);
	    ft_swap(stack_a);
	    printf("ss\n");
	}
	else if (a == 0 && b == 1)
	{
	    ft_swap(stack_a);
	    printf("sa\n");
	}
	else if (a == 1 && b == 0)
	{
	    ft_swap(stack_b);
	    printf("sb\n");
	}
    }
}

void    ft_split_stack(t_list **stack_a, t_list **stack_b)
{
    int len;
    int i;


    i = 0;
    len = ft_lstsize(*stack_a);
    while (i < (len / 2))
    {
	ft_push(stack_a, stack_b);
	printf("pb\n");
	i++;
    }
}
