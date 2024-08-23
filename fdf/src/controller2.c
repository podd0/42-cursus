/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:22:01 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/23 17:22:45 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>

void	handle_rotate(int key, t_full *ctx)
{
	if (key == 0)
		ctx->camera = f_to_frame(ctx->camera, rotz(1));
	else if (key == 2)
		ctx->camera = f_to_frame(ctx->camera, rotz(-1));
	else if (key == 1)
		ctx->camera = f_to_world(rotx(1), ctx->camera);
	else
		ctx->camera = f_to_world(rotx(-1), ctx->camera);
}

void	adjust_z_axis(int key, t_full *ctx)
{
	if (key == '.')
		ctx->camera.o = add(ctx->camera.o, scale(10 / ctx->scale,
					ctx->camera.z));
	else if (key == ',')
		ctx->camera.o = sub(ctx->camera.o, scale(10 / ctx->scale,
					ctx->camera.z));
}

void	print_menu(t_full *ctx)
{
	mlx_string_put(ctx->mlx, ctx->mlx_win, 0, 40, 0xffffff,
		"Arrow keys: rotate the camera");
	mlx_string_put(ctx->mlx, ctx->mlx_win, 0, 60, 0xffffff,
		"WASD: translate the camera");
	mlx_string_put(ctx->mlx, ctx->mlx_win, 0, 80, 0xffffff, "+, -: zoom level");
	mlx_string_put(ctx->mlx, ctx->mlx_win, 0, 100, 0xffffff,
		"L: toggle anti-aliasing");
	mlx_string_put(ctx->mlx, ctx->mlx_win, 0, 120, 0xffffff,
		"O: switch between orthogonal and perspective");
	mlx_string_put(ctx->mlx, ctx->mlx_win, 0, 140, 0xffffff,
		",.: move along z axis\n");
}
