/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:48:12 by apuddu            #+#    #+#             */
/*   Updated: 2024/04/12 16:29:22 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>

char	*double_cum(char *cum, size_t *csize)
{
	char	*res;
	size_t	i;

	res = malloc(*csize * 2 - 1);
	i = 0;
	while (cum[i])
	{
		res[i] = cum[i];
		i++;
	}
	free(cum);
	*csize = *csize * 2 - 1;
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	has_end(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (i);
	return (-1);
}
