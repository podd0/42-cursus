/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 00:56:15 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/23 16:43:07 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>

static void	translate_scale_row(t_context *parsed, int i, t_vec3 center,
		float scale_factor)
{
	int	j;

	j = 0;
	while (j < parsed->grid->arr[i]->size)
	{
		*grid_at(parsed->grid, i, j) = sub(*grid_at(parsed->grid, i, j),
			center);
		*grid_at(parsed->grid, i, j) = scale(scale_factor,
			*grid_at(parsed->grid, i, j));
		j++;
	}
}

t_context	parse_file(char *filename)
{
	t_context	parsed;
	float		scale_factor;
	int			i;
	t_vec3		center;

	parsed = parse_file_decenter(filename);
	i = parsed.grid->size / 2;
	center = parsed.grid->arr[i]->arr[parsed.grid->arr[i]->size / 2];
	center.z = 0;
	i = 0;
	scale_factor = 500.0 / imax(parsed.grid->size, parsed.grid->arr[0]->size);
	while (i < parsed.grid->size)
	{
		translate_scale_row(&parsed, i, center, scale_factor);
		i++;
	}
	return (parsed);
}
