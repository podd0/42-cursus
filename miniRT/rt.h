/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:58:35 by apuddu            #+#    #+#             */
/*   Updated: 2024/11/03 00:07:43 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <stdio.h>
# include <stdlib.h>
# include <libft.h>
# include <vector.h>
# include <mlx.h>

struct							s_vec3
{
	float						x;
	float						y;
	float						z;
};

typedef struct s_vec3			t_vec3;

struct							s_frame
{
	t_vec3						x;
	t_vec3						y;
	t_vec3						z;
	t_vec3						o;
};

typedef struct s_frame			t_frame;

typedef struct s_img
{
	void						*img;
	char						*addr;
	int							bits_per_pixel;
	int							line_length;
	int							endian;
	float						*z_buf;
}								t_img;

typedef struct s_sphere
{
	t_vec3	center;
	t_vec3	color;
	float	radius;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	normal;
	t_vec3	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	center;
	t_vec3	direction;
	float	radius;
	t_vec3	color;
}	t_plane;


typedef struct s_scene
{
	t_frame	camera;
	float	fov;
	t_vec3	ambient_color;
	
}	t_scene;


t_vec3	add(const t_vec3 a, const t_vec3 b);
float	dot(const t_vec3 a, const t_vec3 b);
t_vec3	neg(const t_vec3 a);
t_vec3	sub(const t_vec3 a, const t_vec3 b);
t_vec3	scale(float f, const t_vec3 v);
t_vec3	to_frame(t_vec3 p, t_frame fr);
t_vec3	to_world(t_vec3 p, t_frame fr);
float	deg_to_rad(float degrees);
t_frame	rotx(float degrees);
t_frame	roty(float degrees);
t_frame	rotz(float degrees);
t_frame	f_to_world(t_frame f1, t_frame ref);
t_frame	f_to_frame(t_frame f1, t_frame ref);
t_vec3	v_to_frame(t_vec3 p, t_frame fr);
t_vec3	v_to_world(t_vec3 p, t_frame fr);

#endif