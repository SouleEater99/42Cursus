/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:03:01 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/17 18:34:40 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_check_sort(t_list **stack_a, t_list **stack_b, t_list *tail)
{
    t_list      *tmp;

    tmp = *stack_a;
    while (tmp->next && ft_lstsize(tail) != 1)
    {
	//      printf("HERE | tmp %d | next_tmp : %d\n",*(int*)tmp->content, *(int*)tmp->next->content);
	if (ft_compare_node(tmp, tmp->next))
	    return (0);
	tmp = tmp->next;
    }
    if (ft_lstsize(*stack_b) == 0 && (tail == NULL  || tail == ft_lstlast(*stack_a)))
	return (1);
    return (0);
}

void	ft_sec_sort_top_a_b(t_list **stack_a, t_list **stack_b)
{
    t_list	*bigger_b;
    int	offset;

    bigger_b = ft_to_bigger(*stack_b);
    offset = ft_offset(*stack_b, bigger_b);
    ft_rotation(stack_a);
    if (offset != 1 && ft_lstsize(*stack_b) - offset + 1 > offset - 1)
    {
	ft_rotation(stack_b);
	printf("rr\n");
    }
    else if (offset == 1 && ft_lstsize(*stack_b) > 3)
    {
	bigger_b = ft_to_bigger(bigger_b->next);
	offset = ft_offset(*stack_b, bigger_b);
	if (offset != 2 && ft_lstsize(*stack_b) - offset + 1 > offset - 1)
	{
	    ft_swap(stack_b);
	    printf("sb\n");
	    ft_rotation(stack_b);
	    printf("rr\n");
	}
	else
	    printf("ra\n");

    }
    else
	printf("ra\n");
  /  printf("===BYE ft_sec_sort_top_a_b===\n");
}

void    ft_second_sort_top_a(t_list **stack_a, t_list **stack_b, t_list *tail)
{
    t_list      *bigger_a;
    t_list      *head;

    bigger_a = ft_to_bigger(tail->next);
    head = *stack_a;
    while (ft_offset(*stack_a, tail) != 1)
	ft_sec_sort_top_a_b(stack_a, stack_b);
    if (ft_offset(*stack_a, tail) == 1)
	ft_sec_sort_top_a_b(stack_a, stack_b);
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
    if (ft_lstsize(*stack_a) - ft_offset(*stack_a, head) + 1 < ft_offset(*stack_a, head) - 1)
    {
	while (ft_offset(*stack_a, head) != 1)
	{
	    ft_reverse_rotation(stack_a);
	    printf("rra\n");
	}
    }
    else
	while (ft_offset(*stack_a, head) != 1)
		ft_sec_sort_top_a_b(stack_a, stack_b);
    ft_push(stack_b, stack_a);
    printf("pa\n");
   // printf("===BYE ft_second_sort_top_a===\n");
}

void    ft_second_sort_bottom_a(t_list **stack_a, t_list **stack_b, t_list *tail)
{
    t_list      *bigger_a;

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
   // printf("===BYE ft_second_sort_bottom_a===\n");
}

void    ft_second_sort_b(t_list **stack_a, t_list **stack_b)
{
    int size;
    int offset;
    t_list      *bigger_b;

    bigger_b = ft_to_bigger(*stack_b);
    size = ft_lstsize(*stack_b);
    offset = ft_offset(*stack_b, bigger_b);
    if (offset - 1 < size - offset + 1)
    {
	while (ft_offset(*stack_b, bigger_b) != 1)
	{
	    ft_rotation(stack_b);
	    printf("rb\n");
	}
	ft_push(stack_b, stack_a);
	printf("pa\n");
    }
    else
    {
	while (ft_offset(*stack_b, bigger_b) != 1)
	{
	    if (ft_offset(*stack_b, bigger_b) != 1)
	    {
		ft_reverse_rotation(stack_b);
		printf("rrb\n");
	    }
	}
	ft_push(stack_b, stack_a);
	printf("pa\n");
    }
  //  printf("===BYE ft_second_sort_b===\n");
}

void    ft_second_sort(t_list **stack_a, t_list **stack_b, t_list *tail)
{
    int offset;
    int size;
    t_list      *bigger_a;
    t_list      *bigger_b;

    bigger_a = ft_to_bigger(tail->next);
    bigger_b = ft_to_bigger(*stack_b);
    if (ft_compare_node(bigger_a, bigger_b) && tail->next == bigger_a)
	ft_second_swap_top_element(stack_a, stack_b);
    while (!ft_check_sort(stack_a, stack_b, tail))
    {
	bigger_a = ft_to_bigger(tail->next);
	bigger_b = ft_to_bigger(*stack_b);
//	printf("ft_compare_node:%d\n",ft_compare_node(bigger_a, bigger_b));
	if (ft_compare_node(bigger_a, bigger_b))
	{

//	    printf("I AM HERE CAN YOU SEE ME\n");
	    size = ft_lstsize(*stack_a);
	    offset = ft_offset(*stack_a, bigger_a);
	    if (offset + ft_offset(*stack_a, tail) < size - offset + 1)
		ft_second_sort_top_a(stack_a, stack_b, tail);// NEW FUNCTION
	    else
		ft_second_sort_bottom_a(stack_a, stack_b, tail);// NEW FUNCTION
	}
	else
	    ft_second_sort_b(stack_a, stack_b);
	//      printf("ft_check_sort : %d\n",ft_check_sort(stack_a, stack_b, tail));
	//      printf ("offset: %d \n", ft_offset(*stack_a, bigger_a));
	//      printf("size of b: %d\n",ft_lstsize(*stack_b));
    }
}
