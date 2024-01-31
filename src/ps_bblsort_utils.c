/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bblsort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:10:30 by bluzi             #+#    #+#             */
/*   Updated: 2023/03/19 20:56:34 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_data	find_max(t_stack *stack_a, t_stack *stack_b)
{
	t_data	max;

	if (stack_a)
		max.a = stack_a -> val;
	if (stack_b)
		max.b = stack_b -> val;
	while (stack_a)
	{
		if (stack_a -> val > max.a)
			max.a = stack_a -> val;
		stack_a = stack_a -> next;
	}
	while (stack_b)
	{
		if (stack_b -> val > max.b)
			max.b = stack_b -> val;
		stack_b = stack_b -> next;
	}
	return (max);
}

t_data	find_min(t_stack *stack_a, t_stack *stack_b)
{
	t_data	min;

	if (stack_a)
		min.a = stack_a -> val;
	if (stack_b)
		min.b = stack_b -> val;
	while (stack_a)
	{
		if (stack_a -> val < min.a)
			min.a = stack_a -> val;
		stack_a = stack_a -> next;
	}
	while (stack_b)
	{
		if (stack_b -> val < min.b)
			min.b = stack_b -> val;
		stack_b = stack_b -> next;
	}
	return (min);
}

t_data	find_size(t_stack *stack_a, t_stack *stack_b)
{
	t_data	size;

	size.a = stack_size(stack_a);
	size.b = stack_size(stack_b);
	return (size);
}

int	find_median(t_stack *stack)
{
	int	med;
	int	size;
	int	i;

	if (!stack)
		return (0);
	i = 0;
	size = stack_size(stack);
	med = find_min(stack, NULL).a;
	while (i++ < size / 2)
		med = find_next(med, stack);
	return (med);
}
