/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:13:53 by apuddu            #+#    #+#             */
/*   Updated: 2024/11/02 22:13:53 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include <stdlib.h>
#include <unistd.h>

t_vec	*vec_init(int n, void *value)
{
	t_vec	*res;

	res = malloc(sizeof(t_vec));
	*res = (t_vec){0, 0, 0};
	vec_assign(res, n, value);
	return (res);
}

t_vec	*vec_uninit(int n)
{
	t_vec	*res;

	res = malloc(sizeof(t_vec));
	*res = (t_vec){0, 0, 0};
	vec_resize(res, n);
	return (res);
}

void	vec_free(t_vec *vec)
{
	free(vec->arr);
	free(vec);
}

t_vec	*vec_copy(t_vec *vec)
{
	t_vec	*res;

	res = safe_alloc(sizeof(t_vec));
	res->size = vec->size;
	res->buf_size = vec->buf_size;
	res->arr = safe_alloc(sizeof(void *) * vec->buf_size);
	ft_memmove(res->arr, vec->arr, sizeof(void *) * vec->size);
	return (res);
}

void	vec_map(t_vec *vec, void (*f)(void *))
{
	int	i;

	i = 0;
	while (i < vec->size)
	{
		f(vec->arr[i]);
		i++;
	}
}
