/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:16:59 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/23 16:44:11 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>
#include <math.h>
#include <mlx.h>
#include <stdlib.h>

t_vec3	pixel_get(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (col_to_vec(*(unsigned int *)dst));
}

void	pixel_put_no_correction(t_img *img, t_vec3 pt, t_vec3 color,
		float alpha)
{
	char	*dst;
	int		x;
	int		y;
	t_vec3	col;

	x = (pt.x + 1e-5);
	y = (pt.y + 1e-5);
	if (x >= WIN_W || y >= WIN_H || x < 0 || y < 0 || pt.z > img->z_buf[x
			* WIN_W + y])
		return ;
	img->z_buf[x * WIN_W + y] = pt.z;
	col = scale(alpha, color);
	col = add(col, scale(1 - alpha, pixel_get(img, x, y)));
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = col_from_vec(col);
}

void	pixel_put(t_img *img, t_vec3 pt, t_vec3 color, float alpha)
{
	pt.x += WIN_W / 2;
	pt.y += WIN_H / 2;
	pixel_put_no_correction(img, pt, color, alpha);
}
