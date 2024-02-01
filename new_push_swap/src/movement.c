
#include "../include/push_swap.h"

void    ft_swap(t_list **stack, char c)
{
        t_list  *tmp;

        if (ft_lstsize(*stack) >= 2)
        {
                tmp = (*stack)->next;
                (*stack)->next = tmp->next;
                tmp->next = *stack;
                *stack = tmp;
                if (c == 'a')
                        write(1, "sa\n", 3);
                else if (c == 'b')
                        write(1, "sb\n", 3);
                else if (c == '2')
                        write(1, "ss\n", 3);
				ft_update_index(*stack);

        }
}

void    ft_push(t_list **stack_1, t_list **stack_2, char c)
{
        t_list  *tmp;
        t_list  *tmp2;

        if (*stack_1)
        {
                tmp = (*stack_1)->next;
                tmp2 = *stack_1;
                tmp2->next = *stack_2;
                *stack_2 = tmp2;
                *stack_1 = tmp;
                if (c == 'a')
                        write(1, "pa\n", 3);
                else if (c == 'b')
                        write(1, "pb\n", 3);
				ft_update_index(*stack_1);
				ft_update_index(*stack_2);

        }
}

void    ft_rotation(t_list **stack, char c)
{
        t_list  *tmp;

        if (*stack && (*stack)->next)
        {
                tmp = ft_lstlast(*stack);
                tmp->next = *stack;
                tmp = (*stack)->next;
                (*stack)->next = NULL;
                *stack = tmp;
                if (c == 'a')
                        write(1, "ra\n", 3);
                else if (c == 'b')
                        write(1, "rb\n", 3);
                else if (c == '2')
                        write(1, "rr\n", 3);
				ft_update_index(*stack);
        }
}

void    ft_reverse_rotation(t_list **stack, char c)
{
        t_list  *last;
        t_list  *before_last;

        if (*stack && (*stack)->next)
        {
                last = ft_lstlast(*stack);
                before_last = *stack;
                while (before_last->next && before_last->next != last)
                        before_last = before_last->next;
                before_last->next = NULL;
                last->next = *stack;
                *stack = last;
                if (c == 'a')
                        write(1, "rra\n", 4);
                else if (c == 'b')
                        write(1, "rrb\n", 4);
                else if (c == '2')
                        write(1, "rrr\n", 4);
				ft_update_index(*stack);
        }
}	

void	ft_update_index(t_list *head)
{
	int	i;

	i = 0;
	while (head)
	{
			head->index = i;
			i++;
			head = head->next;
	}
}
