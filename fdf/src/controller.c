/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:19:02 by apuddu            #+#    #+#             */
/*   Updated: 2024/09/10 17:58:03 by apuddu           ###   ########.fr       */
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

void	move_camera(t_frame *camera, t_controls *controls)
{
	float	scaling;

	scaling = 10 / (dot(camera->y, camera->y));
	camera->o = add(camera->o, scale(scaling * controls->delta_y, camera->y));
	camera->o = add(camera->o, scale(scaling * controls->delta_x, camera->x));
	camera->o = add(camera->o, scale(scaling * controls->delta_z, camera->z));
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

void	set_movement(int key, t_controls *controls, int delta)
{
	if (key == 'w')
		controls->delta_y += -delta;
	else if (key == 's')
		controls->delta_y += delta;
	else if (key == 'a')
		controls->delta_x += -delta;
	else if (key == 'd')
		controls->delta_x += delta;
	else if (key == ',')
		controls->delta_z += -delta;
	else if (key == '.')
		controls->delta_z += delta;
}
