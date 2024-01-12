/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:59:19 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/12 17:45:36 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_a_bottom(t_list **stack_a, t_list **stack_b)
{
    t_list	*bigger_a;
    t_list	*bigger_b;
    int		offset;
    int		size;

    bigger_a = ft_to_bigger(*stack_a); 
    bigger_b = ft_to_bigger(*stack_b);
    while (ft_offset(*stack_a, bigger_a) != 1)
    {
	offset = ft_offset(*stack_b, bigger_b);
	size = ft_lstsize(*stack_b);
	ft_reverse_rotation(stack_a);
	if (size - offset + 1 <= offset - 1 && offset != 1 )
	{
	    ft_reverse_rotation(stack_b);
	    printf("rrr\n");
	}
	else
	    printf("rra\n");
	if (ft_offset(*stack_a, bigger_a) != 1)
	    ft_swap_top_element(stack_a, stack_b);
    }
}

void	ft_sort_a_top(t_list **stack_a, t_list **stack_b)
{
    t_list	*bigger_a;
    t_list	*bigger_b;
    int		offset;
    int		size;

    bigger_a = ft_to_bigger(*stack_a); 
    bigger_b = ft_to_bigger(*stack_b);
    while (ft_offset(*stack_a, bigger_a) != 1)
    {
	offset = ft_offset(*stack_b, bigger_b);
	size = ft_lstsize(*stack_b);
	ft_rotation(stack_a);
	if (size - offset + 1 > offset - 1 && offset != 1)
	{
	    ft_reverse_rotation(stack_b);
	    printf("rr\n");
	}
	else
	    printf("ra\n");
	if (ft_offset(*stack_a, bigger_a) != 1)
	    ft_swap_top_element(stack_a, stack_b);
    }
}

void	ft_sort_b_bottom(t_list **stack_a, t_list **stack_b)
{
    t_list	*bigger_a;
    t_list	*bigger_b;
    int		offset;
    int		size;

    bigger_a = ft_to_bigger(*stack_a); 
    bigger_b = ft_to_bigger(*stack_b);
    while (ft_offset(*stack_b, bigger_b) != 1 && ft_offset(*stack_b, bigger_b) != 0)
    {
	offset = ft_offset(*stack_a, bigger_a);
	size = ft_lstsize(*stack_a);
	ft_reverse_rotation(stack_b);
	if (size - offset + 1 <= offset - 1 && offset != 1 )
	{
	    ft_reverse_rotation(stack_a);
	    printf("rrr\n");
	}
	else
	    printf("rrb\n");
	if (ft_offset(*stack_b, bigger_b) != 1)
	    ft_swap_top_element(stack_a, stack_b);
    }
    if (ft_offset(*stack_b, bigger_b) == 1)
    {
	ft_push(stack_b, stack_a);
	printf("pa\n");
    }
}

void	ft_sort_b_top(t_list **stack_a, t_list **stack_b)
{
    t_list	*bigger_a;
    t_list	*bigger_b;
    int		offset;
    int		size;

    bigger_a = ft_to_bigger(*stack_a); 
    bigger_b = ft_to_bigger(*stack_b);
    while (ft_offset(*stack_b, bigger_b) != 1 && ft_offset(*stack_b, bigger_b) != 0)
    {
	offset = ft_offset(*stack_a, bigger_a);
	size = ft_lstsize(*stack_a);
	ft_rotation(stack_b);
	if (size - offset + 1 > offset - 1 && offset != 1 )
	{
	    ft_rotation(stack_a);
	    printf("rr\n");
	}
	else
	    printf("rb\n");
	if (ft_offset(*stack_b, bigger_b) != 1)
	    ft_swap_top_element(stack_a, stack_b);
    }
    if (ft_offset(*stack_b, bigger_b) == 1)
    {
	ft_push(stack_b, stack_a);
	printf("pa\n");
    }
}

void	ft_first_sort(t_list **stack_a, t_list **stack_b)
{
    t_list	*bigger_a;
    t_list	*bigger_b;
    int		offset;
    int		size;

    ft_swap_top_element(stack_a, stack_b);
    bigger_a = ft_to_bigger(*stack_a); 
    bigger_b = ft_to_bigger(*stack_b);
    offset = ft_offset(*stack_a, bigger_a);
    size = ft_lstsize(*stack_a);
    if (ft_compare_node(bigger_a->content, bigger_b->content))
    {
	if (size - offset + 1 <= offset - 1)
	    ft_sort_a_bottom(stack_a, stack_b);
	else
	    ft_sort_a_top(stack_a, stack_b);
    }
    else
    {
	size = ft_lstsize(*stack_b);
	offset = ft_offset(*stack_b, bigger_b);
	if (size - offset + 1 <= offset - 1)
	    ft_sort_b_bottom(stack_a, stack_b);
	else
	    ft_sort_b_top(stack_a, stack_b);
    }
}

int	main(int ac, char **av)
{
    t_list	*stack_a = NULL;
    t_list	*stack_b = NULL;
    t_list	*tail;
    t_list	*tmp;

    if (ft_check_paramters(ac, av) == -1)
    {
	printf("error");
	return (0); /// i need here a message on stdout error;
    }
    stack_a = ft_fill_stack_a(stack_a, ac, av);
    if (!ft_compare_node(stack_a->content, stack_a->next->content))
    {
	ft_swap(&stack_a);
	printf("sa\n");
    }
    ft_split_stack(&stack_a, &stack_b);
    ft_first_sort(&stack_a, &stack_b);
    tail = stack_a;













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
