#include "../include/push_swap.h"

t_list  *ft_to_lower(t_list *stack)
{
        t_list  *tmp;
        t_list  *lower;

        if (ft_lstsize(stack) == 0)
                return (NULL);
        tmp = stack;
        lower = stack;
        while (tmp->next)
        {
                if (ft_compare_node(lower, tmp->next))
                        lower = tmp->next;
                tmp = tmp->next;
        }
        return (lower);
}

t_list  *ft_to_bigger(t_list *stack)
{
        t_list  *tmp;
        t_list  *bigger;

        if (ft_lstsize(stack) == 0)
                return (NULL);
        tmp = stack;
        bigger = stack;
        while (tmp->next)
        {
                if (!ft_compare_node(bigger, tmp->next))
                        bigger = tmp->next;
                tmp = tmp->next;
        }
        return (bigger);
}

t_list  *ft_near_node(t_list *stack_a, t_list *stack_b)
{
        t_list  *tmp;
        t_list  *save;
        int             lower;
        int     size;
        int     i;

        i = 0;
        size = ft_lstsize(stack_a);
        tmp = stack_a;
        lower = ft_move_number(stack_a, stack_b, tmp);
        save = tmp;
        while (tmp )
        {
            if (i < size / 10 || i > size - (size / 10))
            {
                if (lower > ft_move_number(stack_a, stack_b, tmp))
                {
                        save = tmp;
                        lower = ft_move_number(stack_a, stack_b, tmp);
                }
            }                
            tmp = tmp->next;
            i++;
        }
        return (save);
}