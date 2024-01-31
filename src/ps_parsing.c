/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:55:12 by bluzi             #+#    #+#             */
/*   Updated: 2023/03/20 00:40:36 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	make_stack(t_stack **stack_a, t_stack **stack_b, int argc, char **argv)
{
	int	n;

	n = 0;
	while (n++ < argc - 1)
	{
		if (!*argv[n])
			parsing_error(stack_a, stack_b);
		while (*argv[n])
		{
			while (*argv[n] && *argv[n] == ' ')
				argv[n]++;
			if (*argv[n] && is_atoiable(argv[n], *stack_a))
				append_node(stack_a, create_node(ft_atoi(argv[n])));
			else
				parsing_error(stack_a, stack_b);
			if (*argv[n] && (*argv[n] == '+' || *argv[n] == '-'))
				argv[n]++;
			while (*argv[n] && ft_isdigit(*argv[n]))
				argv[n]++;
			while (*argv[n] && *argv[n] == ' ')
				argv[n]++;
		}
	}
}

void	parsing_error(t_stack **stack_a, t_stack **stack_b)
{
	free_stacks(stack_a, stack_b);
	exit(write(2, "Error\n", 6));
}
