#include "../include/push_swap.h"

int     ft_compare_node(t_list *value1, t_list *value2)
{
        if (ft_lstsize(value2) == 0)
                return (1);
        if (ft_lstsize(value1) == 0)
                return (0);
        if (value1->nbr > value2->nbr)
                return (1);
        return (0);
}

t_list  *ft_get_pos_a(t_list *target, t_list *stack_a)
{
        t_list  *tmp;
        t_list  *lower;
        t_list  *bigger;

        tmp = stack_a;
        bigger = ft_to_bigger(stack_a);
        lower = ft_to_lower(stack_a);
        if (!ft_compare_node(target, lower) || ft_compare_node(target, bigger))
                return (lower);
        while (lower)
        {
                if (!ft_compare_node(target, lower))
                        return (lower);
                lower = lower->next;
        }
        lower = ft_to_lower(stack_a);
        while (tmp && tmp != lower)
        {
                if (!ft_compare_node(target, tmp))
                        return (tmp);
                tmp = tmp->next;
        }
        return (NULL);
}

t_list  *ft_get_pos_b(t_list *target, t_list *stack_b)
{
        t_list  *tmp;
        t_list  *lower;
        t_list  *bigger;

        tmp = stack_b;
        if (ft_lstsize(tmp) < 2)
                return (NULL);
        bigger = ft_to_bigger(stack_b);
        lower = ft_to_lower(stack_b);
        if (!ft_compare_node(target, lower) || ft_compare_node(target, bigger))
                return (bigger);
        while (bigger)
        {
                if (ft_compare_node(target, bigger))
                        return (bigger);
                bigger = bigger->next;
        }
        bigger = ft_to_bigger(stack_b);
        while (tmp && tmp != bigger)
        {
                if (ft_compare_node(target, tmp))
                        return (tmp);
                tmp = tmp->next;
        }
        return (NULL);
}

int     ft_move_top(t_list *a, t_list *b, t_list *target, t_list *pos)
{
        int     top_a;
        int     top_b;

        top_a = target->index;
        top_b = pos->index;
        if (top_a == 0)
                return (top_b + 1);
        else if (top_b == 0)
                return (top_a + 1);
        else if (top_a < top_b)
                return ((top_b - top_a) + top_b + 1);
        else if (top_a > top_b)
                return ((top_a - top_b) + top_a + 1);
        return (top_a + 1);
}

int     ft_move_bottom(t_list *a, t_list *b, t_list *target, t_list *pos)
{
        int     bottom_a;
        int     bottom_b;
        int     len_a;
        int     len_b;

        len_a = ft_lstsize(a);
        len_b = ft_lstsize(b);
        bottom_a = len_a - target->index;
        bottom_b = len_b - pos->index;
        if (bottom_a == 0)
                return (bottom_b + 1);
        else if (bottom_b == 0)
                return (bottom_a + 1);
        else if (bottom_a < bottom_b)
                return ((bottom_b - bottom_a) + bottom_b + 1);
        else if (bottom_a > bottom_b)
                return ((bottom_a - bottom_b) + bottom_a + 1);
        return (bottom_a + 1);
}


int     ft_move_number(t_list *a, t_list *b, t_list *target)
{
        int     len_a;
        int     len_b;
        t_list  *pos;

        len_a = ft_lstsize(a);
        len_b = ft_lstsize(b);
        pos = ft_get_pos_b(target, b);

        if (len_a - target->index >= target->index && len_b - pos->index >= pos->index)
                return (ft_move_top(a, b, target, pos));
        else if (len_a - target->index <= target->index && len_b - pos->index <= pos->index)
                return (ft_move_bottom(a, b, target, pos));
        else if (len_a - target->index >= target->index && len_b - pos->index <= pos->index)
                return (target->index + len_b - pos->index + 1);
        else if (len_a - target->index <= target->index && len_b - pos->index >= pos->index)
                return (len_a - target->index + pos->index + 1);
        return (0);
}
