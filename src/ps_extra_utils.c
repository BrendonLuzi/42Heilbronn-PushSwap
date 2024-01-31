/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_extra_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:14:34 by bluzi             #+#    #+#             */
/*   Updated: 2023/03/19 21:37:04 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_bigger_num(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	is_unique(int n, t_stack *stack)
{
	while (stack)
	{
		if (n == stack -> val)
			return (0);
		stack = stack -> next;
	}
	return (1);
}

int	is_atoiable(char *c, t_stack *stack)
{
	long int	n;
	int			i;
	int			sign;

	n = 0;
	i = 0;
	sign = 1;
	if (c[i] == '-' || c[i] == '+')
		if (c[i++] == '-')
			sign = -1;
	while (ft_isdigit(c[i]))
	{
		n *= 10;
		n += (c[i++] - '0');
		if (n - (sign < 0) > 2147483647)
			return (0);
	}
	if (!is_unique(n * sign, stack))
		return (0);
	if (*c == '+' || *c == '-')
		c++;
	return (ft_isdigit(*c));
}

int	checker_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	while (*stack_a)
	{
		temp = (*stack_a)-> next;
		free(*stack_a);
		*stack_a = temp;
	}
	free(stack_a);
	while (*stack_b)
	{
		temp = (*stack_b)-> next;
		free(*stack_b);
		*stack_b = temp;
	}
	free(stack_b);
}
