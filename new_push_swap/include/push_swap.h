/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:12:35 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/30 15:12:41 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef push_swap_H
#define PUSH_SWAP_H

# include "./get_next_line.h"
# include "../libft/libft.h"

typedef struct t_list{
    int nbr;
    int index;
    struct t_list *next;
} t_list;

t_list  *ft_fill_stack_a(t_list *stack_a, char **av);
void    ft_lstclear(t_list **lst, void (*del)(void *));
t_list  *ft_lstnew(int  nbr);
void    ft_lstadd_back(t_list **lst, t_list *new);
int     ft_lstsize(t_list *lst);
t_list  *ft_lstlast(t_list *lst);
void    ft_free_lst(char **tab);
char    *ft_merge_arg(char **av);
int     ft_check_paramters(char **av);
int     ft_check_is_number(char *str);
char    *ft_strjoin_2(char *str1, char *str2);
void	ft_reverse_rotation(t_list **stack, char c);
void	ft_rotation(t_list **stack, char c);
void	ft_push(t_list **stack_1, t_list **stack_2, char c);
void	ft_swap(t_list **stack, char c);
void	ft_update_index(t_list *head);
int     ft_compare_node(t_list *value1, t_list *value2);
t_list  *ft_get_pos_a(t_list *target, t_list *stack_a);
t_list  *ft_get_pos_b(t_list *target, t_list *stack_b);
int     ft_move_top(t_list *a, t_list *b, t_list *target, t_list *pos);
int     ft_move_bottom(t_list *a, t_list *b, t_list *target, t_list *pos);
int     ft_move_number(t_list *a, t_list *b, t_list *target);
t_list  *ft_to_lower(t_list *stack);
t_list  *ft_to_bigger(t_list *stack);
t_list  *ft_near_node(t_list *stack_a, t_list *stack_b);
void    ft_sort_stack(t_list **stack_a, t_list **stack_b);
void    ft_sort_stack_a(t_list **stack_a, t_list **stack_b);
void    ft_sort_3(t_list **stack_a);
void    ft_sort_stack_b(t_list **stack_a, t_list **stack_b, t_list *near);
void    ft_sort_b_remain(t_list **stack_a, t_list **stack_b, t_list *near, t_list *pos);
void    ft_sort_b_equal_bottom(t_list **stack_a, t_list **stack_b, t_list *near, t_list *pos);
void    ft_sort_b_equal_top(t_list **stack_a, t_list **stack_b, t_list *near, t_list *pos);





#endif