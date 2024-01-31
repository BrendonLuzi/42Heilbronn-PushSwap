/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:49:02 by bluzi             #+#    #+#             */
/*   Updated: 2023/03/19 21:58:58 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*move;
	int		check;

	check = 1;
	while (check)
	{
		move = get_next_line(0);
		if (!move)
			break ;
		check = 0;
		if (*move == 'r')
			check = rotate_checker(stack_a, stack_b, move);
		else if (*move == 'p')
			check = push_checker(stack_a, stack_b, move);
		else if (*move == 's')
			check = swap_checker(stack_a, stack_b, move);
		free(move);
	}
	if (!check)
		write(1, "Error\n", 6);
	else if ((stack_size(*stack_a) == 1 || is_ordered(*stack_a) == -1)
		&& !(*stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	push_checker(t_stack **stack_a, t_stack **stack_b, char *move)
{
	t_stack	*temp;
	t_stack	**stack_origin;
	t_stack	**stack_destin;

	if (checker_strcmp(move, "pb\n"))
	{
		if (stack_size(*stack_a) < 1)
			return (1);
		stack_origin = stack_a;
		stack_destin = stack_b;
	}
	else if (checker_strcmp(move, "pa\n"))
	{
		if (stack_size(*stack_b) < 1)
			return (1);
		stack_origin = stack_b;
		stack_destin = stack_a;
	}
	else
		return (0);
	temp = (*stack_origin)-> next;
	(*stack_origin)-> next = *stack_destin;
	*stack_destin = *stack_origin;
	*stack_origin = temp;
	return (1);
}

int	swap_checker(t_stack **stack_a, t_stack **stack_b, char *move)
{
	t_stack	*temp;

	if ((checker_strcmp(move, "sa\n") || checker_strcmp(move, "ss\n"))
		&& stack_size(*stack_a) > 1)
	{	
		temp = (*stack_a)-> next;
		(*stack_a)-> next = (*stack_a)-> next -> next;
		temp -> next = (*stack_a);
		*stack_a = temp;
	}
	if ((checker_strcmp(move, "sb\n") || checker_strcmp(move, "ss\n"))
		&& stack_size(*stack_b) > 1)
	{	
		temp = (*stack_b)-> next;
		(*stack_b)-> next = (*stack_b)-> next -> next;
		temp -> next = (*stack_b);
		*stack_b = temp;
	}
	return ((checker_strcmp(move, "sa\n")
			|| checker_strcmp(move, "sb\n") || checker_strcmp(move, "ss\n")));
}

int	rotate_checker(t_stack **stack_a, t_stack **stack_b, char *move)
{
	int	check;

	check = 0;
	if (checker_strcmp(move, "rra\n") || checker_strcmp(move, "rrr\n"))
	{
		rotate_single_stack(stack_a, -1);
		check++;
	}
	if (checker_strcmp(move, "rrb\n") || checker_strcmp(move, "rrr\n"))
	{
		rotate_single_stack(stack_b, -1);
		check++;
	}
	if (checker_strcmp(move, "ra\n") || checker_strcmp(move, "rr\n"))
	{
		rotate_single_stack(stack_a, 1);
		check++;
	}
	if (checker_strcmp(move, "rb\n") || checker_strcmp(move, "rr\n"))
	{
		rotate_single_stack(stack_b, 1);
		check++;
	}
	return (check);
}
