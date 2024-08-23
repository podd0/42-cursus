/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:46:09 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/20 00:42:16 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <vector.h>

t_vec3	*grid_at(t_grid *grid, int i, int j)
{
	return (&(grid->arr[i]->arr[j]));
}

unsigned int	*vvu_at(t_vvu *vvu, int i, int j)
{
	return (&(vvu->arr[i]->arr[j]));
}
