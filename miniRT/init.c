/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:19:11 by apuddu            #+#    #+#             */
/*   Updated: 2025/02/10 03:52:32 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_img	*init_image(void *mlx)
{
	t_img *img;

	img = malloc(sizeof(t_img));
	img->img = mlx_new_image(mlx, WIN_W, WIN_H);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
		&img->endian);
	return (img);
}

// return a ctx, or exit cleanly on error
t_ctx	init(char *filename)
{
	t_ctx	ctx;

	
	ctx.scene = parse(filename);
	ctx.mlx = mlx_init();
	ctx.mlx_win = mlx_new_window(ctx.mlx, WIN_W, WIN_H, "miniRT");
	ctx.img = init_image(ctx.mlx);
	if (!ctx.scene || !ctx.mlx || !ctx.mlx_win)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (ctx);
}
