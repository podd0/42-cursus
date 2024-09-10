/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:30:14 by apuddu            #+#    #+#             */
/*   Updated: 2024/09/10 17:56:29 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <vector.h>

# define WIN_H 1000
# define WIN_W 1000

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

struct							s_vvec
{
	t_vec3						*arr;
	int							size;
	int							buf_size;
};

typedef struct s_vvec			t_vvec;

void							vvec_push_back(t_vvec *vec, t_vec3 elem);
t_vec3							vvec_pop_back(t_vvec *vec);
void							vvec_assign(t_vvec *vec, int n, t_vec3 value);
void							vvec_resize(t_vvec *vec, int n);
t_vvec							*vvec_init(int n, t_vec3 value);
t_vvec							*vvec_uninit(int n);
void							vvec_free(t_vvec *vec);
t_vvec							*vvec_copy(t_vvec *vec);
void							vvec_map(t_vvec *vec, void (*f)(t_vec3));
void							vvec_map_sub(t_vvec *vec, t_vec3 (*f)(t_vec3));
t_vec3							vvec_back(t_vvec *vec);

struct							s_grid
{
	t_vvec						**arr;
	int							size;
	int							buf_size;
};

typedef struct s_grid			t_grid;

void							grid_push_back(t_grid *vec, t_vvec *elem);
t_vvec							*grid_pop_back(t_grid *vec);
void							grid_assign(t_grid *vec, int n, t_vvec *value);
void							grid_resize(t_grid *vec, int n);
t_grid							*grid_init(int n, t_vvec *value);
t_grid							*grid_uninit(int n);
void							grid_free(t_grid *vec);
t_grid							*grid_copy(t_grid *vec);
void							grid_map(t_grid *vec, void (*f)(t_vvec *));
void							grid_map_sub(t_grid *vec,
									t_vvec *(*f)(t_vvec *));
t_vvec							*grid_back(t_grid *vec);
t_vec3							*grid_at(t_grid *grid, int i, int j);

struct							s_parsed_line
{
	t_vvec						*vecs;
	t_vu						*colors;
};
typedef struct s_parsed_line	t_parsed_line;

struct							s_context
{
	t_grid						*grid;
	t_vvu						*colors;
};

typedef struct s_context		t_context;

typedef struct s_img
{
	void						*img;
	char						*addr;
	int							bits_per_pixel;
	int							line_length;
	int							endian;
	float						*z_buf;
}								t_img;

struct							s_point
{
	t_vec3						pos;
	unsigned int				color;
};

typedef struct s_point			t_point;
typedef struct s_full			t_full;

typedef void					(*t_line_drawer)(t_point a, t_point b,
						t_img *img);
typedef t_img					(*t_render)(void *mlx, t_context ctx,
						t_frame camera, t_full *full);

struct							s_controls
{
	int							arrows[4];
	int							zoom;
	int							delta_x;
	int							delta_y;
	int							delta_z;
};

typedef struct s_controls		t_controls;

struct							s_full
{
	t_context					ctx;
	t_img						current;
	t_frame						camera;
	void						*mlx;
	void						*mlx_win;
	float						scale;
	t_render					render;
	t_render					render_inactive;
	t_line_drawer				line_drawer;
	t_line_drawer				line_drawer_inactive;
	float						img_plane;
	t_controls					controls;
};

typedef struct s_fuck_norminette
{
	t_context					*ctx;
	int							row;
}								t_fuck_norminette;

static inline t_vec3	add(const t_vec3 a, const t_vec3 b)
{
	return ((t_vec3){a.x + b.x, a.y + b.y, a.z + b.z});
}

static inline float	dot(const t_vec3 a, const t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

static inline t_vec3	neg(const t_vec3 a)
{
	return ((t_vec3){-a.x, -a.y, -a.z});
}

static inline t_vec3	sub(const t_vec3 a, const t_vec3 b)
{
	return (add(a, neg(b)));
}

static inline t_vec3	scale(float f, const t_vec3 v)
{
	return ((t_vec3){v.x * f, v.y * f, v.z * f});
}

t_vec3							to_frame(t_vec3 p, t_frame fr);
t_vec3							to_world(t_vec3 p, t_frame fr);
float							deg_to_rad(float degrees);
t_frame							rotx(float degrees);
t_frame							roty(float degrees);
t_frame							rotz(float degrees);
t_frame							f_to_world(t_frame f1, t_frame ref);
t_frame							f_to_frame(t_frame f1, t_frame ref);
t_vec3							v_to_frame(t_vec3 p, t_frame fr);
t_vec3							v_to_world(t_vec3 p, t_frame fr);

unsigned int					*vvu_at(t_vvu *vvu, int i, int j);

t_context						parse_file(char *filename);
t_context						parse_file_decenter(char *filename);

int								ft_atoi_advance(char **s);

t_img							alloc_img(void *mlx);
void							pixel_put_no_correction(t_img *img, t_vec3 pt,
									t_vec3 color, float alpha);
void							pixel_put(t_img *img, t_vec3 pt, t_vec3 color,
									float alpha);

t_img							render(void *mlx, t_context ctx, t_frame camera,
									t_full *full);
t_img							render_persp(void *mlx, t_context ctx,
									t_frame camera, t_full *full);

void							clamp_draw(t_point *a, t_point *b, t_img *img,
									t_line_drawer draw);
void							point_swap(t_point *a, t_point *b);
t_vec3							col_to_vec(unsigned int col);
unsigned int					col_from_vec(t_vec3 v);
void							draw_line_aa(t_point a, t_point b, t_img *img);
void							draw_line(t_point a, t_point b, t_img *img);
t_point							point_at(t_context *ctx, t_frame camera, int i,
									int j);

int								handle_key_down(int key, t_full *ctx);
void							set_defaults(t_full *ctx);
void							handle_rotate(int *arrows, t_full *ctx);
void							adjust_z_axis(int key, t_full *ctx);
void							print_menu(t_full *ctx);
int								loop_hook(t_full *ctx);
int								handle_key_up(int key, t_full *ctx);
void							set_movement(int key, t_controls *controls,
									int delta);
void							toggle_antialiasing(t_full *ctx);
void							toggle_perspective(t_full *ctx);
void							move_camera(t_frame *camera,
									t_controls *controls);
t_frame							zoom(t_frame camera, float value);

#endif