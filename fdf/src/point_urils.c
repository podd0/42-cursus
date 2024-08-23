/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_urils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 01:38:36 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/20 01:38:48 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	point_swap(t_point *a, t_point *b)
{
	t_point	c;

	c = *a;
	*a = *b;
	*b = c;
}

t_point	point_at(t_context *ctx, t_frame camera, int i, int j)
{
	t_point	a;

	a.pos = to_frame(ctx->grid->arr[i]->arr[j], camera);
	a.color = ctx->colors->arr[i]->arr[j];
	return (a);
}
