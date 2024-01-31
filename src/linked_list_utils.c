/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:53:35 by bluzi             #+#    #+#             */
/*   Updated: 2023/03/19 20:56:34 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*node;

	node = ft_calloc(1, sizeof(t_stack));
	if (!node)
		return (NULL);
	node -> val = value;
	node -> next = NULL;
	return (node);
}

void	append_node(t_stack **stack, t_stack *node)
{
	t_stack	*last;

	if (!(*stack))
	{
		*stack = node;
		return ;
	}
	last = last_node(*stack);
	last -> next = node;
	return ;
}

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack -> next;
		i++;
	}
	return (i);
}

t_stack	*last_node(t_stack *stack)
{
	while (stack -> next)
		stack = stack -> next;
	return (stack);
}

int	*ll_to_array(t_stack *stack, int size)
{
	int	*stack_array;
	int	i;

	stack_array = ft_calloc(size, sizeof(int));
	i = 0;
	while (stack -> next)
	{
		stack_array[i++] = stack -> val;
		stack = stack -> next;
	}
	return (stack_array);
}
