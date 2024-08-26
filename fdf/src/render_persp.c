/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_persp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:15:24 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/23 17:22:25 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>
#include <mlx.h>
#include <stdlib.h>

void	draw_line_persp(t_point a, t_point b, t_img *img, t_full *full)
{
	float	z;
	float	alpha;
	t_vec3	v;

	if (a.pos.z > b.pos.z)
		point_swap(&a, &b);
	if (b.pos.z < 0.01)
		return ;
	v = sub(b.pos, a.pos);
	if (a.pos.z < 0.01)
	{
		if (v.z < 0.01)
			return ;
		alpha = (0.01 - a.pos.z) / v.z;
		a.pos = add(a.pos, scale(alpha, v));
	}
	z = a.pos.z;
	a.pos = scale(full->img_plane / a.pos.z, a.pos);
	a.pos.z = z;
	z = b.pos.z;
	b.pos = scale(full->img_plane / b.pos.z, b.pos);
	b.pos.z = z;
	clamp_draw(&a, &b, img, full->line_drawer);
}

void	render_grid_line_persp(t_img *img, t_fuck_norminette ctx_i,
		t_frame camera, t_full *full)
{
	int			j;
	int			i;
	t_point		a;
	t_point		b;
	t_context	*ctx;

	i = ctx_i.row;
	ctx = ctx_i.ctx;
	j = 0;
	while (j < ctx->grid->arr[i]->size)
	{
		a = point_at(ctx, camera, i, j);
		if (j < ctx->grid->arr[i]->size - 1)
		{
			b = point_at(ctx, camera, i, j + 1);
			draw_line_persp(a, b, img, full);
		}
		if (i < ctx->grid->size - 1)
		{
			b = point_at(ctx, camera, i + 1, j);
			draw_line_persp(a, b, img, full);
		}
		j++;
	}
}

t_img	render_persp(void *mlx, t_context ctx, t_frame camera, t_full *full)
{
	t_img	img;
	int		i;

	img = alloc_img(mlx);
	i = 0;
	while (i < ctx.grid->size)
	{
		render_grid_line_persp(&img, (t_fuck_norminette){&ctx, i}, camera,
			full);
		i++;
	}
	free(img.z_buf);
	return (img);
}
