/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:19:11 by apuddu            #+#    #+#             */
/*   Updated: 2024/11/19 15:32:40 by apuddu           ###   ########.fr       */
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
	}
}
