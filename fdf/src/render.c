/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:38:42 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/22 14:17:22 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>
#include <math.h>
#include <mlx.h>
#include <stdlib.h>

t_vec3	col_to_vec(unsigned int col)
{
	return ((t_vec3){((col >> 16) & 0xff), ((col >> 8) & 0xff), (col & 0xff)});
}

static t_vec3	interp(t_vec3 a, t_vec3 b, float f)
{
	return (add(scale(1 - f, a), scale(f, b)));
}

void	clamp_draw(t_point *a, t_point *b, t_img *img, t_line_drawer draw)
{
	float	fa;
	float	fb;
	t_vec3	v;

	if (a->pos.x > b->pos.x)
		point_swap(a, b);
	v = sub(b->pos, a->pos);
	fa = fmaxf(0.0, fminf((-WIN_W / 2 - a->pos.x) / v.x, (WIN_W / 2 - a->pos.x)
				/ v.x));
	fa = fmaxf(fa, fminf((-WIN_H / 2 - a->pos.y) / v.y, (WIN_H / 2 - a->pos.y)
				/ v.y));
	fb = fminf(1.0, fmaxf((-WIN_W / 2 - a->pos.x) / v.x, (WIN_W / 2 - a->pos.x)
				/ v.x));
	fb = fminf(fb, fmaxf((-WIN_H / 2 - a->pos.y) / v.y, (WIN_H / 2 - a->pos.y)
				/ v.y));
	a->pos = interp(a->pos, b->pos, fa);
	b->pos = interp(a->pos, b->pos, fb);
	a->color = col_from_vec(interp(col_to_vec(a->color), col_to_vec(b->color),
				fa));
	b->color = col_from_vec(interp(col_to_vec(a->color), col_to_vec(b->color),
				fb));
	draw(*a, *b, img);
}

static inline void	draw_vertical(t_point a, t_point b, t_img *img)
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
		pixel_put(img, mid, mid_col, 1.0);
		mid = add(mid, vec);
		mid_col = add(mid_col, col_change);
	}
}

void	draw_line(t_point a, t_point b, t_img *img)
{
	t_vec3	mid;
	t_vec3	vec;
	t_vec3	mid_col;
	t_vec3	col_change;

	vec = sub(b.pos, a.pos);
	if (fabs(vec.x) < fabs(vec.y))
	{
		draw_vertical(a, b, img);
		return ;
	}
	col_change = scale(1 / vec.x, sub(col_to_vec(b.color),
				col_to_vec(a.color)));
	vec = scale(1 / vec.x, vec);
	mid = a.pos;
	mid_col = col_to_vec(a.color);
	while (mid.x <= b.pos.x)
	{
		pixel_put(img, mid, mid_col, 1.0);
		mid = add(mid, vec);
		mid_col = add(mid_col, col_change);
	}
}
