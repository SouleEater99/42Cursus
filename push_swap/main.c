/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:59:19 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/11 18:01:40 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_is_number(char *str)
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

int	ft_check_paramters(int	ac, char **av)
{
    int	i;
    int	j;
    int	tmp;

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

t_list	*ft_fill_stack_a(t_list *stack_a, int ac, char **av)
{
    int	i;
    int	*tmp;
    t_list	*current;

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

void	ft_swap(t_list **stack)
{
    t_list	*tmp;

    if (ft_lstsize(*stack) >= 2)
    {
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
    }	
}

void	ft_push(t_list **stack_1, t_list **stack_2)
{
    t_list	*tmp;
    t_list	*tmp2;
    if (*stack_1)
    {
	tmp = (*stack_1)->next;
	tmp2 = *stack_1;
	tmp2->next = *stack_2;
	*stack_2 = tmp2;
	*stack_1 = tmp;
    }
}

void	ft_rotation(t_list **stack)
{
    t_list	*tmp;

    tmp = ft_lstlast(*stack);
    tmp->next = *stack;
    tmp = (*stack)->next;
    (*stack)->next = NULL;
    *stack = tmp;
}

void	ft_reverse_rotation(t_list **stack)
{
    t_list	*last;
    t_list	*before_last;

    if ((*stack)->next)
    {
	last = ft_lstlast(*stack);
	before_last = *stack;
	while (before_last->next && before_last->next != last)
	    before_last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
    }
}

int	ft_compare_node(void *value1, void *value2)
{
    if (*(int*)value1 > *(int*)value2)
	return (1);
    return (0);
}

t_list	*ft_to_lower(t_list *stack)
{
    t_list	*tmp;
    t_list	*lower;

    tmp = stack;
    lower = stack;
    while (tmp->next)
    {
	if (ft_compare_node(lower->content, tmp->next->content))
	    lower = tmp->next;
	tmp = tmp->next;
    }
    return (lower);
}

int	ft_offset(t_list *stack, t_list *node)
{
    int	i;

    i = 0;
    while (stack != node)
    {
	stack = stack->next;
	i++;
    }
    return (i);
}

void	ft_swap_top_element(t_list **stack_a, t_list **stack_b)
{
    int	a;
    int	b;

    if (*stack_b && *stack_a)
    {
	a = ft_compare_node((*stack_a)->content, (*stack_a)->next->content);
	b = ft_compare_node((*stack_b)->content, (*stack_b)->next->content);
	if (a == 0 && b == 1)
	{
	    ft_swap(stack_b);
	    ft_swap(stack_a);
	    printf("ss\n");
	}
	else if (a == 0 && b == 0)
	{
	    ft_swap(stack_a);
	    printf("sa\n");
	}
	else if (a == 1 && b == 1)
	{
	    ft_swap(stack_b);
	    printf("sb\n");
	}
    }
}

void	ft_split_stack(t_list **stack_a, t_list **stack_b)
{
    int	len;
    int	i;


    i = 0;
    len = ft_lstsize(*stack_a);
    while (i < (len / 2))
    {
	ft_push(stack_a, stack_b);
	printf("pb\n");
	i++;
    }
}

int	main(int ac, char **av)
{
    t_list	*stack_a = NULL;
    t_list	*stack_b = NULL;
    t_list	*tmp;


    if (ft_check_paramters(ac, av) == -1)
    {
	printf("error");
	return (0); /// i need here a message on stdout error;
    }
    stack_a = ft_fill_stack_a(stack_a, ac, av);

    ft_split_stack(&stack_a, &stack_b);
    ft_swap_top_element(&stack_a, &stack_b);
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
    ft_lstclear(&stack_a, free);
    ft_lstclear(&stack_b, free);
}
