/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:11:07 by bluzi             #+#    #+#             */
/*   Updated: 2023/03/19 20:56:34 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <math.h>

int	binary_search(int *stack_arr, int *subs_end_idx, int lis_len, int i)
{
	int	lo;
	int	hi;
	int	mid;

	lo = 1;
	hi = lis_len + 1;
	while (lo < hi)
	{
		mid = lo + ((hi - lo) / 2);
		if (stack_arr[subs_end_idx[mid]] > stack_arr[i])
			hi = mid;
		else
			lo = mid + 1;
	}
	return (lo);
}

int	*make_lis(int *stack, int *subs_end_idx, int *prev_num_idx, int len)
{
	int	*lis;
	int	i;
	int	j;

	lis = ft_calloc(len, sizeof(int));
	i = subs_end_idx[len];
	j = len - 1;
	while (j >= 0)
	{
		lis[j--] = stack[i];
		i = prev_num_idx[i];
	}
	j = -1;
	free(subs_end_idx);
	free(prev_num_idx);
	return (lis);
}

int	*calc_lis(int *stack_array, int size)
{
	int	*prev_num_idx;
	int	*subs_end_idx;
	int	lis_len;
	int	temp_lis_len;
	int	i;

	prev_num_idx = ft_calloc(size, sizeof(int));
	subs_end_idx = ft_calloc(size + 1, sizeof(int));
	subs_end_idx[0] = -1;
	i = 0;
	lis_len = 0;
	while (i <= size - 1)
	{
		temp_lis_len = binary_search(stack_array, subs_end_idx, lis_len, i);
		prev_num_idx[i] = subs_end_idx[temp_lis_len - 1];
		subs_end_idx[temp_lis_len] = i;
		if (temp_lis_len > lis_len)
			lis_len = temp_lis_len;
		i++;
	}
	return (make_lis(stack_array, subs_end_idx, prev_num_idx, lis_len));
}
