#include <mlx.h>
#include <fdf.h>
#include <math.h>

void	vec_print(t_vec3 v);


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_frame	camera;

	camera.o = (t_vec3){0, 0, 0};

	camera.x = (t_vec3){0.7071067811865476, 0.7071067811865475, 0.0};
	camera.y = (t_vec3){-0.5, 0.5000000000000001, 0.7071067811865475};
	camera.z = (t_vec3){0.4999999999999999, -0.5, 0.7071067811865476};
	camera.o = to_world((t_vec3){0, 0, 10}, camera);
	vec_print(camera.o);
	t_vec3	square[] ={{0, 0, 0},  {1, 0, 0}, {0, 1, 0}, {1, 1, 0}, {1, 0, 1}, {0, 0, 1}, {0, 1, 1}, {1, 1, 1}};

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
	
	for (int i = 0; i < 8; i++)
	{
		t_vec3 pt = to_frame(square[i], camera);
		vec_print(to_frame(square[i], camera));
		for(int dx = 0; dx < 3; dx++)
			for(int dy = 0; dy < 3; dy++)
				mlx_pixel_put(mlx, mlx_win, pt.x*10+500+dx, pt.y*10+500+dy, 0xffffffff);
	}

	// for (int i = 0; i < 100; i++)
	// 	for (int j = 0; j < 100; j++)
	// 		mlx_pixel_put(mlx, mlx_win, i, j, 0xff00aaaa);
	
	mlx_loop(mlx);
}