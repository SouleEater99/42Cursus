#include "../include/push_swap.h"

void    ft_sort_b_equal_top(t_list **stack_a, t_list **stack_b, t_list *near, t_list *pos)
{
        while (near->index != 0 && pos->index != 0)
        {
                ft_rotation(stack_a, 'r');
                ft_rotation(stack_b, '2');
        }
}

void    ft_sort_b_equal_bottom(t_list **stack_a, t_list **stack_b, t_list *near, t_list *pos)
{
        while (near->index != 0 && pos->index != 0)
        {
                ft_reverse_rotation(stack_a, 'r');
                ft_reverse_rotation(stack_b, '2');
        }
}

void    ft_sort_b_remain(t_list **stack_a, t_list **stack_b, t_list *near, t_list *pos)
{
        int             size_a;
        int             size_b;

        size_a = ft_lstsize(*stack_a);
        size_b = ft_lstsize(*stack_b);
        if (size_a - near->index > near->index)
                while (near->index != 0)
                        ft_rotation(stack_a, 'a');
        else if (size_a - near->index <= near->index)
                while (near->index != 0)
                        ft_reverse_rotation(stack_a, 'a');
        if (size_b - pos->index > pos->index)
                while (pos->index != 0)
                        ft_rotation(stack_b, 'b');
        else if (size_b - pos->index <= pos->index)
                while (pos->index != 0)
                        ft_reverse_rotation(stack_b, 'b');
        if (near->index == 0)
                ft_push(stack_a, stack_b, 'b');
}

void    ft_sort_stack_b(t_list **stack_a, t_list **stack_b, t_list *near)
{
        int             size_a;
        int             size_b;
        t_list          *pos;

        pos = ft_get_pos_b(near, *stack_b);
        size_a = ft_lstsize(*stack_a);
        size_b = ft_lstsize(*stack_b);
        if (size_a - near->index > near->index && size_b - pos->index> pos->index)
        {
                ft_sort_b_equal_top(stack_a, stack_b, near, pos);
        }
        else if (size_a - near->index <= near->index && size_b - pos->index <= pos->index)
        {
                ft_sort_b_equal_bottom(stack_a, stack_b, near, pos);
        }
        ft_sort_b_remain(stack_a, stack_b, near, pos);
}

void    ft_sort_3(t_list **stack_a)
{
        t_list  *bigger;

        bigger = ft_to_bigger(*stack_a);
        if (bigger->index != 2 && ft_lstsize(*stack_a) > 2)
        {
                if (ft_lstsize(*stack_a) - bigger->index >= bigger->index)
                        ft_rotation(stack_a, 'a');
                else
                        ft_reverse_rotation(stack_a, 'a');
        }
        if (ft_compare_node(*stack_a, (*stack_a)->next))
                ft_swap(stack_a, 'a');
}

void    ft_sort_stack_a(t_list **stack_a, t_list **stack_b)
{
        t_list  *pos;

        pos = ft_get_pos_a(*stack_b, *stack_a);
        if (ft_lstsize(*stack_a) - pos->index > pos->index)
        {
                while (pos->index != 0)
                        ft_rotation(stack_a, 'a');
        }
        else
                while (pos->index != 0)
                        ft_reverse_rotation(stack_a, 'a');
        ft_push(stack_b, stack_a, 'a');
}

void    ft_sort_stack(t_list **stack_a, t_list **stack_b)
{
        t_list  *near;
        t_list  *lower;

        if (ft_lstsize(*stack_a) <= 3)
                ft_sort_3(stack_a);
        else
        {
                while (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_b) < 2)
                        ft_push(stack_a, stack_b, 'b');
                while (ft_lstsize(*stack_a) > 3)
                {
                        near = ft_near_node(*stack_a, *stack_b);
                        ft_sort_stack_b(stack_a, stack_b, near);
                }
                ft_sort_3(stack_a);
                while (ft_lstsize(*stack_b) > 0)
                        ft_sort_stack_a(stack_a, stack_b);
                lower = (ft_to_lower(*stack_a));
                if (ft_lstsize(*stack_a) - lower->index >= lower->index)
                        while (lower->index != 0)
                                ft_rotation(stack_a, 'a');
                else
                        while (lower->index != 0)
                                ft_reverse_rotation(stack_a, 'a');
        }
}