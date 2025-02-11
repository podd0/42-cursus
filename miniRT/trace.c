/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:18:20 by apuddu            #+#    #+#             */
/*   Updated: 2025/02/11 21:04:01 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_vec3	calc_direction(int x, int y, float fov, t_frame camera)
{
	float	unit_rot;
	t_vec3	v;

	x -= WIN_W / 2;
	y -= WIN_H / 2;
	unit_rot = fov / WIN_W;
	v = rotx(y * unit_rot).z;
	v = to_world(v, roty(x * unit_rot));
	return (to_world(v, camera));
}

t_vec3	ray_at(float t, t_vec3 direction, t_vec3 origin)
{
	return (add(scale(t, direction), origin));
}

t_vec3	cast_ray(t_vec3 direction, t_scene *scene)
{
	int		i;
	float	t;
	float	mn;
	t_vec3	color;
	t_shape	shape;

	i = 0;
	color = scene->ambient_color;
	mn = INFINITY;
	while (i < scene->objects->size)
	{
		shape = scene->objects->arr[i];
		t = shape.methods->intersect(shape.obj, scene->camera.o, direction);
		if (t < mn && t > 0)
		{
			color = shape.methods->normal(shape.obj, ray_at(t - 1e-6, direction, scene->camera.o));
			if (dot(color, direction) > 0)
				color = neg(color);
			color = norm_color(color);
			color = shape.color;
			mn = t;
		}
		i++;
	}
	return (color);
}

void	trace(t_ctx *ctx)
{
	int		x;
	int		y;
	t_vec3	direction;
	t_vec3	color;

	x = 0;
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			direction = calc_direction(x, y, ctx->scene->fov, ctx->scene->camera);
			color = cast_ray(direction, ctx->scene);
			pixel_put(ctx->img, x, y, color);
			y++;
		}
		x++;
	}
	printf("Done\n");
	mlx_put_image_to_window(ctx->mlx, ctx->mlx_win, ctx->img->img, 0, 0);
}