/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:58:27 by apuddu            #+#    #+#             */
/*   Updated: 2024/09/10 17:04:01 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>

int	handle_key_down(int key, t_full *ctx)
{
	if (key == 65307)
	{
		mlx_loop_end(ctx->mlx);
		return (0);
	}
	if (key >= 65361 && key <= 65364)
		ctx->controls.arrows[key - 65361] = 1;
	if (key == 65451 || key == 43)
		ctx->controls.zoom++;
	if (key == 65453 || key == 45)
		ctx->controls.zoom--;
	if (key == 'w' || key == 'a' || key == 's' || key == 'd' || key == ','
		|| key == '.')
		set_movement(key, &ctx->controls, 1);
	if (key == 'p')
		toggle_perspective(ctx);
	if (key == 'l')
		toggle_antialiasing(ctx);
	return (0);
}

int	handle_key_up(int key, t_full *ctx)
{
	if (key >= 65361 && key <= 65364)
		ctx->controls.arrows[key - 65361] = 0;
	if (key == 65451 || key == 43)
		ctx->controls.zoom--;
	if (key == 65453 || key == 45)
		ctx->controls.zoom++;
	if (key == 'w' || key == 'a' || key == 's' || key == 'd' || key == ','
		|| key == '.')
		set_movement(key, &ctx->controls, -1);
	return (0);
}

int	loop_hook(t_full *ctx)
{
	void	*old;

	handle_rotate(ctx->controls.arrows, ctx);
	move_camera(&ctx->camera, &ctx->controls);
	if (ctx->controls.zoom == 1)
		ctx->scale *= 1.05;
	if (ctx->controls.zoom == -1)
		ctx->scale *= 1 / 1.05;
	old = ctx->current.img;
	ctx->current = (ctx->render)(ctx->mlx, ctx->ctx, zoom(ctx->camera,
				ctx->scale), ctx);
	mlx_put_image_to_window(ctx->mlx, ctx->mlx_win, ctx->current.img, 0, 0);
	print_menu(ctx);
	mlx_destroy_image(ctx->mlx, old);
	return (0);
}
