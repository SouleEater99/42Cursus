/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:23:00 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/30 15:23:04 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    ft_try(t_list **a, t_list **b)
{
        int     len;
        int     j;

        j = 0;
        len = ft_lstsize(*a);
        while (j++ < len / 2)
                ft_push(a, b, 'b');


}

void    ft_print(t_list *stack_a, t_list *stack_b)
{
        t_list *tmp = stack_a;
        while (tmp)
        {
                //printf("+++++\n");
                //printf("stack_a : %d| index : %d |move: %d\n",tmp->nbr, tmp->index, ft_move_number(stack_a, stack_b, tmp));
                printf("stack_a : %d| index : %d\n",tmp->nbr, tmp->index);

                tmp = tmp->next;
               
        }        
        tmp = stack_b;
        while (tmp)
        {
                printf("stack_b : %d| index : %d\n",tmp->nbr, tmp->index);

                tmp = tmp->next;
        }
}

int main(int ac, char **av)
{
        t_list  *stack_a;
        t_list  *stack_b;
        char    *str;
        char    **tab;

        stack_a = NULL;
        stack_b = NULL;
        if (ac >= 2)
        {
                str = ft_merge_arg(av);
                tab = ft_split(str, ' ');
                if (!tab)
                        return (0);
                if (str)
                        free(str);
                if (ft_check_paramters(tab) == -1)
                        return (write(2, "Error\n", 6), 0);
                stack_a = ft_fill_stack_a(stack_a, tab);
                ft_sort_stack(&stack_a, &stack_b);
                //ft_try(&stack_a, &stack_b);
                ft_free_lst(tab);
                //ft_print(stack_a, stack_b);
                ft_lstclear(&stack_a, free);
                ft_lstclear(&stack_b, free);
        }

}