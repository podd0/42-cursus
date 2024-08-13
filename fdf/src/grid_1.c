/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:40:57 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/13 22:47:26 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include <stdlib.h>
#include <unistd.h>
#include "fdf.h"

t_grid	*grid_init(int n, t_vec3 value)
{
	t_grid	*res;

	res = malloc(sizeof(t_grid));
	*res = (t_grid){0, 0, 0};
	grid_assign(res, n, value);
	return (res);
}

t_grid	*grid_uninit(int n)
{
	t_grid	*res;

	res = malloc(sizeof(t_grid));
	*res = (t_grid){0, 0, 0};
	grid_resize(res, n);
	return (res);
}

void	grid_free(t_grid *vec)
{
	free(vec->arr);
	free(vec);
}

t_grid	*grid_copy(t_grid *vec)
{
	t_grid	*res;

	res = safe_alloc(sizeof(t_grid));
	res->size = vec->size;
	res->buf_size = vec->buf_size;
	res->arr = safe_alloc(sizeof(t_vec3) * vec->buf_size);
	ft_memmove(res->arr, vec->arr, sizeof(t_vec3) * vec->size);
	return (res);
}

void	grid_map(t_grid *vec, void (*f)(t_vec3))
{
	int	i;

	i = 0;
	while (i < vec->size)
	{
		f(vec->arr[i]);
		i++;
	}
}
