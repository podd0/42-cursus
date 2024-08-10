/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:36:14 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/10 15:20:32 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "vector.h"
#include <stdlib.h>
#include <unistd.h>

static void	sort_3(t_ps *ps)
{
	int		imin;
	int		le;
	t_vi	*vec;

	vec = dq_to_vi(ps->a, 3);
	imin = 0;
	while (vec->arr[imin] > vec->arr[(imin + 1) % 3]
		|| vec->arr[imin] > vec->arr[(imin + 2) % 3])
		imin++;
	le = (vec->arr[0] < vec->arr[1]) + (vec->arr[1] < vec->arr[2])
		+ (vec->arr[2] < vec->arr[0]);
	if (le == 1)
	{
		sa(ps);
		if (imin != 2)
			imin ^= 1;
	}
	if (imin == 2)
		rra(ps);
	else if (imin == 1)
		ra(ps);
	vi_free(vec);
}

static void	merge(t_ps *ps)
{
	int	r;

	r = 3;
	while (r > 0)
	{
		while (ps->b->front && ps->b->front->value > ps->a->back->value)
		{
			pa(ps);
		}
		r--;
		rra(ps);
	}
	while (ps->b->front)
	{
		pa(ps);
	}
}

static void	putstr(char *str)
{
	ft_putendl_fd(str, 1);
}

void	small_sort(t_vi *vec, t_ps *ps)
{
	if (!check_sorted(ps->a, vec->size, 0))
	{
		if (vec->size == 2)
			sa(ps);
		else if (vec->size == 3)
		{
			sort_3(ps);
		}
		else
		{
			pb(ps);
			if (vec->size == 5)
			{
				pb(ps);
				if (ps->b->front->value < ps->b->front->next->value)
					sb(ps);
			}
			sort_3(ps);
			merge(ps);
		}
		vstr_map(ps->moves, putstr);
	}
	ps_free(ps);
	vi_free(vec);
}
