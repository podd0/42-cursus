/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:22:17 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/06 20:23:48 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "vector.h"
#include <stdlib.h>
#include <unistd.h>

int	get_mid(t_deque *ls, int len)
{
	t_vi	*vec;
	int		mid_ind;
	int		l;
	int		r;

	vec = dq_to_vi(ls, len);
	l = 0;
	r = vec->size - 1;
	while (1)
	{
		mid_ind = subdiv(vec, vec->arr[l], l, r);
		if (mid_ind == vec->size / 2)
		{
			mid_ind = vec->arr[mid_ind];
			break ;
		}
		if (mid_ind < vec->size / 2)
		{
			l = mid_ind + 1;
		}
		else
			r = mid_ind - 1;
	}
	vi_free(vec);
	return (mid_ind);
}

void	rrota_n(t_ps *ps, int n)
{
	while (n--)
	{
		rra(ps);
	}
}

void	rrotb_n(t_ps *ps, int n)
{
	while (n--)
	{
		rrb(ps);
	}
}

void	split_a(t_ps *ps, int size, int x, int top)
{
	int	i;
	int	rots;

	rots = 0;
	i = 0;
	while (i < size)
	{
		if (ps->a->front->value < x)
		{
			pb(ps);
			if (LOCAL_SWAP && size < N_LOCAL_SWAP && ps->b->front
				&& ps->b->front->next
				&& ps->b->front->value < ps->b->front->next->value)
				sb(ps);
		}
		else
		{
			rots++;
			ra(ps);
		}
		i++;
	}
	if (top >= 2)
		rrota_n(ps, rots);
}

void	quick_sort_a(t_ps *ps, int size, int top)
{
	int	mid;

	if (check_sorted(ps->a, size, 0))
	{
		return ;
	}
	if (size == 2)
	{
		if (ps->a->front->value > ps->a->front->next->value)
			sa(ps);
		return ;
	}
	mid = get_mid(ps->a, size);
	if (size > 1)
	{
		split_a(ps, size, mid, top);
		quick_sort_a(ps, (size + 1) / 2, top | 1);
		quick_sort_b(ps, size / 2, top + 1);
	}
}
