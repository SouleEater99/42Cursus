/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:46:46 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/21 10:19:38 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_check_is_number(char *str);
int		ft_check_paramters(char **av, char c);
int		ft_offset(t_list *stack, t_list *node);
int		ft_compare_node(t_list *value1, t_list *value2);
void	ft_swap(t_list **stack, char c);
void	ft_rotation(t_list **stack, char c);
void	ft_reverse_rotation(t_list **stack, char c);
void	ft_push(t_list **stack_1, t_list **stack_2, char c);
void	ft_split_stack(t_list **stack_a, t_list **stack_b);
t_list	*ft_to_bigger(t_list *stack);
t_list	*ft_to_lower(t_list *stack);
t_list	*ft_fill_stack_a(t_list *stack_a, char **av, char c);
t_list	*ft_get_pos_b(t_list *target, t_list **stack_b);
t_list	*ft_get_pos_a(t_list *target, t_list **stack_a);
void	ft_sort_stack_b(t_list **stack_a, t_list **stack_b, t_list *near);
void	ft_sort_stack(t_list **stack_a, t_list **stack_b);
void	ft_sort_stack_a(t_list **stack_a, t_list **stack_b);
t_list	*ft_near_node(t_list **stack_a, t_list **stack_b);
int		ft_move_number(t_list **stack_a, t_list **stack_b, t_list *target);
int		ft_move_number_top(t_list **stack_a, t_list **stack_b, t_list *target);
int		ft_move_number_bottom(t_list **stack_a, t_list **stack_b,
			t_list *target);
void	ft_sort_3(t_list **stack_a);
void	ft_free(char **tab);
int		ft_fill_stack_split(t_list **stack_a, char **av);
void	ft_sort_b_equal_top(t_list **stack_a, t_list **stack_b, t_list *near);
void	ft_sort_b_equal_bottom(t_list **stack_a, t_list **stack_b,
			t_list *near);
void	ft_sort_b_remain(t_list **stack_a, t_list **stack_b, t_list *near);

#endif
