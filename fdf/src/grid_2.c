/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:42:31 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/13 23:45:41 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include <fdf.h>
#include <stdlib.h>
#include <unistd.h>

t_vvec	*grid_back(t_grid *vec)
{
	return (vec->arr[vec->size - 1]);
}

void	grid_map_sub(t_grid *vec, t_vvec *(*f)(t_vvec *))
{
	int	i;

	i = 0;
	while (i < vec->size)
	{
		vec->arr[i] = f(vec->arr[i]);
		i++;
	}
}
