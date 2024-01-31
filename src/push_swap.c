/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:55:10 by bluzi             #+#    #+#             */
/*   Updated: 2023/03/19 20:56:34 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_data	min_on_top(t_stack *stack_a, t_data moves, t_data size)
{
	int		min;
	int		rot_a;

	rot_a = 0;
	min = stack_a -> val;
	while (stack_a)
	{
		if (stack_a -> val < min)
		{
			min = stack_a -> val;
			moves.a = rot_a;
		}
		stack_a = stack_a -> next;
		rot_a++;
	}
	moves.total = moves.a;
	if (moves.a > size.a - moves.a)
	{
		moves.total = size.a - moves.a;
		moves.a = moves.a - size.a;
	}
	moves.b = 0;
	return (moves);
}

t_data	find_shortest_move(t_stack *stack_a, t_stack *stack_b, t_data size)
{
	t_stack	*temp_a;
	t_data	moves;
	int		rot_a;
	int		rot_b;
	int		next;

	moves.total = -1;
	moves.a = 0;
	moves.b = 0;
	rot_b = 0;
	while (stack_b)
	{
		temp_a = stack_a;
		rot_a = 0;
		next = find_next(stack_b -> val, stack_a);
		while (temp_a && next != temp_a -> val)
		{
			temp_a = temp_a -> next;
			rot_a++;
		}
		moves = is_shortest(rot_a, rot_b, moves, size);
		stack_b = stack_b -> next;
		rot_b++;
	}
	return (moves);
}

void	get_in_position(t_stack **stack_a, t_stack **stack_b)
{
	t_data	size;
	t_data	moves;

	moves.total = -1;
	moves.a = 0;
	moves.b = 0;
	size.a = stack_size(*stack_a);
	size.b = stack_size(*stack_b);
	if (*stack_b)
		moves = find_shortest_move(*stack_a, *stack_b, size);
	else
		moves = min_on_top(*stack_a, moves, size);
	rotate(stack_a, stack_b, moves.a, moves.b);
}

void	keep_lis(t_stack **stack_a, t_stack **stack_b, int *lis)
{
	int	size;
	int	i;
	int	j;
	int	median;

	i = 0;
	j = 0;
	size = stack_size(*stack_a);
	median = find_median(*stack_a);
	while (j != size)
	{
		if ((*stack_a)-> val == lis[i])
		{
			rotate(stack_a, stack_b, 1, 0);
			i++;
		}
		else if (!((lis[0] == lis[1]) && j + 3 > size))
		{
			push(stack_a, stack_b, 'b');
			if ((*stack_b)-> val <= median)
				rotate(stack_a, stack_b, 0, 1);
		}
		j++;
	}
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	*lis_arr;
	int	size;

	if (stack_size(*stack_a) == 1 || is_ordered(*stack_a) == -1)
		return ;
	size = stack_size(*stack_a);
	if (size < 10)
	{
		if (size != 1)
			sort_small_stack(stack_a, stack_b);
		return ;
	}
	lis_arr = calc_lis(ll_to_array(*stack_a, size), size);
	keep_lis(stack_a, stack_b, lis_arr);
	while (*stack_b)
	{
		get_in_position(stack_a, stack_b);
		push(stack_a, stack_b, 'a');
	}
	get_in_position(stack_a, stack_b);
	free(lis_arr);
}
