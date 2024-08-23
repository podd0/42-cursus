/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_aa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:06:43 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/22 14:07:30 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>
#include <math.h>
#include <mlx.h>
#include <stdlib.h>

static inline void	put_pixel_tall_aa(t_img *img, t_vec3 pos, t_vec3 col)
{
	float	alpha;

	pos.y += 1e-4;
	alpha = pos.y - floor(pos.y);
	pixel_put(img, pos, col, alpha);
	pos.y -= 1.0;
	pixel_put(img, pos, col, 1 - (alpha));
}

static inline void	put_pixel_wide_aa(t_img *img, t_vec3 pos, t_vec3 col)
{
	float	alpha;

	pos.x += 1e-4;
	alpha = pos.x - floor(pos.x);
	pixel_put(img, pos, col, alpha);
	pos.x -= 1.0;
	pixel_put(img, pos, col, 1 - alpha);
}

void	draw_vertical_aa(t_point a, t_point b, t_img *img)
{
	t_vec3	mid;
	t_vec3	vec;
	t_vec3	mid_col;
	t_vec3	col_change;

	if (a.pos.y > b.pos.y)
		point_swap(&a, &b);
	vec = sub(b.pos, a.pos);
	col_change = scale(1 / vec.y, sub(col_to_vec(b.color),
				col_to_vec(a.color)));
	vec = scale(1 / vec.y, vec);
	mid = a.pos;
	mid_col = col_to_vec(a.color);
	while (mid.y <= b.pos.y)
	{
		put_pixel_wide_aa(img, mid, mid_col);
		mid = add(mid, vec);
		mid_col = add(mid_col, col_change);
	}
}

void	draw_line_aa(t_point a, t_point b, t_img *img)
{
	t_vec3	mid;
	t_vec3	vec;
	t_vec3	mid_col;
	t_vec3	col_change;

	vec = sub(b.pos, a.pos);
	if (vec.x < fabs(vec.y))
	{
		draw_vertical_aa(a, b, img);
		return ;
	}
	col_change = scale(1 / vec.x, sub(col_to_vec(b.color),
				col_to_vec(a.color)));
	vec = scale(1 / vec.x, vec);
	mid = a.pos;
	mid_col = col_to_vec(a.color);
	while (mid.x <= b.pos.x)
	{
		put_pixel_tall_aa(img, mid, mid_col);
		mid = add(mid, vec);
		mid_col = add(mid_col, col_change);
	}
}
