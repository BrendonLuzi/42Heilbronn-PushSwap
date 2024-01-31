/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:39:38 by bluzi             #+#    #+#             */
/*   Updated: 2023/03/19 22:06:30 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc == 1)
		return (0);
	stack_a = ft_calloc(1, sizeof(t_stack *));
	stack_b = ft_calloc(1, sizeof(t_stack *));
	*stack_a = NULL;
	*stack_b = NULL;
	make_stack(stack_a, stack_b, argc, argv);
	if (*stack_a)
		push_swap(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
