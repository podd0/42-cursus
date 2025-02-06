/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:58:35 by apuddu            #+#    #+#             */
/*   Updated: 2025/02/06 02:00:45 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <get_next_line.h>
# include <libft.h>
# include <vector.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>

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

// represented by its normal, i.e. the vector that
// is perpendicular to it. Analytically it's:
// plane = {x | x dot normal = normal dot normal}
typedef struct s_plane
{
	t_vec3	normal;
	t_vec3	color;
}	t_plane;

// the axis of the cylinder is the segment ab,
// for each point in this segment the cylinder is made
// of the circle of radius `radius` orthogonal to ab
typedef struct s_cylinder
{
	t_vec3	a;
	t_vec3	b;
	float	radius;
	t_vec3	color;
}	t_cylinder;

# define SPHERE 1
# define PLANE 2
# define CYLINDER 3

typedef union u_shape
{
	t_sphere		*sphere;
	t_plane			*plane;
	t_cylinder		*cylinder;
}	t_shape;

typedef struct s_light
{
	t_vec3	pos;
	t_vec3	color;
}	t_light;

// The scene contains the camera, the ambient color
// and the objects that it contains with the respective types.
// `scene.object->arr[i]` points to an object of type `scene.types->arr[i]`
typedef struct s_scene
{
	t_frame		camera;
	float		fov;
	t_vec3		ambient_color;
	t_vector	*objects;
	t_vi		*types;
	t_vector	*lights;
}	t_scene;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_img	curr;
}	t_mlx;

typedef struct s_ctx
{
	t_scene	*scene;
	t_mlx	*mlx;
}	t_ctx;

t_vec3	add(const t_vec3 a, const t_vec3 b);
float	dot(const t_vec3 a, const t_vec3 b);
t_vec3	cross(const t_vec3 a, const t_vec3 b);
t_vec3	neg(const t_vec3 a);
t_vec3	sub(const t_vec3 a, const t_vec3 b);
t_vec3	scale(float f, const t_vec3 v);
t_vec3	norm(t_vec3 v, float target_len);
float	vec_length(t_vec3 v);

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

t_scene	*parse(char *filename);

#endif