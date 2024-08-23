/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vvec_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:42:31 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/14 01:41:23 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include <fdf.h>
#include <stdlib.h>
#include <unistd.h>

t_vvec	*vvec_init(int n, t_vec3 value)
{
	t_vvec	*res;

	res = malloc(sizeof(t_vvec));
	*res = (t_vvec){0, 0, 0};
	vvec_assign(res, n, value);
	return (res);
}

t_vvec	*vvec_uninit(int n)
{
	t_vvec	*res;

	res = malloc(sizeof(t_vvec));
	*res = (t_vvec){0, 0, 0};
	vvec_resize(res, n);
	return (res);
}

void	vvec_free(t_vvec *vec)
{
	free(vec->arr);
	free(vec);
}

t_vvec	*vvec_copy(t_vvec *vec)
{
	t_vvec	*res;

	res = safe_alloc(sizeof(t_vvec));
	res->size = vec->size;
	res->buf_size = vec->buf_size;
	res->arr = safe_alloc(sizeof(t_vec3) * vec->buf_size);
	ft_memmove(res->arr, vec->arr, sizeof(t_vec3) * vec->size);
	return (res);
}

void	vvec_map(t_vvec *vec, void (*f)(t_vec3))
{
	int	i;

	i = 0;
	while (i < vec->size)
	{
		f(vec->arr[i]);
		i++;
	}
}
