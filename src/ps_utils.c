/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 07:43:20 by bluzi             #+#    #+#             */
/*   Updated: 2023/03/19 21:46:16 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_ordered(t_stack *stack)
{
	int		order;

	if (stack -> val > stack -> next -> val)
		order = 1;
	else
		order = -1;
	while (stack -> next)
	{
		if (stack -> val > stack -> next -> val && order == -1)
			return (0);
		else if (stack -> val < stack -> next -> val && order == 1)
			return (0);
		stack = stack -> next;
	}
	return (order);
}

t_data	print_single_rotations(t_data moves)
{
	if (moves.a > 0)
	{
		moves.a--;
		ft_printf("ra\n");
	}
	else if (moves.a < 0)
	{
		moves.a++;
		ft_printf("rra\n");
	}
	if (moves.b > 0)
	{
		moves.b--;
		ft_printf("rb\n");
	}
	else if (moves.b < 0)
	{
		moves.b++;
		ft_printf("rrb\n");
	}
	return (moves);
}

void	print_moves(t_data moves)
{
	while (moves.a || moves.b)
	{
		if (moves.a > 0 && moves.b > 0)
		{
			moves.a--;
			moves.b--;
			ft_printf("rr\n");
		}
		else if (moves.a < 0 && moves.b < 0)
		{
			moves.a++;
			moves.b++;
			ft_printf("rrr\n");
		}
		else
			moves = print_single_rotations(moves);
	}
}

t_data	is_shortest(int rot_a, int rot_b, t_data moves, t_data size)
{
	if (get_bigger_num(rot_a, rot_b) < moves.total || moves.total == -1)
	{
		moves.a = rot_a;
		moves.b = rot_b;
		moves.total = get_bigger_num(moves.a, moves.b);
	}
	if (get_bigger_num((size.a - rot_a), (size.b - rot_b)) < moves.total)
	{
		moves.a = rot_a - size.a ;
		moves.b = rot_b - size.b;
		moves.total = get_bigger_num(-moves.a, -moves.b);
	}
	if (rot_a + (size.b - rot_b) < moves.total)
	{
		moves.a = rot_a;
		moves.b = rot_b - size.b;
		moves.total = moves.a - moves.b;
	}
	if ((size.a - rot_a) + rot_b < moves.total)
	{
		moves.a = rot_a - size.a;
		moves.b = rot_b;
		moves.total = moves.b - moves.a;
	}
	return (moves);
}

int	find_next(int num_b, t_stack *stack_a)
{
	int	next;
	int	min;

	next = num_b;
	min = stack_a -> val;
	while (stack_a)
	{
		if ((stack_a -> val < next || next == num_b) && stack_a -> val > num_b)
			next = stack_a -> val;
		if (stack_a -> val < min)
			min = stack_a -> val;
		stack_a = stack_a -> next;
	}
	if (next == num_b)
		return (min);
	else
		return (next);
}
