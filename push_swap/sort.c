/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 04:03:39 by apuddu            #+#    #+#             */
/*   Updated: 2024/07/31 17:54:29 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include <stdlib.h>
#include <unistd.h>

void	merge(t_vi *dst, t_vi *src, int l, int w)
{
	int	i;
	int	r;
	int	mid;
	int	r1;

	mid = l + w;
	r = mid + w;
	i = l;
	r1 = mid;
	if (r > dst->size)
		r = dst->size;
	while (i < r)
	{
		if (r1 >= r || (l < mid && src->arr[l] < src->arr[r1]))
		{
			dst->arr[i] = src->arr[l];
			l++;
		}
		else
		{
			dst->arr[i] = src->arr[r1];
			r1++;
		}
		i++;
	}
}

void	swap(t_vi **a, t_vi **b)
{
	t_vi	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	end_sort(t_vi *vec, t_vi *orig_vec, t_vi *temp)
{
	if (orig_vec != vec)
	{
		free(orig_vec->arr);
		*orig_vec = *vec;
		free(vec);
	}
	else
		vi_free(temp);
}

void	merge_sort(t_vi *vec)
{
	t_vi	*temp;
	int		w;
	int		i;
	t_vi	*orig_vec;

	orig_vec = vec;
	temp = vi_uninit(vec->size);
	w = 1;
	while (w < vec->size)
	{
		i = 0;
		while (i < vec->size)
		{
			merge(temp, vec, i, w);
			i += w * 2;
		}
		w *= 2;
		swap(&temp, &vec);
	}
	end_sort(vec, orig_vec, temp);
}
