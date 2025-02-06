/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:19:11 by apuddu            #+#    #+#             */
/*   Updated: 2025/02/06 00:47:10 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

// return a ctx, or exit cleanly on error
t_ctx	init(char *filename)
{
	t_ctx	res;

	res.scene = parse(filename);
	res.mlx = NULL;
	if (!res.scene || !res.mlx)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return res;
}
