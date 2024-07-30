/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vlu_1.c                                            :+:      :+:    :+:   */
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

t_vlu	*vlu_init(int n, long unsigned int value)
{
	t_vlu	*res;

	res = malloc(sizeof(t_vlu));
	*res = (t_vlu){0, 0, 0};
	vlu_assign(res, n, value);
	return (res);
}

t_vlu	*vlu_uninit(int n)
{
	t_vlu	*res;

	res = malloc(sizeof(t_vlu));
	*res = (t_vlu){0, 0, 0};
	vlu_resize(res, n);
	return (res);
}

void	vlu_free(t_vlu *vec)
{
	free(vec->arr);
	free(vec);
}