/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:22:01 by apuddu            #+#    #+#             */
/*   Updated: 2024/09/04 15:51:28 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>

void	handle_rotate(int *arrows, t_full *ctx)
{
	if (arrows[0])
		ctx->camera = f_to_frame(ctx->camera, rotz(1));
	if (arrows[2])
		ctx->camera = f_to_frame(ctx->camera, rotz(-1));
	if (arrows[1])
		ctx->camera = f_to_world(rotx(1), ctx->camera);
	if (arrows[3])
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
		"P: switch between orthogonal and perspective");
	mlx_string_put(ctx->mlx, ctx->mlx_win, 0, 140, 0xffffff,
		",.: move along z axis\n");
}
