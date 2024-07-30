/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_1.c                                             :+:      :+:    :+:   */
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

t_vi	*vi_init(int n, int value)
{
	t_vi	*res;

	res = malloc(sizeof(t_vi));
	*res = (t_vi){0, 0, 0};
	vi_assign(res, n, value);
	return (res);
}

t_vi	*vi_uninit(int n)
{
	t_vi	*res;

	res = malloc(sizeof(t_vi));
	*res = (t_vi){0, 0, 0};
	vi_resize(res, n);
	return (res);
}

void	vi_free(t_vi *vec)
{
	free(vec->arr);
	free(vec);
}