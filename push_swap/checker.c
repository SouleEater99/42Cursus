/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:24:29 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/21 12:10:15 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checker_sort(t_list **stack_a, t_list **stack_b, char *line)
{
	if (ft_strncmp(line, "sa\n") == 0)
	    ft_swap(stack_a, 'd');
	else if (ft_strncmp(line, "sb\n") == 0)
	    ft_swap(stack_b, 'd');
	else if (ft_strncmp(line, "ss\n") == 0)
	{
	    ft_swap(stack_a, 'd');
	    ft_swap(stack_b, 'd');
	}
	else if (ft_strncmp(line, "pa\n") == 0)
	    ft_push(stack_a, 'd');
	else if (ft_strncmp(line, "pb\n") == 0)
	    ft_push(stack_b, 'd');
	else if (ft_strncmp(line, "ra\n") == 0)
	    ft_rotation(stack_a, 'd');
	else if (ft_strncmp(line, "rb\n") == 0)
	    ft_rotation(stack_b, 'd');
	else if (ft_strncmp(line, "rr\n") == 0)
	{
	    ft_rotation(stack_a, 'd');
	    ft_rotation(stack_b, 'd');
	}
	else if (ft_strncmp(line, "rra\n") == 0)
	    ft_reverse_rotation(stack_a, 'd');
	else if (ft_strncmp(line, "rrb\n") == 0)
	    ft_reverse_rotation(stack_b, 'd');
	else if (ft_strncmp(line, "rrr\n") == 0)
	{
	    ft_reverse_rotation(stack_a, 'd');
	    ft_reverse_rotation(stack_a, 'd');
	}
	free(line);
}


int main(int ac, char **av)
{
    char	*line;
    t_list  *stack_a;
    t_list  *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (ac >= 2)
    {
	if (ac == 2)
	{
	    if (!ft_fill_stack_split(&stack_a, av))
		return (0);
	}
	else
	{
	    if (ft_check_paramters(av, 'a') == -1)
		return (write(2, "Error\n", 6), 0);
	    stack_a = ft_fill_stack_a(stack_a, av, 'a');
	}
	while (line = get_next_line(0))
	    ft_checker_sort(stack_a, stack_b, line);
	ft_lstclear(&stack_a, free);
    }
}
