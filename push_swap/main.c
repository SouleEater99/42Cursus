/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:59:19 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/11 14:35:53 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_is_number(char *str)
{
        long long       count;

        count = 0;
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


	//ft_swap(&stack_a);
	//ft_push(&stack_a, &stack_b);
	//ft_rotation(&stack_a);
	ft_reverse_rotation(&stack_a);
	tmp = stack_a;
	while (tmp)
	{
		printf("stack_A :%d \n", *(int*)tmp->content);
		tmp = tmp->next;
	}
	tmp = stack_b;
	while (tmp)
	{
		printf("stack_B :%d \n", *(int*)tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}
