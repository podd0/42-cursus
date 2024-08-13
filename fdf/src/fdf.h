#ifndef FRAME_H
# define FRAME_H

struct					s_vec3
{
	float				x;
	float				y;
	float				z;
};

typedef struct s_vec3	t_vec3;

struct					s_frame
{
	t_vec3				x;
	t_vec3				y;
	t_vec3				z;
	t_vec3				o;
};

typedef struct s_frame	t_frame;

struct					s_vvec
{
	t_vec3				*arr;
	int					size;
	int					buf_size;
};

typedef struct s_vvec	t_vvec;

void					vvec_push_back(t_vvec *vec, t_vec3 elem);
t_vec3					vvec_pop_back(t_vvec *vec);
void					vvec_assign(t_vvec *vec, int n, t_vec3 value);
void					vvec_resize(t_vvec *vec, int n);
t_vvec					*vvec_init(int n, t_vec3 value);
t_vvec					*vvec_uninit(int n);
void					vvec_free(t_vvec *vec);
t_vvec					*vvec_copy(t_vvec *vec);
void					vvec_map(t_vvec *vec, void (*f)(t_vec3));
void					vvec_map_sub(t_vvec *vec, t_vec3 (*f)(t_vec3));
t_vec3					vvec_back(t_vvec *vec);

struct					s_grid
{
	t_vvec				**arr;
	int					size;
	int					buf_size;
};

typedef struct s_grid	t_grid;

void					grid_push_back(t_grid *vec, t_vvec *elem);
t_vvec					*grid_pop_back(t_grid *vec);
void					grid_assign(t_grid *vec, int n, t_vvec *value);
void					grid_resize(t_grid *vec, int n);
t_grid					*grid_init(int n, t_vvec *value);
t_grid					*grid_uninit(int n);
void					grid_free(t_grid *vec);
t_grid					*grid_copy(t_grid *vec);
void					grid_map(t_grid *vec, void (*f)(t_vvec *));
void					grid_map_sub(t_grid *vec, t_vvec *(*f)(t_vvec *));
t_vvec					*grid_back(t_grid *vec);

t_vec3	add(const t_vec3 a, const t_vec3 b);
t_vec3	neg(const t_vec3 a);
t_vec3	sub(const t_vec3 a, const t_vec3 b);
float	dot(const t_vec3 a, const t_vec3 b);
t_vec3	scale(float f, const t_vec3 v);
t_vec3	to_frame(t_vec3 p, t_frame fr);
t_vec3	to_world(t_vec3 p, t_frame fr);

#endif