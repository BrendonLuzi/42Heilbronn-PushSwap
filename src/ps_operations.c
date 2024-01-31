/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:17:44 by bluzi             #+#    #+#             */
/*   Updated: 2023/03/19 21:46:04 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **stack_a, t_stack **stack_b, int moves_a, int moves_b)
{
	t_data	moves;

	if (moves_a)
		rotate_single_stack(stack_a, moves_a);
	if (moves_b)
		rotate_single_stack(stack_b, moves_b);
	moves.a = moves_a;
	moves.b = moves_b;
	print_moves(moves);
}

void	rotate_single_stack(t_stack **stack, int rotations)
{
	t_stack	*temp;
	int		size;

	if (!(*stack && (*stack)-> next))
		return ;
	size = stack_size(*stack);
	temp = last_node(*stack);
	temp -> next = *stack;
	if (rotations < 0)
		rotations = size + rotations;
	while (rotations--)
		temp = temp -> next;
	*stack = temp -> next;
	temp -> next = NULL;
}

void	push(t_stack **stack_a, t_stack **stack_b, char push_dest)
{
	t_stack	*temp;
	t_stack	**stack_origin;
	t_stack	**stack_destin;

	if (push_dest == 'b')
	{
		stack_origin = stack_a;
		stack_destin = stack_b;
	}
	else if (push_dest == 'a')
	{
		stack_origin = stack_b;
		stack_destin = stack_a;
	}
	else
		return ;
	temp = (*stack_origin)-> next;
	(*stack_origin)-> next = *stack_destin;
	*stack_destin = *stack_origin;
	*stack_origin = temp;
	ft_printf("p%c\n", push_dest);
}

void	swap(t_stack **stack_a, t_stack **stack_b, char stack_to_swap)
{
	t_stack	*temp;

	if ((stack_to_swap == 'a' || stack_to_swap == 's'))
	{	
		temp = (*stack_a)-> next;
		(*stack_a)-> next = (*stack_a)-> next -> next;
		temp -> next = (*stack_a);
		*stack_a = temp;
	}
	if ((stack_to_swap == 'b' || stack_to_swap == 's'))
	{	
		temp = (*stack_b)-> next;
		(*stack_b)-> next = (*stack_b)-> next -> next;
		temp -> next = (*stack_b);
		*stack_b = temp;
	}
	ft_printf("s%c\n", stack_to_swap);
}
