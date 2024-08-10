/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:19:25 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/10 17:31:06 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "vector.h"
#include <stdlib.h>
#include <unistd.h>

void	split_b(t_ps *ps, int size, int x, int top)
{
	int	i;
	int	rots;

	rots = 0;
	i = 0;
	while (i < size)
	{
		if (ps->b->front->value >= x)
		{
			pa(ps);
			if (LOCAL_SWAP && size < N_LOCAL_SWAP && ps->a->front
				&& ps->a->front->next
				&& ps->a->front->value > ps->a->front->next->value)
				sa(ps);
		}
		else
		{
			rots++;
			rb(ps);
		}
		i++;
	}
	if (top >= 2)
		rrotb_n(ps, rots);
}

t_deque	*copy_n(t_deque *src, int n)
{
	t_deque	*dq;
	t_node	*it;

	dq = malloc(sizeof(t_deque));
	*dq = (t_deque){NULL, NULL};
	it = src->front;
	while (n--)
	{
		dq_push_back(dq, node_of(it->value));
		it = it->next;
	}
	return (dq);
}

int	ft_abs(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

int	check_sorted(t_deque *dq, int size, int rev)
{
	t_node	*it;

	it = dq->front;
	if (size == 0)
		return (1);
	size--;
	while (size)
	{
		if (!(it->value > it->next->value) != !(rev))
			return (0);
		it = it->next;
		size--;
	}
	return (1);
}

void	quick_sort_b(t_ps *ps, int size, int top)
{
	int	mid;

	if (check_sorted(ps->b, size, 1) || size == 2)
	{
		if (size == 2 && ps->b->front->value < ps->b->front->next->value)
			sb(ps);
		while (size-- > 0)
			pa(ps);
		return ;
	}
	mid = get_mid(ps->b, size);
	if (size > 1)
	{
		split_b(ps, size, mid, top);
		quick_sort_a(ps, (size + 1) / 2, top + 1);
		quick_sort_b(ps, (size) / 2, top);
	}
	else
	{
		while (size)
		{
			pa(ps);
			size--;
		}
	}
}
