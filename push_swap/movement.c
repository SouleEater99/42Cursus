/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 06:48:31 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/12 06:50:29 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap(t_list **stack)
{
    t_list      *tmp;

    if (ft_lstsize(*stack) >= 2)
    {
        tmp = (*stack)->next;
        (*stack)->next = tmp->next;
        tmp->next = *stack;
        *stack = tmp;
    }
}

void    ft_push(t_list **stack_1, t_list **stack_2)
{
    t_list      *tmp;
    t_list      *tmp2;
    if (*stack_1)
    {
        tmp = (*stack_1)->next;
        tmp2 = *stack_1;
        tmp2->next = *stack_2;
        *stack_2 = tmp2;
        *stack_1 = tmp;
    }
}

void    ft_rotation(t_list **stack)
{
    t_list      *tmp;

    tmp = ft_lstlast(*stack);
    tmp->next = *stack;
    tmp = (*stack)->next;
    (*stack)->next = NULL;
    *stack = tmp;
}

void    ft_reverse_rotation(t_list **stack)
{
    t_list      *last;
    t_list      *before_last;

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
