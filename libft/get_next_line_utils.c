/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:21:01 by bluzi             #+#    #+#             */
/*   Updated: 2023/02/08 13:54:03 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = malloc(count * size);
	if (str == NULL)
		return (NULL);
	if ((count > 65535 || size > 65535) && (size_t)-1 / count < size)
		return (NULL);
	while (i < count * size)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}

int	ft_find_nl(const char *s)
{
	int	i;

	i = 0;
	while (s + i && s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < dstsize - 1)
	{
		if (src[i])
			dst[i] = src[i];
		else
			dst[i] = '\0';
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

int	ft_strealloc(char **str, size_t size)
{
	char	*new_str;

	new_str = gnl_calloc(size, sizeof(char));
	if (!new_str)
		return (0);
	if (*str)
	{
		ft_strlcpy(new_str, *str, ft_strlen(*str) + 1);
		free(*str);
	}
	*str = new_str;
	return (0);
}
