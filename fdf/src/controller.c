/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:19:02 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/23 17:22:45 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>

t_frame	zoom(t_frame camera, float value)
{
	camera.x = scale(value, camera.x);
	camera.y = scale(value, camera.y);
	return (camera);
}

void	move_camera(t_frame *camera, int key)
{
	float	scaling;

	scaling = 10 / (dot(camera->y, camera->y));
	if (key == 'w')
		camera->o = sub(camera->o, scale(scaling, camera->y));
	else if (key == 's')
		camera->o = add(camera->o, scale(scaling, camera->y));
	else if (key == 'a')
		camera->o = sub(camera->o, scale(scaling, camera->x));
	else if (key == 'd')
		camera->o = add(camera->o, scale(scaling, camera->x));
}

void	toggle_perspective(t_full *ctx)
{
	t_render	temp;

	temp = ctx->render;
	ctx->render = ctx->render_inactive;
	ctx->render_inactive = temp;
}

void	toggle_antialiasing(t_full *ctx)
{
	t_line_drawer	temp;

	temp = ctx->line_drawer;
	ctx->line_drawer = ctx->line_drawer_inactive;
	ctx->line_drawer_inactive = temp;
}

int	controller(int key, t_full *ctx)
{
	if (key == 65307)
	{
		mlx_loop_end(ctx->mlx);
		return (0);
	}
	if (key >= 65361 && key <= 65364)
		handle_rotate(key - 65361, ctx);
	if (key == 65451 || key == 43)
		ctx->scale *= 1.1;
	if (key == 65453 || key == 45)
		ctx->scale /= 1.1;
	if (key == 'w' || key == 'a' || key == 's' || key == 'd')
		move_camera(&(ctx->camera), key);
	if (key == 'p')
		toggle_perspective(ctx);
	if (key == 'l')
		toggle_antialiasing(ctx);
	if (key == ',' || key == '.')
		adjust_z_axis(key, ctx);
	mlx_destroy_image(ctx->mlx, ctx->current.img);
	ctx->current = (ctx->render)(ctx->mlx, ctx->ctx, zoom(ctx->camera,
				ctx->scale), ctx);
	mlx_put_image_to_window(ctx->mlx, ctx->mlx_win, ctx->current.img, 0, 0);
	print_menu(ctx);
	return (0);
}
