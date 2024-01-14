/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:59:19 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/14 13:15:29 by ael-maim         ###   ########.fr       */
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
    printf("===BYE ft_sort_a_bottom===\n");
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
    printf("===BYE ft_sort_a_top===\n");
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
    printf("===BYE ft_sort_b_bottom===\n");
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
    printf("===BYE ft_sort_b_top===\n");
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
    if (ft_compare_node(bigger_a, bigger_b))
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
    printf("===BYE ft_first_sort===\n");
}

int	ft_check_sort(t_list **stack_a, t_list **stack_b, t_list *tail)
{
    t_list	*tmp;

    tmp = *stack_a;
    while (tmp->next)
    {
    	printf("HERE | tmp %d | next_tmp : %d\n",*(int*)tmp->content, *(int*)tmp->next->content);
	if (ft_compare_node(tmp, tmp->next))
	    return (0);
	tmp = tmp->next;
    }
    printf("HERE\n");
    if (ft_lstsize(*stack_b) == 0 && (tail == NULL  || tail == ft_lstlast(*stack_a)))
	return (1);
    return (0);
}

void	ft_second_sort_top_a(t_list **stack_a, t_list **stack_b, t_list *tail)
{
    t_list	*bigger_a;

    bigger_a = ft_to_bigger(tail->next);
    while (ft_offset(*stack_a, tail) != 1)
    {
	ft_rotation(stack_a);
	printf("ra\n");
    }
    if (ft_offset(*stack_a, tail) == 1)
    {
	ft_rotation(stack_a);
	printf("ra\n");
    }
    while (ft_offset(*stack_a, bigger_a) != 1)
    {
	ft_second_swap_top_element(stack_a, stack_b);
	if (ft_offset(*stack_a, bigger_a) != 1)
	{
	    ft_push(stack_a, stack_b);
	    printf("pb\n");
	}	
    }
    ft_push(stack_a, stack_b);
    printf("pb\n");
    while (ft_offset(*stack_a, tail) != 1)
    {
	ft_reverse_rotation(stack_a);
	printf("rra\n");
    }
    ft_push(stack_b, stack_a);
    printf("pa\n");
    printf("===BYE ft_second_sort_top_a===\n");
}

void	ft_second_sort_bottom_a(t_list **stack_a, t_list **stack_b, t_list *tail)
{
    t_list	*bigger_a;

    bigger_a = ft_to_bigger(tail->next);
    if (ft_lstlast(*stack_a) != tail)
    {
	ft_reverse_rotation(stack_a);
	printf("rra\n");
    }
    while (ft_offset(*stack_a, bigger_a) != 1)
    {
	ft_reverse_rotation(stack_a);
	printf("rra\n");
	if (ft_compare_node(*stack_a, (*stack_a)->next))
	{
	    ft_swap(stack_a);
	    printf("sa\n");
	}
	ft_push(stack_a, stack_b);
	printf("pb\n");
	ft_second_swap_top_element(stack_a, stack_b);
    }
    printf("===BYE ft_second_sort_bottom_a===\n");
}

void	ft_second_sort_b(t_list **stack_a, t_list **stack_b)
{
    int	size;
    int	offset;
    t_list	*bigger_b;

    bigger_b = ft_to_bigger(*stack_b);
    size = ft_lstsize(*stack_b);
    offset = ft_offset(*stack_b, bigger_b);
    if (offset - 1 > size - offset + 1)
    {
	while (ft_offset(*stack_b, bigger_b) != 1)
	{
	    ft_rotation(stack_b);
	    printf("rb\n");
	    ft_second_swap_top_element(stack_a, stack_b);
	}
	ft_push(stack_b, stack_a);
	printf("pa\n");
    }
    else
    {
	while (ft_offset(*stack_b, bigger_b) != 1)
	{
	    ft_second_swap_top_element(stack_a, stack_b);
	    if (ft_offset(*stack_b, bigger_b) != 1)
	    {
		ft_reverse_rotation(stack_b);
		printf("rrb\n");
	    }
	}
	ft_push(stack_b, stack_a);
	printf("pa\n");
    }
    printf("===BYE ft_second_sort_b===\n");
}

void	ft_second_sort(t_list **stack_a, t_list **stack_b, t_list *tail)
{
    int	offset;
    int	size;
    t_list	*bigger_a;
    t_list	*bigger_b;

    bigger_a = ft_to_bigger(tail->next);
    bigger_b = ft_to_bigger(*stack_b);
    if (ft_compare_node(bigger_a, bigger_b) && tail->next == bigger_a)
	ft_second_swap_top_element(stack_a, stack_b);
    while (!ft_check_sort(stack_a, stack_b, tail))
    {
	bigger_a = ft_to_bigger(tail->next);
	bigger_b = ft_to_bigger(*stack_b);
	if (ft_compare_node(bigger_a, bigger_b) || ft_lstsize(*stack_b) == 0)
	{
	    size = ft_lstsize(*stack_a);
	    offset = ft_offset(*stack_a, bigger_a);
	    if (offset + ft_offset(*stack_a, tail) < size - offset + 1)
		ft_second_sort_top_a(stack_a, stack_b, tail);// NEW FUNCTION
	    else
		ft_second_sort_bottom_a(stack_a, stack_b, tail);// NEW FUNCTION
	}
	else
	    ft_second_sort_b(stack_a, stack_b);
    printf("ft_check_sort : %d\n",ft_check_sort(stack_a, stack_b, tail));
    }
}

int	main(int ac, char **av)
{
    t_list	*stack_a = NULL;
    t_list	*stack_b = NULL;
    t_list	*tail = NULL;

    if (ft_check_paramters(ac, av) == -1)
    {
	printf("error");
	return (0); /// i need here a message on stdout error;
    }
    stack_a = ft_fill_stack_a(stack_a, ac, av);
    printf("ft_check_sort first: %d\n",ft_check_sort(&stack_a, &stack_b, tail));

    if (ft_check_sort(&stack_a, &stack_b, tail))
    {
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (1);
    }
    if (!ft_compare_node(stack_a, stack_a->next))
    {
	ft_swap(&stack_a);
	printf("sa\n");
    }
    ft_split_stack(&stack_a, &stack_b);
    ft_first_sort(&stack_a, &stack_b);
    tail = stack_a;
    printf("tail : %d\n", *(int*)tail->content);
    ft_second_sort(&stack_a, &stack_b, tail);










    printf("ft_check_sort : %d\n",ft_check_sort(&stack_a, &stack_b, tail));
    // /*
    t_list	*tmp;
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
    //  */
    ft_lstclear(&stack_a, free);
    ft_lstclear(&stack_b, free);
}
