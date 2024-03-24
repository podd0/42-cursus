/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:22:02 by apuddu            #+#    #+#             */
/*   Updated: 2024/03/23 20:28:52 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count(char *s, char c)
{
	char	*it;
	char	*it2;
	size_t	cnt;

	cnt = 1;
	it = s;
	it2 = ft_strchr(it, c);
	while (it2)
	{
		cnt++;
		it = it2 + 1;
		while (*it == c)
		{
			it++;
		}
		it2 = ft_strchr(it, c);
	}
	return (cnt);
}

char	**populate_split(char *s, char **res, char c)
{
	char	*it;
	char	*it2;
	size_t	i;

	i = 0;
	it = s;
	it2 = ft_strchr(it, c);
	while (it2)
	{
		res[i] = ft_substr(it, 0, it2 - it);
		if (res[i] == NULL)
			return (NULL);
		it = it2 + 1;
		while (*it == c)
		{
			it++;
		}
		it2 = ft_strchr(it, c);
		i++;
	}
	res[i] = ft_strdup(it);
	if (res[i] == NULL)
		return (NULL);
	res[i + 1] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	chset[2];
	char	*trimmed;
	char	**res;
	int		cnt;

	cnt = 0;
	chset[0] = c;
	chset[1] = 0;
	trimmed = ft_strtrim(s, chset);
	if (trimmed == NULL)
		return (NULL);
	if (!trimmed[0])
	{
		free(trimmed);
		return (ft_calloc(1, sizeof(char *)));
	}
	cnt = count(trimmed, c);
	res = malloc((cnt + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	res = (populate_split(trimmed, res, c));
	free(trimmed);
	return (res);
}
