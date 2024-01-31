/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:22:46 by bluzi             #+#    #+#             */
/*   Updated: 2023/03/19 21:57:23 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	int	a;
	int	b;
	int	total;
}	t_data;

//	push_swap functions
t_data	min_on_top(t_stack *stack_a, t_data moves, t_data size);
t_data	find_shortest_move(t_stack *stack_a, t_stack *stack_b, t_data size);
void	get_in_position(t_stack **stack_a, t_stack **stack_b);
void	keep_lis(t_stack **stack_a, t_stack **stack_b, int *lis);
void	push_swap(t_stack **stack_a, t_stack **stack_b);

//	bubble_sort functions
void	order_3_less(t_stack **stack_a, int size);
void	swap_3_more(t_stack **stack_a, t_stack **stack_b, t_data size);
void	rotate_3_more(t_stack **stack_a, t_stack **stack_b, t_data size);
void	order_3_more(t_stack **stack_a, t_stack **stack_b);
void	sort_small_stack(t_stack **stack_a, t_stack **stack_b);

//	bubble_sort utils
t_data	find_max(t_stack *stack_a, t_stack *stack_b);
t_data	find_min(t_stack *stack_a, t_stack *stack_b);
t_data	find_size(t_stack *stack_a, t_stack *stack_b);
int		find_median(t_stack *stack);

// longest increasing subsequence functions and utils
int		*lis(int *stack_arr, int size);
int		binary_search(int *stack_arr, int *subs_end_idx, int lis_len, int i);
int		*make_lis(int *stack, int *subs_end_idx, int *prev_num_idx, int len);
int		*calc_lis(int *stack_array, int size);

//	stack operations
void	rotate(t_stack **stack_a, t_stack **stack_b, int moves_a, int moves_b);
void	rotate_single_stack(t_stack **stack, int rotations);
void	push(t_stack **stack_a, t_stack **stack_b, char push_dest);
void	swap(t_stack **stack_a, t_stack **stack_b, char stack_to_swap);

//	push_swap utils
int		is_ordered(t_stack *stack);
int		find_next(int num_b, t_stack *stack_a);
t_data	is_shortest(int rot_a, int rot_b, t_data moves, t_data size);
void	print_moves(t_data moves);
t_data	print_single_rotations(t_data moves);

//	linked list handling related functions
t_stack	*create_node(int value);
void	append_node(t_stack **stack, t_stack *node);
int		stack_size(t_stack *stack);
t_stack	*last_node(t_stack *stack);
int		*ll_to_array(t_stack *stack, int size);

//	extra util functions
int		get_bigger_num(int a, int b);
int		is_atoiable(char *c, t_stack *stack);
int		checker_strcmp(const char *s1, const char *s2);
void	free_stacks(t_stack **stack_a, t_stack **stack_b);

// checker functions
void	checker(t_stack **stack_a, t_stack **stack_b);
int		push_checker(t_stack **stack_a, t_stack **stack_b, char *move);
int		swap_checker(t_stack **stack_a, t_stack **stack_b, char *move);
int		rotate_checker(t_stack **stack_a, t_stack **stack_b, char *move);

//	parsing
void	make_stack(t_stack **stack_a, t_stack **stack_b, int argc, char **argv);
void	parsing_error(t_stack **stack_a, t_stack **stack_b);

#endif
