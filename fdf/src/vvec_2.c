/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vvec_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:42:31 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/13 23:42:31 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include <stdlib.h>
#include <unistd.h>

t_vec3	vvec_back(t_vvec *vec)
{
	return (vec->arr[vec->size - 1]);
}

void	vvec_map_sub(t_vvec *vec, t_vec3 (*f)(t_vec3))
{
	int	i;

	i = 0;
	while (i < vec->size)
	{
		vec->arr[i] = f(vec->arr[i]);
		i++;
	}
}
