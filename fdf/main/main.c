/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:00:13 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/23 16:16:13 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <get_next_line.h>
#include <math.h>
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

void	set_defaults(t_full *ctx)
{
	ctx->render = render;
	ctx->render_inactive = render_persp;
	ctx->line_drawer = draw_line;
	ctx->line_drawer_inactive = draw_line_aa;
	ctx->scale = 1.0;
	ctx->img_plane = 500.0;
}

int	main(int argc, char **argv)
{
	t_full	full;

	if (argc < 2)
		return (0);
	full.camera = rotz(45);
	full.camera = f_to_world(rotx(135), full.camera);
	full.camera.o = to_world((t_vec3){0, 0, -800}, full.camera);
	full.mlx = mlx_init();
	full.mlx_win = mlx_new_window(full.mlx, 1000, 1000, "fdf");
	full.ctx = parse_file(argv[1]);
	set_defaults(&full);
	full.current = render(full.mlx, full.ctx, full.camera, &full);
	mlx_put_image_to_window(full.mlx, full.mlx_win, full.current.img, 0, 0);
	print_menu(&full);
	mlx_hook(full.mlx_win, 2, 1L << 0, controller, &full);
	mlx_hook(full.mlx_win, 17, 1L << 17, mlx_loop_end, full.mlx);
	mlx_loop(full.mlx);
	mlx_destroy_image(full.mlx, full.current.img);
	mlx_destroy_window(full.mlx, full.mlx_win);
	mlx_destroy_display(full.mlx);
	free(full.mlx);
	grid_map(full.ctx.grid, vvec_free);
	vvu_map(full.ctx.colors, vu_free);
	grid_free(full.ctx.grid);
	vvu_free(full.ctx.colors);
}
