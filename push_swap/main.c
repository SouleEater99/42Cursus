/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:59:19 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/16 19:17:51 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_get_pos_b(t_list **stack_a, t_list **stack_b)
{
	int	pos;
	t_list	*tmp;

	tmp = *stack_b;
	pos = 1;
	while (tmp)
	{
		if (!ft_compare_node(*stack_a, tmp))
			i++;
		else
		    return (tmp);
		tmp = tmp->next;
	}
	return (ft_lstlast(tmp));
}

void	ft_sort_stack_b(t_list	**stack_a, t_list **stack_b)
{
	(void)stack_a;
	(void)stack_b;
	
	if (ft_lstsize(*stack_b) >= 2)
	{
		

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

    ft_reverse_rotation(&stack_a);
    ft_reverse_rotation(&stack_b);
  //  ft_first_sort(&stack_a, &stack_b);
///*
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
//*/

	
   // ft_rotation(&stack_a);
    tail = stack_a;

   // printf("tail: %d\n", *(int*)tail->content);
  //  tmp = ft_to_bigger(tail->next);
   // printf("bigger_a:%d\n", *(int*)tmp->content);
   // ft_second_sort_top_a(&stack_a, &stack_b, tail);
    ft_second_sort(&stack_a, &stack_b, tail);









    ft_sort_stack_b(&stack_a, &stack_b);

    printf("ft_check_sort : %d\n",ft_check_sort(&stack_a, &stack_b, tail));
     ///*
   //t_list	*tmp;
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
