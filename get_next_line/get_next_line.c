/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 00:58:19 by apuddu            #+#    #+#             */
/*   Updated: 2024/04/30 22:09:03 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*consume_head(char *left, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	while (i < len)
	{
		ret[i] = left[i];
		i++;
	}
	while (left[i])
	{
		left[i - len] = left[i];
		i++;
	}
	left[i - len] = '\0';
	return (ret);
}

size_t	ft_strcpy(char *dst, char *src, size_t i)
{
	dst += i;
	while (*src)
	{
		i++;
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (i);
}

char	*append_cum(char *cum, char *left, size_t end_cum, ssize_t b_read)
{
	char	t;
	ssize_t	i;

	i = b_read + 1;
	t = left[b_read + 1];
	left[b_read + 1] = 0;
	ft_strcpy(cum, left, end_cum);
	left[b_read + 1] = t;
	while (left[i])
	{
		left[i - b_read - 1] = left[i];
		i++;
	}
	left[i - b_read - 1] = '\0';
	return (cum);
}

char	*get_line(int fd, char **left)
{
	char	*cum;
	size_t	i;
	size_t	size;
	ssize_t	b_read;

	size = (BUFFER_SIZE) * 2 + 1;
	i = 0;
	cum = malloc(size);
	i = ft_strcpy(cum, *left, i);
	b_read = read(fd, *left, BUFFER_SIZE);
	while (b_read > 0)
	{
		(*left)[b_read] = '\0';
		if (b_read + i + 2 > size)
			cum = double_cum(cum, &size);
		b_read = has_end(*left);
		if (b_read != -1)
			return (append_cum(cum, *left, i, b_read));
		i = ft_strcpy(cum, *left, i);
		assert(i < size);
		b_read = read(fd, *left, BUFFER_SIZE);
	}
	free(*left);
	*left = 0;
	if (cum[0])
		return (cum);
	free(cum);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*left = NULL;
	ssize_t		i;

	if (!left)
	{
		left = malloc(BUFFER_SIZE + 1);
		left[0] = '\0';
	}
	i = has_end(left);
	if (i != -1)
	{
		return (consume_head(left, i + 1));
	}
	return (get_line(fd, &left));
}
