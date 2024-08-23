/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 01:07:01 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/23 00:58:17 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>
#include <mlx.h>
#include <stdlib.h>

static float	*alloc_z_buf(int size)
{
	float	*res;
	int		i;

	res = malloc(size * sizeof(float));
	i = 0;
	while (i < size)
	{
		res[i] = 1e18;
		i++;
	}
	return (res);
}

t_img	alloc_img(void *mlx)
{
	t_img	img;
	int		i;
	int		j;

	img.img = mlx_new_image(mlx, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	img.z_buf = alloc_z_buf(WIN_H * WIN_W);
	i = 0;
	while (i < WIN_W)
	{
		j = 0;
		while (j < WIN_H)
		{
			pixel_put_no_correction(&img, (t_vec3){i, j, 11e17},
				col_to_vec(0x111111), 1.0);
			j++;
		}
		i++;
	}
	return (img);
}

unsigned int	col_from_vec(t_vec3 v)
{
	return (((int)v.x << 16) | ((int)v.y << 8) | ((int)v.z));
}

void	render_grid_line(t_img *img, t_fuck_norminette ctx_i, t_frame camera,
		t_full *full)
{
	int			j;
	int			i;
	t_point		a;
	t_point		b;
	t_context	*ctx;

	j = 0;
	ctx = ctx_i.ctx;
	i = ctx_i.row;
	while (j < ctx->grid->arr[i]->size)
	{
		a = point_at(ctx, camera, i, j);
		if (j < ctx->grid->arr[i]->size - 1)
		{
			b = point_at(ctx, camera, i, j + 1);
			clamp_draw(&a, &b, img, full->line_drawer);
		}
		a = point_at(ctx, camera, i, j);
		if (i < ctx->grid->size - 1)
		{
			b = point_at(ctx, camera, i + 1, j);
			clamp_draw(&a, &b, img, full->line_drawer);
		}
		j++;
	}
}

t_img	render(void *mlx, t_context ctx, t_frame camera, t_full *full)
{
	t_img	img;
	int		i;
	int		rev;
	int		ind;

	img = alloc_img(mlx);
	i = 0;
	rev = (point_at(&ctx, camera, 0, 0).pos.z > point_at(&ctx, camera,
				ctx.grid->size - 1, 0).pos.z);
	while (i < ctx.grid->size)
	{
		if (rev)
			ind = ctx.grid->size - 1 - i;
		else
			ind = i;
		render_grid_line(&img, (t_fuck_norminette){&ctx, ind}, camera, full);
		i++;
	}
	free(img.z_buf);
	return (img);
}
