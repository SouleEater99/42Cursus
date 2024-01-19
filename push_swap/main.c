/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:59:19 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/19 17:55:08 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **tab)
{
    int	i;

    i = 0;
    while (tab[i])
	free(tab[i++]);
    free(tab);
}

void	ft_sort_3(t_list **stack_a)
{
    t_list	*bigger;
    int	offset;

    bigger = ft_to_bigger(*stack_a);
    offset = ft_offset(*stack_a, bigger);
    if (offset != 3)
    {
	if (ft_lstsize(*stack_a) - offset >= offset)
	    ft_rotation(stack_a, 'a');
	else
	    ft_reverse_rotation(stack_a, 'a');
    }
    if (ft_compare_node(*stack_a, (*stack_a)->next))
	ft_swap(stack_a, 'a');
}

int	ft_move_number(t_list **stack_a, t_list **stack_b, t_list *target)
{
    int	top_a;
    int	top_b;
    int	bottom_a;
    int	bottom_b;
    int	offset;

    offset = ft_offset(*stack_a, target);
    top_a = offset - 1;
    bottom_a = ft_lstsize(*stack_a) - offset + 1;
    offset = ft_offset(*stack_b, ft_get_pos_b(target, stack_b));
    top_b = offset - 1;
    bottom_b = ft_lstsize(*stack_b) - offset + 1;
    if (bottom_a >= top_a && bottom_b >= top_b)
    {
	if (top_a == 0)
	    return (top_b + 1);
	else if (top_b == 0)
	    return (top_a + 1);
	else if (top_a < top_b)
	    return ((top_b - top_a) + top_b + 1);
	else if (top_a > top_b)
	    return ((top_a - top_b) + top_a + 1);
	else
	    return(top_a + 1);
    }
    else if (bottom_a <= top_a && bottom_b <= top_b)
    {
	if (bottom_a == 0)
	    return (bottom_b + 1);
	else if (bottom_b == 0)
	    return (bottom_a + 1);
	else if (bottom_a < bottom_b)
	    return ((bottom_b - bottom_a) + bottom_b + 1);
	else if (bottom_a > bottom_b)
	    return ((bottom_a - bottom_b) + bottom_a + 1);
	else
	    return(bottom_a + 1);
    }
    else if (bottom_a >= top_a && bottom_b <= top_b)
	return(top_a + bottom_b + 1);
    else if (bottom_a <= top_a && bottom_b >= top_b)
	return (bottom_a + top_b + 1);
    return (0);
}


t_list	*ft_near_node(t_list **stack_a, t_list **stack_b)
{
    t_list	*tmp;
    t_list	*save;
    int	lower;

    tmp = *stack_a;
    lower = ft_move_number(stack_a, stack_b, tmp);
    save = tmp;
    while (tmp)
    {
	if (lower > ft_move_number(stack_a, stack_b, tmp))
	{
	    save = tmp;
	    lower = ft_move_number(stack_a, stack_b, tmp);
	}
	tmp = tmp->next;
    }
    return (save);
}

// /*
void	ft_sort_stack_a(t_list **stack_a, t_list **stack_b)
{

    int		offset;
    t_list	*pos;

    pos = ft_get_pos_b(*stack_b, stack_a);
    offset = ft_offset(*stack_a,pos);
    if (ft_lstsize(*stack_a) - offset + 1 > offset - 1)
	while (ft_offset(*stack_a, pos) != 1)
	    ft_rotation(stack_a, 'a');
    else
	while (ft_offset(*stack_a, pos) != 1)
	    ft_reverse_rotation(stack_a, 'a');
    ft_push(stack_b, stack_a, 'a');


}
// */
void	ft_sort_stack(t_list **stack_a, t_list **stack_b)
{
    t_list	*near;
    int		offset;

    if (ft_lstsize(*stack_a) <= 3)
	ft_sort_3(stack_a);
    else
    {
	while (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_b) < 2)
	    ft_push(stack_a, stack_b, 'b');
	if (!ft_compare_node(*stack_b, (*stack_b)->next))
	    ft_swap(stack_b, 'b');
	while (ft_lstsize(*stack_a) > 0)
	{
	    near = ft_near_node(stack_a, stack_b);
	    ft_sort_stack_b(stack_a, stack_b, near);	
	}
	offset = ft_offset(*stack_b, ft_to_bigger(*stack_b));
	if (ft_lstsize(*stack_b) - offset + 1 >= offset - 1)
	    while (ft_offset(*stack_b, ft_to_bigger(*stack_b)) != 1)
		ft_rotation(stack_b, 'b');
	else
	    while (ft_offset(*stack_b, ft_to_bigger(*stack_b)) != 1)
		ft_reverse_rotation(stack_b, 'b');
    }
    while (ft_lstsize(*stack_b) > 0)
	ft_push(stack_b, stack_a, 'a');
}


int	main(int ac, char **av)
{
    t_list	*stack_a;
    t_list	*stack_b;
    char	**tab;

    tab = NULL;
    stack_a = NULL;
    if (ac >= 2)
    {
	if (ac == 2)
	{
	    tab = ft_split(av[1], ' ');
	    if (ft_check_paramters(tab, 's') == -1)
		return (write (2,"Error\n",6), ft_free(tab), 0);
	    stack_a = ft_fill_stack_a(stack_a, tab, 's');
	    ft_free(tab);
	}
	else
	{
	    if (ft_check_paramters(av, 'a') == -1)
		return (write (2,"Error\n",6), 0);
	    stack_a = ft_fill_stack_a(stack_a, av, 'a');
	}



	ft_sort_stack(&stack_a, &stack_b);
//	/*
	//	ft_push(&stack_a, &stack_b, 'b');
	//	ft_push(&stack_a, &stack_b, 'b');
	//	ft_push(&stack_a, &stack_b, 'b');
	//	ft_push(&stack_a, &stack_b, 'b');
	t_list    *tmp;
	printf("---------------------------------\n");
	tmp = stack_a;
	while (tmp)
	{
	//printf("number of move:%d \n", ft_move_number(&stack_a, &stack_b, tmp));
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



}
