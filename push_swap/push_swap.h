#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "libft/libft.h"

int     ft_check_is_number(char *str);
int     ft_check_paramters(int  ac, char **av);
int     ft_offset(t_list *stack, t_list *node);
int     ft_compare_node(t_list *value1, t_list *value2);
void    ft_swap(t_list **stack);
void    ft_rotation(t_list **stack);
void    ft_reverse_rotation(t_list **stack);
void    ft_push(t_list **stack_1, t_list **stack_2);
void    ft_split_stack(t_list **stack_a, t_list **stack_b);
void    ft_swap_top_element(t_list **stack_a, t_list **stack_b);
void    ft_second_swap_top_element(t_list **stack_a, t_list **stack_b);
t_list  *ft_to_bigger(t_list *stack);
t_list  *ft_fill_stack_a(t_list *stack_a, int ac, char **av);
void    ft_sort_a_bottom(t_list **stack_a, t_list **stack_b);
void    ft_sort_a_top(t_list **stack_a, t_list **stack_b);
void    ft_sort_b_bottom(t_list **stack_a, t_list **stack_b);
void    ft_sort_b_top(t_list **stack_a, t_list **stack_b);
void    ft_first_sort(t_list **stack_a, t_list **stack_b);
int     ft_check_sort(t_list **stack_a, t_list **stack_b, t_list *tail);
void    ft_second_sort_top_a(t_list **stack_a, t_list **stack_b, t_list *tail);
void    ft_second_sort_bottom_a(t_list **stack_a, t_list **stack_b, t_list *tail);
void    ft_second_sort_b(t_list **stack_a, t_list **stack_b);
void    ft_second_sort(t_list **stack_a, t_list **stack_b, t_list *tail);
t_list  *ft_get_pos_b(t_list **stack_a, t_list **stack_b);
void    ft_sort_stack_b(t_list  **stack_a, t_list **stack_b);


#endif
