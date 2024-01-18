/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:03:14 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/18 12:29:42 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void    ft_sort_a_bottom(t_list **stack_a, t_list **stack_b)
{
    t_list      *bigger_a;
    t_list      *bigger_b;
    int         offset;
    int         size;

    bigger_a = ft_to_bigger(*stack_a);
    bigger_b = ft_to_bigger(*stack_b);
    while (ft_offset(*stack_a, bigger_a) != 1)
    {
        ft_swap_top_element(stack_a, stack_b);
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
    }
   // printf("===BYE ft_sort_a_bottom===\n");
}

void    ft_sort_a_top(t_list **stack_a, t_list **stack_b)
{
    t_list      *bigger_a;
    t_list      *bigger_b;
    int         offset;
    int         size;

    bigger_a = ft_to_bigger(*stack_a);
    bigger_b = ft_to_bigger(*stack_b);
    while (ft_offset(*stack_a, bigger_a) != 1)
    {
        ft_second_swap_top_element(stack_a, stack_b);
        offset = ft_offset(*stack_b, bigger_b);
        size = ft_lstsize(*stack_b);
        ft_rotation(stack_a);
        if (size - offset + 1 > offset - 1 && offset != 1)
        {
            ft_rotation(stack_b);
            printf("rr\n");
        }
        else
            printf("ra\n");
    }
    //printf("===BYE ft_sort_a_top===\n");
}

void    ft_sort_b_bottom(t_list **stack_a, t_list **stack_b)
{
    t_list      *bigger_a;
    t_list      *bigger_b;
    int         offset;
    int         size;

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
   // printf("===BYE ft_sort_b_bottom===\n");
}

void    ft_sort_b_top(t_list **stack_a, t_list **stack_b)
{
    t_list      *bigger_a;
    t_list      *bigger_b;
    int         offset;
    int         size;

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
   // printf("===BYE ft_sort_b_top===\n");
}

void    ft_first_sort(t_list **stack_a, t_list **stack_b)
{
    t_list      *bigger_a;
    t_list      *bigger_b;
    int         offset;
    int         size;

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
  //  printf("===BYE ft_first_sort===\n");
}
