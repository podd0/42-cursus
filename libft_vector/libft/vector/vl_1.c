/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vl_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:37:53 by apuddu            #+#    #+#             */
/*   Updated: 2024/07/30 01:37:53 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "vector.h"
#include <stdlib.h>
#include <unistd.h>

t_vl	*vl_init(int n, long value)
{
	t_vl	*res;

	res = malloc(sizeof(t_vl));
	*res = (t_vl){0, 0, 0};
	vl_assign(res, n, value);
	return (res);
}

t_vl	*vl_uninit(int n)
{
	t_vl	*res;

	res = malloc(sizeof(t_vl));
	*res = (t_vl){0, 0, 0};
	vl_resize(res, n);
	return (res);
}

void	vl_free(t_vl *vec)
{
	free(vec->arr);
	free(vec);
}