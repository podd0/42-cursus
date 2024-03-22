/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:22:15 by apuddu            #+#    #+#             */
/*   Updated: 2024/03/19 20:23:25 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (0);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (i + 1);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	char	*nulb;

	nulb = ft_memchr(dst, 0, size);
	if (nulb == NULL)
		return (size);
	i = nulb - dst;
	return (i + ft_strlcpy(nulb, src, size - i));
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	while (len)
	{
		dup[len] = s[len];
		--len;
	}
	dup[0] = s[0];
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	max_len;
	char	*res;

	max_len = ft_strlen(s);
	if (start >= max_len)
		return (NULL);
	if (max_len < start + len)
		len = max_len - start;
	res = malloc(len + 1);
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, s + start, len);
	res[len] = 0;
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*res;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc(len);
	if (res == NULL)
		return (NULL);
	i = ft_strlcpy(res, s1, len);
	ft_strlcpy(res + i - 1, s2, len);
	return (res);
}
