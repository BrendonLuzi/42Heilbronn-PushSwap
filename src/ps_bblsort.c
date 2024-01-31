/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bblsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:59:54 by bluzi             #+#    #+#             */
/*   Updated: 2023/03/19 21:34:19 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	order_3_less(t_stack **stack_a, int size)
{
	int	max;

	max = find_max(*stack_a, NULL).a;
	while (size == 3 && is_ordered(*stack_a) != -1)
	{
		if ((*stack_a)-> val == max)
			rotate(stack_a, NULL, 1, 0);
		else
			swap(stack_a, NULL, 'a');
	}
	if (size == 2 && is_ordered(*stack_a) != -1)
		swap(stack_a, NULL, 'a');
}

void	swap_3_more(t_stack **stack_a, t_stack **stack_b, t_data size)
{
	t_data	max;
	t_data	min;
	t_data	val;
	t_data	next;

	val.a = (*stack_a)-> val;
	val.b = (*stack_b)-> val;
	next.a = (*stack_a)-> next -> val;
	next.b = (*stack_b)-> next -> val;
	max = find_max(*stack_a, *stack_b);
	min = find_min(*stack_a, *stack_b);
	if ((val.a > next.a) && !(val.a == max.a && next.a == min.a && size.a > 2))
	{		
		if ((val.b < next.b)
			&& !(val.b == min.b && next.b == max.b && size.b > 2))
			swap(stack_a, stack_b, 's');
		else
			swap(stack_a, stack_b, 'a');
	}
	else if (val.b < next.b
		&& !(val.b == min.b && next.b == max.b && size.b > 2))
		swap(stack_a, stack_b, 'b');
}

void	rotate_3_more(t_stack **stack_a, t_stack **stack_b, t_data size)
{
	t_data	max;
	t_data	min;
	t_data	val;
	t_data	last;

	val.a = (*stack_a)-> val;
	val.b = (*stack_b)-> val;
	last.a = last_node(*stack_a)-> val;
	last.b = last_node(*stack_b)-> val;
	max = find_max(*stack_a, *stack_b);
	min = find_min(*stack_a, *stack_b);
	if (is_ordered(*stack_a) != -1 && is_ordered(*stack_b) == 1)
		if ((val.a < last.a)
			&& !(val.a == min.a && last.a == max.a && size.a > 2))
			rotate(stack_a, stack_b, -1, 0);
	else
		rotate(stack_a, stack_b, 1, 0);
	else if (is_ordered(*stack_b) != 1 && is_ordered(*stack_a) == -1)
		if ((val.b > last.b)
			&& !(val.b == max.b && last.b == min.b && size.b > 2))
			rotate(stack_a, stack_b, 0, -1);
	else
		rotate(stack_a, stack_b, 0, 1);
	else if (is_ordered(*stack_a) != -1 && is_ordered(*stack_b) != 1)
		rotate(stack_a, stack_b, 1, 1);
}

void	order_3_more(t_stack **stack_a, t_stack **stack_b)
{
	t_data	size;

	size = find_size(*stack_a, *stack_b);
	while (is_ordered(*stack_a) != -1 || is_ordered(*stack_b) != 1)
	{
		swap_3_more(stack_a, stack_b, size);
		rotate_3_more(stack_a, stack_b, size);
	}
}

void	sort_small_stack(t_stack **stack_a, t_stack **stack_b)
{
	int		median;
	int		i;
	t_data	size;

	i = 0;
	size = find_size(*stack_a, *stack_b);
	median = find_median(*stack_a);
	if (is_ordered(*stack_a) == -1)
		return ;
	if (size.a <= 3)
		order_3_less(stack_a, size.a);
	else
	{
		while (size.a - i++)
		{
			if ((*stack_a)-> val < median)
				push(stack_a, stack_b, 'b');
			else
				rotate(stack_a, stack_b, 1, 0);
		}
		order_3_more(stack_a, stack_b);
	}
	while (*stack_b)
		push(stack_a, stack_b, 'a');
}
