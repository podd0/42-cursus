/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:40:57 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/13 22:47:20 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include <stdlib.h>
#include <unistd.h>
#include "fdf.h"

void	grid_push_back(t_grid *vec, t_vec3 elem)
{
	int	new_buf_size;
	int	c_size;

	if (vec->size >= vec->buf_size)
	{
		c_size = vec->size;
		new_buf_size = vec->buf_size;
		if (new_buf_size < 16)
			new_buf_size = 16;
		grid_resize(vec, new_buf_size * 2);
		vec->size = c_size;
	}
	vec->arr[vec->size] = elem;
	vec->size++;
}

t_vec3	grid_pop_back(t_grid *vec)
{
	if (vec->size == 0)
	{
		write(2, "Error: pop empty vector\n", 24);
		exit(1);
	}
	vec->size--;
	return (vec->arr[vec->size]);
}

void	grid_assign(t_grid *vec, int n, t_vec3 value)
{
	int	i;

	i = 0;
	vec->size = n;
	vec->buf_size = n;
	free(vec->arr);
	vec->arr = safe_alloc(n * sizeof(t_vec3));
	while (i < n)
	{
		vec->arr[i] = value;
		i++;
	}
}

void	grid_resize(t_grid *vec, int n)
{
	t_grid	old;

	old = *vec;
	vec->size = n;
	vec->buf_size = n;
	vec->arr = safe_alloc(n * sizeof(t_vec3));
	ft_memcpy(vec->arr, old.arr, old.size * sizeof(t_vec3));
	free(old.arr);
}
